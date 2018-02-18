"""my_team.py

Champlain College CSI-480, Fall 2017
The following code was adapted by Joshua Auerbach (jauerbach@champlain.edu)
from the UC Berkeley Pacman Projects (see license and attribution below).
----------------------------------------------------------


Author: Albert Sebastian, Kevin Blum
Class: CSI-490-01
Assignment: Pacman Capture the Flag Final Project
Date Assigned: 11/21/17
Due Date: 12/13/17 11:59 pm
 
Description:
Pacman Capture the Flag agents
There are three classes
The Reflex Capture Agent initializes all the valuable information for 
each pacman agent, there are two possible agents for the game

The offensive reflex agent takes a set of weights for features and the features
are determined by the game information. The agent essentially works by the score of the game
The agent will search for food if the score is less than 4 in the teams favor and it will
try to get two pieces of food then return to the home side. If the score is four in the favor
of the team then it will act defensively

The defensive reflex agent will essentially only be defenseive and attempt to attack any
pacman that cross onto the home side. If the agent is not chasing a pacman then it will 
stay near the middle of the map and patrol within a range on the middle of the map.
 
Certification of Authenticity: 
I certify that this is entirely my own work, except where I have given 
fully-documented references to the work of others. I understand the definition 
and consequences of plagiarism and acknowledge that the assessor of this 
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
- staff; and/or Communicate a copy of this assignment to a plagiarism checking
- service (which may then retain a copy of this assignment on its database for
- the purpose of future plagiarism checking)

----------------------
Licensing Information:  You are free to use or extend these projects for
educational purposes provided that (1) you do not distribute or publish
solutions, (2) you retain this notice, and (3) you provide clear
attribution to UC Berkeley, including a link to http://ai.berkeley.edu.

Attribution Information: The Pacman AI projects were developed at UC Berkeley.
The core projects and autograders were primarily created by John DeNero
(denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
Student side autograding was added by Brad Miller, Nick Hay, and
Pieter Abbeel (pabbeel@cs.berkeley.edu).
"""

from capture_agents import CaptureAgent
import random
import time
import util
from game import Directions
import game
from util import nearest_point
from tracking import ExactInference
#################
# Team creation #
#################

def create_team(first_index, second_index, is_red,
               first='OffensiveReflexAgent', second='DefensiveReflexAgent'):
    """
    This function should return a list of two agents that will form the
    team, initialized using first_index and second_index as their agent
    index numbers.  is_red is True if the red team is being created, and
    will be False if the blue team is being created.

    As a potentially helpful development aid, this function can take
    additional string-valued keyword arguments ("first" and "second" are
    such arguments in the case of this function), which will come from
    the --red_opts and --blue_opts command-line arguments to capture.py.
    For the nightly contest, however, your team will be created without
    any extra arguments, so you should make sure that the default
    behavior is what you want for the nightly contest.
    """
    inferences = []
    # The following line is an example only; feel free to change it.
    return [eval(first)(first_index, inferences, True), eval(second)(second_index, inferences)]

##########
# Agents #
##########

class ReflexCaptureAgent(CaptureAgent):
    """
    A base class for reflex agents that chooses score-maximizing actions
    """
    def __init__(self, index, inferences, inference_initializer=False):
        self.inferences = inferences
        self.inference_initializer = inference_initializer
        CaptureAgent.__init__(self, index)
    
    def register_initial_state(self, game_state):
        self.start = game_state.get_agent_position(self.index)
        CaptureAgent.register_initial_state(self, game_state)
        #two things which will be useful for future calculations
        self.mid_screen = game_state.data.layout.width/2
        self.legal_positions = [p for p in game_state.get_walls().as_list(False) if p[1] > 1]
        #used for probabilistic tracking
        if self.inference_initializer:
            self.inferences[:] = [ExactInference(opponent, self.distancer, game_state) 
                             for opponent in self.get_opponents(game_state)]
            
    def choose_action(self, game_state):
        """
        Picks among the actions with the highest Q(s,a).
        """
        
        for inference in self.inferences:
            # first elapse the time, then process the current observation
            inference.elapse_time(game_state)
            inference.observe_state(game_state, self.index)

        # comment out the following to not display the belief distributions
        self.display_distributions_over_positions([inference.get_belief_distribution() for inference in self.inferences])
        actions = game_state.get_legal_actions(self.index)

        # You can profile your evaluation time by uncommenting these lines
        # start = time.time()
        
        values = [self.evaluate(game_state, a) for a in actions]
        # print 'eval time for agent %d: %.4f' % (self.index, time.time() - start)

        max_value = max(values)
        best_actions = [a for a, v in zip(actions, values) if v == max_value]

        food_left = len(self.get_food(game_state).as_list())

        if food_left <= 2:
            best_dist = 9999
            for action in actions:
                successor = self.get_successor(game_state, action)
                pos2 = successor.get_agent_position(self.index)
                dist = self.get_maze_distance(self.start, pos2)
                if dist < best_dist:
                    best_action = action
                    best_dist = dist
            return best_action

        return random.choice(best_actions)

    def get_successor(self, game_state, action):
        """
        Finds the next successor which is a grid position (location tuple).
        """
        successor = game_state.generate_successor(self.index, action)
        pos = successor.get_agent_state(self.index).get_position()
        if pos != nearest_point(pos):
            # Only half a grid position was covered
            return successor.generate_successor(self.index, action)
        else:
            return successor

    def evaluate(self, game_state, action):
        """
        Computes a linear combination of features and feature weights
        """
        features = self.get_features(game_state, action)
        weights = self.get_weights(game_state, action)
        return features * weights

    def get_features(self, game_state, action):
        """
        Returns a counter of features for the state
        """
        features = util.Counter()
        successor = self.get_successor(game_state, action)
        features['successor_score'] = self.get_score(successor)
        return features

    def get_weights(self, game_state, action):
        """
        Normally, weights do not depend on the gamestate.  They can be either
        a counter or a dictionary.
        """
        return {'successor_score': 1.0}


class OffensiveReflexAgent(ReflexCaptureAgent):
    """
    Modified version of the basic reflex agent.
    
    Priority is to grab food in small groups and return to the home base for points
    
    avoids ghosts when possible
    
    """

    def get_features(self, game_state, action):
        features = util.Counter()
        successor = self.get_successor(game_state, action)
        food_list = self.get_food(successor).as_list()
        features['successor_score'] = -len(food_list)  # self.get_score(successor)
        
        #calculates how many ghosts are trying to eat you
        enemies = [successor.get_agent_state(i) for i in self.get_opponents(successor)]
        defenders = [a for a in enemies if a.is_pacman != True and a.get_position() != None]
        features['num_defenders'] = len(defenders)
        #distance to defenders (weighted heavily because pacman doesn't want to be eaten)
        if len(defenders) > 0:
            dists = [self.get_maze_distance(successor.get_agent_state(self.index).get_position(), a.get_position()) for a in defenders]
            features['defender_distance'] = min(dists)
        
        
        #avoids getting stuck in 1 deep corners
        if action == Directions.STOP:
            features['stop'] = 1
        rev = Directions.REVERSE[game_state.get_agent_state(self.index).configuration.direction]
        if action == rev:
            features['reverse'] = 1
        # Compute distance to the nearest food (very high priority)            
        if len(food_list) > 0:  # This should always be True,  but better safe than sorry
            my_pos = successor.get_agent_state(self.index).get_position()
            min_distance = min([self.get_maze_distance(my_pos, food) for food in food_list])
            features['distance_to_food'] = min_distance
        """if the offensive pacman is carrying more than the set carry limit, ignore more food and return home to cash in
        Also condition because we were having a different mid point based on which side our team was playing on,
        blue and red's mid_screen were different for some reason. Adapted so both sides could return peleets
        print (game_state.get_agent_state(self.index).num_carrying)
        """
        if self.red:
            if game_state.get_agent_state(self.index).num_carrying > 1:
                #distance to center
                distance_home = min([self.distancer.get_distance(my_pos, (self.mid_screen-1, i))
                                 for i in range(game_state.data.layout.height)
                                 if (self.mid_screen -1, i) in self.legal_positions])
                features['middle'] = distance_home;
                features.pop('distance_to_food', None)
        else:
            if game_state.get_agent_state(self.index).num_carrying > 1:
                #distance to center
                distance_home = min([self.distancer.get_distance(my_pos, (self.mid_screen, i))
                                 for i in range(game_state.data.layout.height)
                                 if (self.mid_screen, i) in self.legal_positions])
                features['middle'] = distance_home;
                features.pop('distance_to_food', None)
        """
        This next portion basically has the offensive agent copy the defensive agent after gaining a sizable lead
        guards one half of the border while the defensive agent patrols the other half.
        """
        
        if self.get_score(game_state) > 3:
            features.pop('distance_to_food', None)
            features.pop('defender_distance', None)
            features.pop('num_defenders', None)
            my_state = successor.get_agent_state(self.index)
            my_pos = my_state.get_position()

             # Computes whether we're on defense (1) or offense (0)
            features['on_defense'] = 1
            if my_state.is_pacman:
                features['on_defense'] = 0
        
        # Computes distance to invaders we can see
            enemies = [successor.get_agent_state(i) for i in self.get_opponents(successor)]
            invaders = [a for a in enemies if a.is_pacman and a.get_position() != None]
            features['num_invaders'] = len(invaders)
            if len(invaders) > 0:
                dists = [self.get_maze_distance(my_pos, a.get_position()) for a in invaders]
                features['invader_distance'] = min(dists)
            #this is to keep the defense agent from roaming randomly around the board when there's nobody to chase
            else:
                features['dist_def_spot'] = min([self.distancer.get_distance(my_pos, (self.mid_screen, i))
                                 for i in range(9,13)
                                 if (self.mid_screen, i) in self.legal_positions])
            if action == Directions.STOP:
                features['stop'] = 1
            rev = Directions.REVERSE[game_state.get_agent_state(self.index).configuration.direction]
            if action == rev:
                features['reverse'] = 1
        
        
        return features
        
        
        #These weights have been tuned to get the desired effect during certain different behaviours.
    def get_weights(self, game_state, action):
        return {'successor_score': 100, 'distance_to_food': -10, 'defender_distance': 30,'num_defenders': 100, 'stop':-1000, 'reverse':-10,'middle': -100000,
                'dist_def_spot': -1,'on_defense': 100,'invader_distance':-1000, 'capsule': -10}


class DefensiveReflexAgent(ReflexCaptureAgent):
    """
    modified defensive reflex agent
    checks for enemies on our side of map, if they exist try and grab closest enemy
    if they don't exist hang out around center stage for good positioning.
    
    """

    def get_features(self, game_state, action):
        features = util.Counter()
        successor = self.get_successor(game_state, action)

        my_state = successor.get_agent_state(self.index)
        my_pos = my_state.get_position()

        # Computes whether we're on defense (1) or offense (0)
        #defense bot should never be on offense
        features['on_defense'] = 1
        if my_state.is_pacman:
            features['on_defense'] = 0
        
        # Computes distance to invaders we can see
        enemies = [successor.get_agent_state(i) for i in self.get_opponents(successor)]
        invaders = [a for a in enemies if a.is_pacman and a.get_position() != None]
        features['num_invaders'] = len(invaders)
        if len(invaders) > 0:
            dists = [self.get_maze_distance(my_pos, a.get_position()) for a in invaders]
            features['invader_distance'] = min(dists)
            #this is to keep the defense agent from roaming randomly around the board when there's nobody to chase
            #patrols middle of map for now
        else:
            features['dist_def_spot'] = min([self.distancer.get_distance(my_pos, (self.mid_screen, i))
                                 for i in range(8,10)
                                 if (self.mid_screen, i) in self.legal_positions])
        if action == Directions.STOP:
            features['stop'] = 1
        rev = Directions.REVERSE[game_state.get_agent_state(self.index).configuration.direction]
        if action == rev:
            features['reverse'] = 1
            #if our team has a lead we move our patrol more southern, since our offensive agent will move north
        if self.get_score(game_state) > 3:
            features['dist_def_spot'] = min([self.distancer.get_distance(my_pos, (self.mid_screen, i))
                                 for i in range(4,6)
                                 if (self.mid_screen, i) in self.legal_positions])    
            
        return features

    def get_weights(self, game_state, action):
        return {'num_invaders': 1000, 'on_defense': 100, 'invader_distance': -10000, 'stop': -100, 'reverse': -2, 'dist_def_spot':-1}


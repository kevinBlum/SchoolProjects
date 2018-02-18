"""multi_agents.py

Author: Kevin Blum
Class: CSI-480-01
Assignment: Multi Agent Pacman
Date Assigned: 10/3/17
Due Date: 10/16/17
 
Description:
This program fills out the functions to for multi agent pacman
autograder questions for a reflex agent, minimax, alpha-beta pruning, 
expectimax, and a better evaluation function
Reflex Agent tallies up a new score based on food and ghost distance
The psuedo code for the alpha-beta pruning was the foundation for
the minimax code just taking out the alpha-beta pruning and furthermore
helped with expectimax because the max value functions all essentially
remain the same, the expected value function is similar but working with a 
list of values for probabilities for values
The better evaluation function improves how it evaluates its relation to food 
essentially so it is passes the tests but is not extensive 
 
Certification of Authenticity: 
I certify that this is entirely my own work, except where I have given 
fully-documented references to the work of others. I understand the definition 
and consequences of plagiarism and acknowledge that the assessor of this 
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
- staff; and/or Communicate a copy of this assignment to a plagiarism checking
- service (which may then retain a copy of this assignment on its database for
- the purpose of future plagiarism checking)

Champlain College CSI-480, Fall 2017
The following code was adapted by Joshua Auerbach (jauerbach@champlain.edu)
from the UC Berkeley Pacman Projects (see license and attribution below).

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
from __future__ import division

from util import manhattan_distance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
      A reflex agent chooses an action at each choice point by examining
      its alternatives via a state evaluation function.

      The code below is provided as a guide.  You are welcome to change
      it in any way you see fit, so long as you don't touch our method
      headers.
    """


    def get_action(self, game_state):
        """
        You do not need to change this method, but you're welcome to.

        get_action chooses among the best options according to the evaluation function.

        Just like in the previous project, get_action takes a GameState and returns
        some Directions.X for some X in the set {North, South, West, East, Stop}
        """
        # Collect legal moves and successor states
        legal_moves = game_state.get_legal_actions()

        # Choose one of the best actions
        scores = [self.evaluation_function(game_state, action) for action in legal_moves]
        best_score = max(scores)
        best_indices = [index for index in range(len(scores)) if scores[index] == best_score]
        chosen_index = random.choice(best_indices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legal_moves[chosen_index]

    def evaluation_function(self, current_game_state, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (new_food) and Pacman position after moving (new_pos).
        new_scared_times holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successor_game_state = current_game_state.generate_pacman_successor(action)
        new_pos = successor_game_state.get_pacman_position()
        new_food = successor_game_state.get_food()

        "*** YOUR CODE HERE ***"
        """
        Variable Definitions for the current food, an alternate score,
        distance to food and ghost and the number of food in the successor state
        """
        current_food = current_game_state.get_food()
        alternate_score = 0
        food_distance = 99999
        ghost_distance = 99999
        food_successor = len(new_food.as_list())

        """
        Finding the closest food and ghost value
        """
        for food in new_food.as_list():
          distance = manhattan_distance(food, new_pos)
          food_distance = min([food_distance, distance])
          
        for ghost in successor_game_state.get_ghost_positions():
          distance = manhattan_distance(new_pos, ghost)
          ghost_distance = min([ghost_distance, distance])
        
        """
        If food is in the current position then add to alternative score
        """
        pos_x, pos_y = new_pos
        if current_food[pos_x][pos_y]:
          alternate_score += 10

        """
        Score is calculated as reciprocal of the distance to closest food minus number of food plus aternate score
        """
        score = 1.0/food_distance - food_successor + alternate_score 

        """
        If a ghost is within 2 spaces then subtract 600 from score, should negate any positive score when ghost is near essentially
        """
        if ghost_distance < 2:
          score -= 600

        return score

def score_evaluation_function(current_game_state):
    """
      This default evaluation function just returns the score of the state.
      The score is the same one displayed in the Pacman GUI.

      This evaluation function is meant for use with adversarial search agents
      (not reflex agents).
    """
    return current_game_state.get_score()

class MultiAgentSearchAgent(Agent):
    """
      This class provides some common elements to all of your
      multi-agent searchers.  Any methods defined here will be available
      to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

      You *do not* need to make any changes here, but you can if you want to
      add functionality to all your adversarial search agents.  Please do not
      remove anything, however.

      Note: this is an abstract class: one that should not be instantiated.  It's
      only partially specified, and designed to be extended.  Agent (game.py)
      is another abstract class.
    """

    def __init__(self, eval_fn = 'score_evaluation_function', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluation_function = util.lookup(eval_fn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 2)
    """

    def get_action(self, game_state):
        """
          Returns the minimax action from the current game_state using self.depth
          and self.evaluation_function.

          Here are some method calls that might be useful when implementing minimax.

          game_state.get_legal_actions(agent_index):
            Returns a list of legal actions for an agent
            agent_index=0 means Pacman, ghosts are >= 1

          game_state.generate_successor(agent_index, action):
            Returns the successor game state after an agent takes an action

          game_state.get_num_agents():
            Returns the total number of agents in the game
        """
        "*** YOUR CODE HERE ***"
        """
        get_action gets the number of agents and then finds the path of actions for minimax
        by calling the max value function which simulates the game in turns of agents and
        finds the maximum and minimum values for states
        """
        self.number_of_agents = game_state.get_num_agents()
        minimax = self.max_value(game_state, 0, 0)
        return minimax[1]
    
    """
    max_value function finds the maximum value at a given state
    value is initialized as a tuple to negative infinity and the direction stop
    for the purpose of the lambda function item lookup
    then for each action in the legal set of actions the value is set to the minimum
    of the values found in the value function giving the value function the successor
    state with the agent index and the action, the next depth mod the number of agents
    and the next depth level and action
    """
    def max_value(self, state, agent_index, current_depth):
        value = (float("-inf"), "Stop")
        for action in state.get_legal_actions(agent_index):
            value = max([value, (self.value(state.generate_successor(agent_index, action), (current_depth + 1) % self.number_of_agents, current_depth + 1), action)], 
                         key=lambda item:item[0])
        return value

    """
    min_value function finds the minimum value at a given state
    value is initialized as a tuple to positive infinity and the direction stop
    for the purpose of the lambda function item lookup
    then for each action in the legal set of actions the value is set to the minimum
    of the values found in the value function giving the value function the successor
    state with the agent index and the action, the next depth mod the number of agents
    and the next depth level and action
    """
    def min_value(self, state, agent_index, current_depth):
        value = (float("inf"), "Stop")
        for action in state.get_legal_actions(agent_index):
            value = min([value, (self.value(state.generate_successor(agent_index, action), (current_depth + 1) % self.number_of_agents, current_depth + 1), action)], 
                         key=lambda item:item[0])
        return value

    """
    value function takes the parameters given from the min_value and max_value
    functions and if the next state is a win or lose state or the next depth is 
    greater or equal to the current depth times the number of agents then return the
    evaluation function of the next state
    if the agent index is zero, pacman, return the value of the max value function 
    else it must be a ghost return the minimum value of the min value function
    """
    def value(self, state, agent_index, next_depth):
        if state.is_lose() or state.is_win() or next_depth >= self.depth * self.number_of_agents:
            return self.evaluation_function(state)
        if (agent_index == 0):
            return self.max_value(state, agent_index, next_depth)[0]  
        else:
            return self.min_value(state, agent_index, next_depth)[0]


class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def get_action(self, game_state):
        """
          Returns the minimax action using self.depth and self.evaluation_function
        """
        "*** YOUR CODE HERE ***"
        """
        get_action gets the number of agents and iniitializes alpha and beta
        to negative and positive infinity respectively then finds the minimax path
        but prunes nodes based on the values of alpha and beta
        """
        self.number_of_agents = game_state.get_num_agents()
        alpha = float("-inf")
        beta  = float("inf")
        alphabeta = self.max_value(game_state, 0, 0, alpha, beta)
        return alphabeta[1]
    
    """
    max_value function finds the maximum value at a given state
    value is initialized as a tuple to negative infinity and the direction stop
    for the purpose of the lambda function item lookup
    then for each action in the legal set of actions the value is set to the minimum
    of the values found in the value function giving the value function the successor
    state with the agent index and the action, the next depth mod the number of agents
    and the next depth level and action
    Then evaluates if the value is greater than the beta value and if so returns value
    else finds the value of alpha by finding the max value of alpha and value
    """    
    def max_value(self ,state, agent_index, current_depth, alpha, beta):
        value = (float("-inf"), "Stop")
        for action in state.get_legal_actions(agent_index):
            value = max([value, (self.value(state.generate_successor(agent_index, action), (current_depth+1) % self.number_of_agents, current_depth + 1, alpha, beta), action)], 
                         key=lambda item:item[0])
            if value[0] > beta:
                return value
            alpha = max(alpha, value[0])
        return value
    
    """
    min_value function finds the minimum value at a given state
    value is initialized as a tuple to positive infinity and the direction stop
    for the purpose of the lambda function item lookup
    then for each action in the legal set of actions the value is set to the minimum
    of the values found in the value function giving the value function the successor
    state with the agent index and the action, the next depth mod the number of agents
    and the next depth level and action
    Then evalutes if the value is less than alpha and if so then return value
    else finds the value of beta as the minimum of beta and value
    """
    def min_value(self, state, agent_index, current_depth, alpha, beta):
        value = (float("inf"), "Stop")
        for action in state.get_legal_actions(agent_index):
            value = min([value, (self.value(state.generate_successor(agent_index, action), (current_depth+1) % self.number_of_agents, current_depth + 1, alpha, beta), action)], 
                         key=lambda item:item[0])
            if value[0] < alpha:
                return value
            beta = min(beta, value[0])
        return value
    
    """
    value function takes the parameters given from the min_value and max_value
    functions and if the next state is a win or lose state or the next depth is 
    greater or equal to the current depth times the number of agents then return the
    evaluation function of the next state
    if the agent index is zero, pacman, return the value of the max value function 
    else it must be a ghost return the minimum value of the min value function
    """
    def value(self, state, agent_index, next_depth, alpha, beta):
        if state.is_lose() or state.is_win() or next_depth >= self.depth * self.number_of_agents:
            return self.evaluation_function(state)
        if (agent_index == 0):
            return self.max_value(state, agent_index, next_depth, alpha, beta)[0]  
        else:
            return self.min_value(state, agent_index, next_depth, alpha, beta)[0]
    

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def get_action(self, game_state):
        """
          Returns the expectimax action using self.depth and self.evaluation_function

          All ghosts should be modeled as choosing uniformly at random from their
          legal moves.
        """
        "*** YOUR CODE HERE ***"
        """
        get_action gets the number of agents and then finds the path of actions for expectimax
        by calling the max value function which simulates the game in turns of agents and
        finds the maximum value and expected value at each state
        """
        self.number_of_agents = game_state.get_num_agents()
        expectimax = self.max_value(game_state, 0, 0)
        return expectimax[1]
    
    """
    max_value function finds the maximum value at a given state
    value is initialized to negative infinity
    then for each action in the legal set of actions the value is set to the minimum
    of the values found in the value function giving the value function the successor
    state with the agent index and the action, the next depth mod the number of agents
    and the next depth level and action
    """    
    def max_value(self ,state, agent_index, current_depth):
        value = float("-inf")
        for action in state.get_legal_actions(agent_index):
            value = max([value, (self.value(state.generate_successor(agent_index, action), (current_depth + 1) % self.number_of_agents, current_depth + 1), action)])
        return value

    """
    expected_value functions finds the expected value at a given state
    value is initialized to a list consisting of the float 0.0
    then for each action in the set of legal actions add to that list the value obtained
    from the value function passing in the parameters the successor
    state with the agent index and the action, the next depth mod the number of agents
    and the next depth level and action
    Returns the sum of all values in the value list divided by the number of values
    """
    def expected_value(self, state, agent_index, current_depth):
        value = [0.0]
        for action in state.get_legal_actions(agent_index):
            value.append(self.value(state.generate_successor(agent_index, action), (current_depth + 1) % self.number_of_agents, current_depth + 1))
        return sum(value)/(len(value)-1)
    
    """
    value function takes the parameters given from the min_value and max_value
    functions and if the next state is a win or lose state or the next depth is 
    greater or equal to the current depth times the number of agents then return the
    evaluation function of the next state
    if the agent index is zero, pacman, return the value of the max value function 
    else it must be a ghost return the value of the expected value function
    """
    def value(self, state, agent_index, next_depth):
        if state.is_lose() or state.is_win() or next_depth >= self.depth * self.number_of_agents:
            return self.evaluation_function(state)
        if (agent_index == 0):
            return self.max_value(state, agent_index, next_depth)[0]  
        else:
            return self.expected_value(state, agent_index, next_depth)
        

def better_evaluation_function(current_game_state):
    """
      Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
      evaluation function (question 5).

      DESCRIPTION: 
          This evaluation function works by manipulating the values of the 
          distances to the food pellets and basically evaluates the score
          of based on how close pacman is to food pellets and the number of 
          pellets left. 
          This evaluation function works for the tests and passes them
          but it certainly does not do a good job of evaluating all possible variables
          because it does not take into account ghosts and pellets and whether ghosts are
          scared and so on. So in other circumstances I do not think this evaluation function
          will perform well but it does perform well enough in this small classic test against
          one ghost
    """
    "*** YOUR CODE HERE ***"
    """
    Variable definitions of all valuable pieces of information
    Current pacman position and food
    List for the distances to food
    """
    current_pos = current_game_state.get_pacman_position()
    current_food = current_game_state.get_food()
    old_score = current_game_state.get_score()
    food_distance = []
    
    score = 0
    
    """
    List of all manhattan distances to food
    """
    for food in current_food.as_list():
        food_distance.append(manhattan_distance(food, current_pos))

    """
    Current food state is 50 times the number of food
    Value for the maximum distance to a food in food distance list
    Value for the minimum distance to a food in food distance list
    """
    current_food_state = 50*len(current_food.as_list())
    max_food_dist = max(food_distance + [0.0]) 
    min_food_dist = min(food_distance + [1000.0])

    """
    Score calculate by taking the value from the function of get score of current game state
    then subtracting the maximum and minimum food distance then adding the reciprocal of the
    sum of all food distances. Then subtract the current number of food times 50 and add the
    reciprocal of the minimum value in the food distance list
    """
    score = (old_score - max_food_dist - min_food_dist + 1.0/sum(food_distance+[0.001]) - current_food_state + 1.0/min([food_distance, float("inf")]))

    return score

# Abbreviation
better = better_evaluation_function
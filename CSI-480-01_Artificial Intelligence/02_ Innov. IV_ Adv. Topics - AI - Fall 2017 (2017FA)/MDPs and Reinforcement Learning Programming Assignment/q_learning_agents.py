"""q_learning_agents.py

Author: Kevin Blum
Class: CSI-480-01
Assignment: Reinforcement Learning
Date Assigned: 10/17/19
Due Date: 11/1/17 11:59pm
 
Description:
The solutions to problems 4, 5, and 7

Implements the necessary functions for the Q-Learning Agent to satisfy the questions
makes use of the given utility functions to accomplish this

The apporximate q-learning functions are not implemented

 
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

from game import *
from learning_agents import ReinforcementAgent
from feature_extractors import *

import random
import util
import math


class QLearningAgent(ReinforcementAgent):
    """
      Q-Learning Agent

      Functions you should fill in:
        - compute_value_from_q_values
        - compute_action_from_q_values
        - get_q_value
        - get_action
        - update

      Instance variables you have access to
        - self.epsilon (exploration prob)
        - self.alpha (learning rate)
        - self.discount (discount rate)

      Functions you should use
        - self.get_legal_actions(state)
          which returns legal actions for a state
    """

    def __init__(self, **args):
        "You can initialize Q-values here..."
        ReinforcementAgent.__init__(self, **args)

        "*** YOUR CODE HERE ***"
        """
        Set self.q_values to the special tuple Counter()
        """
        self.q_values = util.Counter()

    def get_q_value(self, state, action):
        """
          Returns Q(state,action)
          Should return 0.0 if we have never seen a state
          or the Q node value otherwise
        """
        "*** YOUR CODE HERE ***"
        """
        return the value of the q node for a given state and action
        """
        return self.q_values[(state, action)]

    def compute_value_from_q_values(self, state):
        """
          Returns max_action Q(state,action)
          where the max is over legal actions.  Note that if
          there are no legal actions, which is the case at the
          terminal state, you should return a value of 0.0.
        """
        "*** YOUR CODE HERE ***"
        """
        List comprehension for setting q_values for each action in the set of legal actions
        for a given state.
        If there are no legal actions then return zero, otherwise return the max q_value 
        """
        q_values = [self.get_q_value(state, action) for action in self.get_legal_actions(state)]
        if len(q_values) == 0:
            return 0.0
        return max(q_values)

    def compute_action_from_q_values(self, state):
        """
          Compute the best action to take in a state.  Note that if there
          are no legal actions, which is the case at the terminal state,
          you should return None.
        """
        "*** YOUR CODE HERE ***"
        """
        If there are no legal actions then return none
        set q_value to low value
        """
        legal_actions = self.get_legal_actions(state)
        if len(legal_actions) == 0:
            return None
        q_value = float("-inf")
        
        """
        then for each legal action find the q_value of that
        legal action, if the q_value of that legal action is better than current q_value
        set the action to the legal action that is better and the q_value to the better 
        q_value of the better legal action
        """
        for new_action in legal_actions:
            q_value_new = self.get_q_value(state, new_action)
            if q_value_new > q_value:
                action = new_action
                q_value = q_value_new
        return action


    def get_action(self, state):
        """
          Compute the action to take in the current state.  With
          probability self.epsilon, we should take a random action and
          take the best policy action otherwise.  Note that if there are
          no legal actions, which is the case at the terminal state, you
          should choose None as the action.

          HINT: You might want to use util.flip_coin(prob)
          HINT: To pick randomly from a list, use random.choice(list)
        """
        # Pick Action
        legal_actions = self.get_legal_actions(state)
        action = None
        "*** YOUR CODE HERE ***"
        """
        if there are no legal actions then return action, which is set to none
        Use the utlity function to flip a coin and choose to return a random action
        or use the current policy for the next action based on the return value from
        the flip_coin function
        """
        if len(legal_actions) == 0:
          return action

        if util.flip_coin(self.epsilon):
          return random.choice(legal_actions)
        else:
          return self.get_policy(state)

    def update(self, state, action, next_state, reward):
        """
          The parent class calls this to observe a
          state = action => next_state and reward transition.
          You should do your Q-Value update here

          NOTE: You should never call this function,
          it will be called on your behalf
        """
        "*** YOUR CODE HERE ***"
        """
        calculate the first part of the update equation, multiply 1 - alpha and the q_value
        set q_value as list with list comprehension to get the q_values for each next action and state in the set of legal actions
        if there are no legal actions then set the sample value as the reward otherwise the sample is the reward plus
        the discount, gamma, times the max q_value
        then calculate the second part of the equation which is just alpha multiplied by the sample
        then set the q_value at the given state and action as the full equation
        """
        equation_part1 = (1 - self.alpha) * self.get_q_value(state, action)
        q_value = [self.get_q_value(next_state, next_action) for next_action in self.get_legal_actions(next_state)]
        
        if len(self.get_legal_actions(next_state)) == 0:
            sample = reward
        else:
            sample = reward + (self.discount * max(q_value))
            
        equation_part2 = self.alpha * sample
        full_equation = equation_part1 + equation_part2
        self.q_values[(state, action)] = full_equation

    def get_policy(self, state):
        return self.compute_action_from_q_values(state)

    def get_value(self, state):
        return self.compute_value_from_q_values(state)


class PacmanQAgent(QLearningAgent):
    "Exactly the same as QLearningAgent, but with different default parameters"

    def __init__(self, epsilon=0.05, gamma=0.8, alpha=0.2, num_training=0, **args):
        """
        These default parameters can be changed from the pacman.py command line.
        For example, to change the exploration rate, try:
            python pacman.py -p PacmanQLearningAgent -a epsilon=0.1

        alpha    - learning rate
        epsilon  - exploration rate
        gamma    - discount factor
        num_training - number of training episodes, i.e. no learning after these many episodes
        """
        args['epsilon'] = epsilon
        args['gamma'] = gamma
        args['alpha'] = alpha
        args['num_training'] = num_training
        self.index = 0  # This is always Pacman
        QLearningAgent.__init__(self, **args)

    def get_action(self, state):
        """
        Simply calls the get_action method of QLearningAgent and then
        informs parent of action for Pacman.  Do not change or remove this
        method.
        """
        action = QLearningAgent.get_action(self, state)
        self.do_action(state, action)
        return action


class ApproximateQAgent(PacmanQAgent):
    """
       ApproximateQLearningAgent

       You should only have to overwrite get_q_value
       and update.  All other QLearningAgent functions
       should work as is.
    """

    def __init__(self, extractor='IdentityExtractor', **args):
        self.feat_extractor = util.lookup(extractor, globals())()
        PacmanQAgent.__init__(self, **args)
        self.weights = util.Counter()

    def get_weights(self):
        return self.weights

    def get_q_value(self, state, action):
        """
          Should return Q(state,action) = w * feature_vector
          where * is the dot_product operator
        """
        "*** YOUR CODE HERE ***"
        util.raise_not_defined()

    def update(self, state, action, next_state, reward):
        """
           Should update your weights based on transition
        """
        "*** YOUR CODE HERE ***"
        features = self.feat_extractor.get_features(state, action)
        difference = reward + self.discount * self.get_value(next_state) - self.get_q_value(state, action)
        for feature in features:
            self.weights[feature] += self.alpha * difference * features[feature]

    def final(self, state):
        "Called at the end of each game."
        # call the super-class final method
        PacmanQAgent.final(self, state)

        # did we finish training?
        if self.episodes_so_far == self.num_training:
            # you might want to print your weights here for debugging
            "*** YOUR CODE HERE ***"
            pass

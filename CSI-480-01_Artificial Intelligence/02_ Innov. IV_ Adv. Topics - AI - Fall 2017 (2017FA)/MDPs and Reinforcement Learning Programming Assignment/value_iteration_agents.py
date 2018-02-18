"""value_iteration_agents.py

Author: Kevin Blum
Class: CSI-480-01
Assignment: Reinforcement Learning
Date Assigned: 10/17/19
Due Date: 11/1/17 11:59pm
 
Description:
The solution to problem 1

Implemented functions for value iteration agents

 
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

import mdp
import util

from learning_agents import ValueEstimationAgent


class ValueIterationAgent(ValueEstimationAgent):
    """
        * Please read learning_agents.py before reading this.*

        A ValueIterationAgent takes a Markov decision process
        (see mdp.py) on initialization and runs value iteration
        for a given number of iterations using the supplied
        discount factor.
    """

    def __init__(self, mdp, discount=0.9, iterations=100):
        """
          Your value iteration agent should take an mdp on
          construction, run the indicated number of iterations
          and then act according to the resulting policy.

          Some useful mdp methods you will use:
              mdp.get_states()
              mdp.get_possible_actions(state)
              mdp.get_transition_states_and_probs(state, action)
              mdp.get_reward(state, action, next_state)
              mdp.is_terminal(state)
        """
        self.mdp = mdp
        self.discount = discount
        self.iterations = iterations
        self.values = util.Counter()  # A Counter is a dict with default 0

        # Write value iteration code here
        "*** YOUR CODE HERE ***"
        """
        nested for loops that act over 100 iterations
        set value as values from self
        """
        for iteration in range(iterations):
            value = self.values.copy()
            """
            for each mdp state set the action value as the special tuple Counter()
            """
            for state in mdp.get_states():
                action_values = util.Counter()
                """
                for each action in the mdp's possible actions for a given state do the next for loop
                and then afterwards set the value of the current state to the max value action
                """
                for action in mdp.get_possible_actions(state):
                    """
                    for each transition state and probability in the mdp's transition states and 
                    probabilities for the given state and action then
                    set the value of the action as itself plus the probability multiplied by the mdp reward
                    for the given state, action, and transition state plus the discounted value of the transition state
                    """
                    for transition_state, probability in mdp.get_transition_states_and_probs(state, action):
                        action_values[action] += probability * (mdp.get_reward( state, action, transition_state) + discount * value[transition_state])
                self.values[state] = action_values[action_values.arg_max()]

    def get_value(self, state):
        """
          Return the value of the state (computed in __init__).
        """
        return self.values[state]

    def compute_q_value_from_values(self, state, action):
        """
          Compute the Q-value of action in state from the
          value function stored in self.values.
        """
        "*** YOUR CODE HERE ***"
        """
        set value to zero
        for each transition state and probability from the mdp list of 
        transition states nad probabilities for the given state and action then
        add to the value itself plus the probability times the mdp reward plus
        the discount value from the transition state
        """
        value = 0
        transition = self.mdp.get_transition_states_and_probs(state,action)
        for transition_state, probability in transition:
            value += probability * (self.mdp.get_reward(state, action, transition_state) + (self.discount * self.values[transition_state]))
        return value

    def compute_action_from_values(self, state):
        """
          The policy is the best action in the given state
          according to the values currently stored in self.values.

          You may break ties any way you see fit.  Note that if
          there are no legal actions, which is the case at the
          terminal state, you should return None.
        """
        "*** YOUR CODE HERE ***"
        """
        return none if in terminal state
        initiate policy and value
        for each action in the set of possible actions from mdp
        assign a new value from the function to compute the value given
        the state and action then if the new value is greater than or equal to
        the current value then set the value to the new better value and set the
        policy to the action that correlates to the better value
        """
        if self.mdp.is_terminal(state):
            return None
        
        policy, value = float("-inf"), None
        for action in self.mdp.get_possible_actions(state):
            value_new = self.compute_q_value_from_values(state, action)
            if value_new >= value:
                value = value_new
                policy = action
        return policy

    def get_policy(self, state):
        return self.compute_action_from_values(state)

    def get_action(self, state):
        "Returns the policy at the state (no exploration)."
        return self.compute_action_from_values(state)

    def get_q_value(self, state, action):
        return self.compute_q_value_from_values(state, action)

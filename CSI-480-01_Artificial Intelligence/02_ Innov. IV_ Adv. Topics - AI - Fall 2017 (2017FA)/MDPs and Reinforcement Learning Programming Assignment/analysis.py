"""analysis.py

Author: Kevin Blum
Class: CSI-480-01
Assignment: Reinforcement Learning
Date Assigned: 10/17/19
Due Date: 11/1/17 11:59pm
 
Description:
The solutions to problems 2, 3, and 6

Implemented viable values to pass the tests of these questions

 
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

######################
# ANALYSIS QUESTIONS #
######################

# Set the given parameters to obtain the specified policies through
# value iteration.

def question2():
    answer_discount = 0.9
    answer_noise = 0.01
    return answer_discount, answer_noise


def question3a():
    answer_discount = 1
    answer_noise = 0.2
    answer_living_reward = -3
    return answer_discount, answer_noise, answer_living_reward

    # If not possible, return 'NOT POSSIBLE'

def question3b():
    answer_discount = 0.1
    answer_noise = 0.1
    answer_living_reward = -2
    return answer_discount, answer_noise, answer_living_reward

    # If not possible, return 'NOT POSSIBLE'

def question3c():
    answer_discount = 0.9
    answer_noise = 0.001
    answer_living_reward = 0.0
    return answer_discount, answer_noise, answer_living_reward

    # If not possible, return 'NOT POSSIBLE'

def question3d():
    answer_discount = 0.9
    answer_noise = 0.1
    answer_living_reward = -0.2
    return answer_discount, answer_noise, answer_living_reward

    # If not possible, return 'NOT POSSIBLE'

def question3e():
    answer_discount = 0.0
    answer_noise = 0.1
    answer_living_reward = -2
    return answer_discount, answer_noise, answer_living_reward

    # If not possible, return 'NOT POSSIBLE'

def question6():
    answer_epsilon = 1
    answer_learning_rate = 0.5
    return 'NOT POSSIBLE'
    # If not possible, return 'NOT POSSIBLE'

if __name__ == '__main__':
    print 'Answers to analysis questions:'
    import analysis
    for q in [q for q in dir(analysis) if q.startswith('question')]:
        response = getattr(analysis, q)()
        print '  Question %s:\t%s' % (q, str(response))

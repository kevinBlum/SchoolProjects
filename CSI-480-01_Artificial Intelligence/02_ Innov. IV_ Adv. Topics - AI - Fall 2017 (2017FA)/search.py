"""search.py

Author: Kevin Blum
Class: CSI-480-01
Assignment: Search Assignment
Date Assigned: 9/12/17
Due Date: 9/28/17 11:59pm
 
Description:

search.py solves the problems for 1,2,3,4
It implements the algorithms of the different search functions for
depth_first_search
breadth_first_search
uniform_cost_search
astar_search
All essentially using the same basic algorithm structure with different data
structures to represent the fringe and minor changes based on the need for cost
and heuristic of the algorithm
 
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

"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in search_agents.py).
"""

import util


class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def get_start_state(self):
        """
        Returns the start state for the search problem.
        """
        util.raise_not_defined()

    def is_goal_state(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raise_not_defined()

    def get_successors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, step_cost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'step_cost' is
        the incremental cost of expanding to that successor.
        """
        util.raise_not_defined()

    def get_cost_of_actions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raise_not_defined()


def tiny_maze_search(problem):
    """
    Returns a sequence of moves that solves tiny_maze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tiny_maze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]


def depth_first_search(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:
    
    
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    e = Directions.EAST
    n = Directions.WEST
    """
    """
    start is the start state from problem, exploredState is an array of the states being explored
    fringe is stack in depth first search, fringe adds the tuple of the start state and an array
    """
    start = problem.get_start_state()
    exploredState = []
    exploredState.append(start)
    fringe = util.Stack()
    fringeTuple = (start, [])
    fringe.push(fringeTuple)
    """
    Main Loop checks if fringe is not empty then checks if goal state, if goal state then actions
    are returned otherwise get the successors of the current state then check if the coordinates are
    within the exploredState and then add the coordinates to the exploredState array and add the actions
    to get to that coordinate state
    """
    while not fringe.is_empty():
        state, actions = fringe.pop()
        if problem.is_goal_state(state):
            return actions
        exploredState.append(state)
        successor = problem.get_successors(state)
        for i in successor:
            coordinates = i[0]
            if not coordinates in exploredState:
                direction = i[1]
                fringe.push((coordinates, actions + [direction]))
    return actions
    
    


def breadth_first_search(problem):
    """Search the shallowest nodes in the search tree first."""
    """
    start is the start state from problem, exploredState is an array of the state being explored
    fringe is queue in breadth first search, fringe adds the tuple of the start state and an array
    """
    start = problem.get_start_state()
    exploredState = []
    exploredState.append(start)
    fringe = util.Queue()
    fringeTuple = (start, [])
    fringe.push(fringeTuple)
    """
    Main Loop checks if fringe is not empty then checks if goal state, if goal state then actions
    are returned otherwise get the successors of the current state then check if the coordinates are
    within the exploredState and then add the coordinates to the exploredState array and add the actions
    to get to that coordinate state
    """
    while not fringe.is_empty():
        state, actions = fringe.pop()
        if problem.is_goal_state(state):
            return actions
        successor = problem.get_successors(state)
        for i in successor:
            coordinates = i[0]
            if not coordinates in exploredState:
                direction = i[1]
                exploredState.append(coordinates)
                fringe.push((coordinates, actions + [direction]))
    return actions


def uniform_cost_search(problem):
    """Search the node of least total cost first."""
    """
    start is the start state from problem, exploredState is an array of the state being explored
    fringe is priority queue in uniform cost search, fringe adds the tuple of the start state and an array, and cost value
    """
    start = problem.get_start_state()
    exploredState = []
    fringe = util.PriorityQueue()
    fringeTuple = (start, [])
    fringe.push(fringeTuple, 0)
    cost = 0
    """
    Main Loop checks if fringe is not empty then checks if goal state, if goal state then actions
    are returned otherwise get the successors of the current state then check if the coordinates are
    within the exploredState and then add the coordinates to the exploredState array and add the actions
    to get to that coordinate state, also adds the cost of actions but each action is one in pacman
    """
    while not fringe.is_empty():
        state, actions = fringe.pop()
        if problem.is_goal_state(state):
            return actions
        if state not in exploredState:
            successors = problem.get_successors(state)
            for successor in successors:
                coordinates = successor[0]
                if coordinates not in exploredState:
                    directions = successor[1]
                    cost = actions + [directions]
                    fringe.push((coordinates, actions + [directions]), problem.get_cost_of_actions(cost))
        exploredState.append(state)
    return actions


def null_heuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0


def a_star_search(problem, heuristic=null_heuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    """
    start is the start state from problem, exploredState is an array of the state being explored
    fringe is priority queue in uniform cost search, fringe adds the tuple of the start state and an array, and
    the heuristic from null_heuristic
    """
    start = problem.get_start_state()
    exploredState = []
    fringe = util.PriorityQueue()
    fringeTuple = (start, [])
    fringe.push(fringeTuple, null_heuristic(start, problem))
    astarCost = 0
    """
    Main Loop checks if fringe is not empty then checks if goal state, if goal state then actions
    are returned otherwise get the successors of the current state then check if the coordinates are
    within the exploredState and then add the coordinates to the exploredState array and add the actions
    to get to that coordinate state, also adds the heuristic but it is using null heuristic
    """
    while not fringe.is_empty():
        state, actions = fringe.pop()
        if problem.is_goal_state(state):
            return actions
        if state not in exploredState:
            successors = problem.get_successors(state)
            for successor in successors:
                coordinates = successor[0]
                if coordinates not in exploredState:
                    directions = successor[1]
                    astarActions = actions + [directions]
                    astarCost = problem.get_cost_of_actions(astarActions) + heuristic(coordinates, problem)
                    fringe.push((coordinates, actions + [directions]), astarCost)
        exploredState.append(state)
    return actions

# Abbreviations
bfs = breadth_first_search
dfs = depth_first_search
astar = a_star_search
ucs = uniform_cost_search

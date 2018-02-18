"""perceptron_pacman.py

Author:              Albert Sebastian & Kevin Blum
Class:               CSI-490-01
Assignment:          Supervised Learning
Date Assigned:       11/12/17
Due Date:            11:59 pm 11/27/17
 
Description:
The code for question six, fills out the train function
 
Certification of Authenticity:    
I certify that this is entirely my own work, except where I have been provided
code by the instructor, or given fully-documented references to the work of 
others. I understand the definition and consequences of plagiarism and 
acknowledge that the assessor of this assignment may, for the purpose of 
assessing this assignment:
    Reproduce this assignment and provide a copy to another member of academic
    staff; and/or Communicate a copy of this assignment to a plagiarism checking
    service (which may then retain a copy of this assignment on its database for 
    the purpose of future plagiarism checking)

This code has been adapted from that provided by Prof. Joshua Auerbach:

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

Perceptron implementation for apprenticeship learning

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



import util
from perceptron import PerceptronClassifier
from pacman import GameState

PRINT = True


class PerceptronClassifierPacman(PerceptronClassifier):
    def __init__(self, legal_labels, max_iterations):
        PerceptronClassifier.__init__(self, legal_labels, max_iterations)
        self.weights = util.Counter()

    def classify(self, data ):
        """
        Data contains a list of (datum, legal moves)
        
        Datum is a Counter representing the features of each GameState.
        legal_moves is a list of legal moves for that GameState.
        """
        guesses = []
        for datum, legal_moves in data:
            vectors = util.Counter()
            for l in legal_moves:
                vectors[l] = self.weights * datum[l]
            guesses.append(vectors.arg_max())
        return guesses


    def train( self, training_data, training_labels, validation_data, validation_labels ):
        self.features = list(training_data[0][0]['Stop'].keys()) # could be useful later
        # DO NOT ZERO OUT YOUR WEIGHTS BEFORE STARTING TRAINING, OR
        # THE AUTOGRADER WILL LIKELY DEDUCT POINTS.

        """
        main loop for each iteration in all iterations
        for each datum, legal moves and labels in the training data and
        training labels create a vector and for each move in the 
        legal set of moves set the vector value at move equal to the
        datum value at move multiplied by the weight vector
        
        classify as the arg max in the vector and if the 
        classification is not the label then add the datum at the label
        to the weights and subtract the datum at the classifcation from the weights
        """
        for iteration in range(self.max_iterations):
            print("Starting iteration ", iteration, "...")
            for (datum, legal_moves), label in zip(training_data, training_labels):
                "*** YOUR CODE HERE ***"
                vector = util.Counter()
                for move in legal_moves:
                    vector[move] = datum[move] * self.weights
                classification = vector.arg_max()
                if classification != label:
                    self.weights += datum[label]
                    self.weights -= datum[classification]
                
                

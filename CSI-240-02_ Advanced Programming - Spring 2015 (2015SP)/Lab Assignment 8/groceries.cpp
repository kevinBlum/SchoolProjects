/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Lab
Date Assigned : 4/2/15
Due Date : 4/6/15
Description : The purpose of the program is to provide an example of polymorphism using a grocery shopping basket and 3 classes of inheritance. The proper constructors and get description
functions are called based on the variable types and stored as grocery object pointers in a vector.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#include "groceries.h"

//default constructor for fruit
Fruit::Fruit(){

   name = "";

}

//alternate constructor for fruit
Fruit::Fruit(string input){

   name = input;

}

//default constructor for pineapple
Pineapple::Pineapple(){

   count = 0;

}

//alternate constructor for pineapple
Pineapple::Pineapple(string input, int number){

   name = input;
   count = number;

}

//virtual function to get description for fruit
void Fruit::getDescription(){

   cout << name << endl;

}

//virtual function to get description for pineapple
void Pineapple::getDescription(){

   cout << name << ", Count: " << count << endl;

}

//function to call the get description functions of each object in the vector
void callDescription(vector<Groceries*> Basket){

   cout << "Let's take a look at what's in our cart:" << endl;

   for (int i = 0; i < Basket.size(); i++){

      Basket[i]->getDescription();

   }

}
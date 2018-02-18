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

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//base class
class Groceries{

public:
   //pure virtual function
   virtual void getDescription()=0;

}; 

//derived class of groceries
class Fruit : public Groceries{

public:
   
   string name;
   virtual void getDescription();
   Fruit();
   Fruit(string name);
   ~Fruit(){};

};

//derived class of fruit
class Pineapple : public Fruit{

public:

   int count;
   virtual void getDescription();
   Pineapple();
   Pineapple(string name, int count);
   ~Pineapple(){};

};

//function to call the get description of the objects in the basket
void callDescription(vector<Groceries*> Basket);
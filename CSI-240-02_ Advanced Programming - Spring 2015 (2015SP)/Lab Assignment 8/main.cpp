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

int main(){

//initializing the vector of grocery object pointers
vector<Groceries*> Basket;

cout << "Let's go shopping for some groceries, we should get started with some apples" << endl;

//creating a fruit class object and adding it to the vector
Fruit apple("Apples");
Basket.push_back(&apple);

cout << "Grapes aren't that bad of a choice, and I like peaches too so we'll grab some." << endl;

system("pause");
system("CLS");

//adding more fruit class objects to the vector
Fruit grapes("Grapes");
Fruit peaches("Peaches");
Basket.push_back(&grapes);
Basket.push_back(&peaches);

//calling the get description functions for the objects in the basket
callDescription(Basket);

system("pause");
system("CLS");

cout << "Actually I think I have enough peaches at home so we'll take those out." << endl;

//deleting the last entry of the vector
Basket.pop_back();

system("pause");
system("CLS");

cout << "I think the last fruit we need are pineapples." << endl << "so we'll grab a ton of them, about 15." << endl;;

//creating a pineapple class object and adding it to the vector
Pineapple Pineapple("Pineapples", 15);
Basket.push_back(&Pineapple);

system("pause");
system("CLS");

callDescription(Basket);

cout << endl << "Looks like a successful shopping trip." << endl;

system("pause");

}
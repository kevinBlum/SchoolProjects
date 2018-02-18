/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Programming Assignment 4
Date Assigned : 2/19/15
Due Date : 3/2/15
Description : The purpose of the program is to prompt a user for input to dynamically create an array of strings using classes, and allow the user to change the size of the array using
pointers. There are now added operator overloading function examples.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Array{

public:

   Array();
   ~Array(){};

  //function prototypes
  void createTextArray(int);
  void createUserArray(int);
  void displaySize();
  void displayContents();
  void switchArray(int, int);
  //operator overload prototypes
  Array operator+(Array&);
  Array operator+(int);
  Array operator=(Array&);
  Array operator-(Array&);
  Array operator==(Array&);
  friend ostream& operator<<(ostream& output, Array& ArrayOne);
  friend istream& operator>>(istream& input, Array& ArrayOne);

private:

   //private class members
   static int counter;
   static int arraySize;
   string stringArray[100];

};
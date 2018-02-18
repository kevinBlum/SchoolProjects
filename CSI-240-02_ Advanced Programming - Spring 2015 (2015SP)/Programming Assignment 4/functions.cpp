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

#include "functions.h"

//function to produce the menu
int menu(){
   
   int choice = -1;   

   cout << "Please Select what you would like to do" << endl << "1 - Create and array from the text file" << endl << "2 - Create an array from your input" << endl << "3 - Quit the program" << endl;
   cin >> choice;
   cin.clear();
   cin.ignore();

   return choice;
}

//function to prompt user for the size
int askSize(){

   int size = 0;

   cout << "How large would like the array to be?" << endl;
   cin >> size;

   return size;
}

//function to prompt user if they would like to change the size
string changeSize(){

   string response = "";

   cout << "Would you like to change the size of the Array? (Y or N)" << endl;
   cin >> response;

   return response;
}


/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Lab 6
Date Assigned : 3/16/15
Due Date : 3/23/15

Description : The purpose of the program is to create a linked list based on user input and allows the user to display the list, state the size, remove the last member and delete the whole list.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#include <iostream>
#include <string>

using namespace std;

//struct for each node
struct List{
   string book;
   List* next;
   static int counter;
};

   //prototypes for each function
   void MenuFunction(List*, List*, List*);
   void AddNode(List*, List*, List*);
   void stateSize();
   void DisplayList(List*, List*);
   void RemoveNode(List*);
   void DeleteList(List*, List*, List*);




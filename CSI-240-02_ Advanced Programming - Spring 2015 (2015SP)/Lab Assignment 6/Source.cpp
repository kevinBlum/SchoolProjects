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


#include "Header.h"

using namespace std;

int main(){

   //creating struct objects for head, create and temp
   List* head = NULL;
   List* create = NULL;
   List* temp = NULL;

   //putting head, create into stack memory
   head = new List;
   create = new List;

   //calling the memory function
   MenuFunction(head, create, temp);

   system("pause");
}

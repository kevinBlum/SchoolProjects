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

int List::counter = 0;

//menu function that creates the display for the user to choose what to do
void MenuFunction(List* head, List* create, List* temp){

   int input;
   bool endFunction = false;

   do{

   system("CLS");
   cout << "Linked List: " << endl << "1 - Add a book node to the end of the list" << endl << "2 - State the size of the list";
   cout << endl << "3 - Traverse and Display the list" << endl << "4 - Remove a node at the end of the list" << endl;
   cout << "5 - Delete the Linked List" << endl << "6 - End Program" << endl;

   cin >> input;
   cin.ignore();
   cin.clear();

   switch (input){
      case 1: 
         AddNode(head, create, temp);
         break;
      case 2:
         stateSize();
         break;
      case 3:
         if (List::counter == 0){
            cout << "There are no items in the list" << endl;
            system("pause");
         }
         else
            DisplayList(head, temp);
         break;
      case 4:
         RemoveNode(head);
         break;
      case 5: 
         DeleteList(head, create, temp);
         break;
      case 6:
         if (List::counter != 0){
         DeleteList(head, create, temp);
         }
         endFunction = true;
   }

   }while (endFunction == false);

}

//add node function that adds each member to the linked list
void AddNode(List* head, List* create, List* temp){

   string book = " ";
   
   if (List::counter > 0) {
      cout << "What is the next book you would like to add to the list?" << endl;
      getline(cin, book);

      create = new List;
      create->book = book;
      create->next = NULL;

      temp = head;
      while (temp){
         if (temp->next == NULL){
            temp->next = create;
            List::counter++;
            return;
         }
         temp = temp->next;

      }

   }
 
   else if (List::counter == 0){

      cout << "What is the first book you would like to add to the list?" << endl;
      getline(cin, book);

      head->book = book;
      head->next = NULL;

      List::counter++;

   }
   
   

}

//function that states the size of the linked list
void stateSize(){

   cout << "The size of the linked list is " << List::counter << " books long" << endl;
   system("pause");

}

//function that traverses and displays the list
void DisplayList(List* head, List* temp){
   
   temp = head;

   if (head->next == NULL){
      cout << head->book << endl;
   }
   else{
      do{
         cout << temp->book << endl;
         temp = temp->next;
      } while (temp->next != NULL);
      cout << temp->book << endl;
   }

   system("pause");
}

//function that removes the last node of the linked list
void RemoveNode(List* head){

   if (head->next == NULL){
      delete head;
      head = NULL;
   }
   else {
      List* secondToLast = head;
      List* last = head->next;
         while (last->next != NULL){
            secondToLast = last;
            last = last->next;
         }
      delete last;
      secondToLast->next = NULL;
   }
   List::counter--;
}

//function that deletes the whole linked list
void DeleteList(List* head, List* create, List* temp){

   temp = head;

   if (head->next == NULL){
      delete head;
      head = NULL;
   }
   else{
      while (temp != NULL){
         delete create;
         create = NULL;
         temp = temp->next;
      }
   }
   delete head;
   head = NULL;
   List::counter = 0;
}
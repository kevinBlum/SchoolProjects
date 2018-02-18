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

#include "class.h"
#include "functions.h"


int main(){

   //variable declaration
   int choice = -1;
   bool loopEnd = false;
   int size;
   int newSize;
   string response;
   Array ArrayOne;
   int newNumber = 0;
   
   //loop to contain the program
   do {
      
      //getting input from menu function
      choice = menu();

      if (choice == 1){

         size = askSize();

         ArrayOne.createTextArray(size);
        
         response = changeSize();
         
            if (response == "Y" || response == "y"){
               cout << "Enter a new size: ";
               cin >> newSize;
               ArrayOne.switchArray(size, newSize);
            }
         
         cout << "Would you like to enter the odd world of operator overloading?" << endl;
         cin >> response;

         if (response == "Y" || response == "y"){
            ArrayOne + ArrayOne;
            ArrayOne + newNumber;
            ArrayOne - ArrayOne;
            ArrayOne = ArrayOne;
            ArrayOne == ArrayOne;
            cout << "Put in a number to change the global counter" << endl;
            cin >> ArrayOne;
            cout << ArrayOne;
         }
               
         cout << "Would you like to display the size and contents of your array? (Y or N)" << endl;
         cin >> response;
         if (response == "Y" || response == "y"){
            ArrayOne.displaySize();
            ArrayOne.displayContents();
         }
         system("pause");
         system("CLS");
      }
      
      else if (choice == 2){
   
         size = askSize();

         ArrayOne.createUserArray(size);

         response = changeSize();

         if (response == "Y" || response == "y"){
            cout << "Enter a new size: ";
            cin >> newSize;
            ArrayOne.switchArray(size, newSize);
         }

         cout << "Would you like to enter the odd world of operator overloading?" << endl;
         cin >> response;

         if (response == "Y" || response == "y"){
            ArrayOne + ArrayOne;
            ArrayOne + newNumber;
            ArrayOne - ArrayOne;
            ArrayOne = ArrayOne;
            ArrayOne == ArrayOne;
            cout << "Put in a number to change the global counter" << endl;
            cin >> ArrayOne;
            cout << ArrayOne;
         }

         cout << "Would you like to display the size and contents of your array? (Y or N)" << endl;
         cin >> response;
         if (response == "Y" || response == "y"){
            ArrayOne.displaySize();
            ArrayOne.displayContents();
         }
         system("pause");
         system("CLS");
      }

      else if (choice == 3)
         loopEnd = true;

      } while (loopEnd == false);


return 0;
}
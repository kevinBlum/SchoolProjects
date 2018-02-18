/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Final Project
Date Assigned : 4/16/15
Due Date : 4/24/15
Description : The purpose of the program is to create a mock computer builder that presents the user with options to build desktops or laptops that are meant for casual or gaming use and to decide based
on price the quality of the computers, dimension or size, and the graphics card if meant for a gaming PC and outputs the potential price of said computer. 
It utilizies two different class hierarchies with polymorphism to create the computer objects
and operator overloading to add information or clear a log file to keep track of information deemed important by the user. 

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/


#include "functions.h"

int main(){



   //variables for menu and operator overloads
   int menuInput = -1;
   bool menuClose = false;
   Iteration newIter;

   do{

      //menu screen information
      cout << "Welcome to the Computer Builder" << endl;
      cout << "1 - Build a Desktop" << endl << "2 - Build a Laptop" << endl << "3 - Add info to the log file" << endl;
      cout << "4 - Clear the log file" << endl << "5 - End program" << endl << endl << "Number of computers created this session: " << Iteration::computersCreated << endl;

      cin >> menuInput;
      cin.ignore();

      //building a desktop
   if(menuInput == 1){
      Desktop newDesktop;
      Desktop* ptr = &newDesktop;
      newDesktop.buildDesktop(ptr);

      ptr = NULL;
      delete ptr;
      
   }
   //building a laptop
   else if (menuInput == 2){
      Laptop newLaptop;
      Laptop* ptr = &newLaptop;
      newLaptop.buildLaptop(ptr);

      ptr = NULL;
      delete ptr;
      
   }
   //adding to the log file
   else if (menuInput == 3) {

      newIter + newIter;
      
   }
   //clearing the log file
   else if (menuInput == 4){

      cout << newIter;
      
   }
   //ending the program
   else if (menuInput == 5){
      menuClose = true;
   }

   } while (menuClose == false);


return 0;
}
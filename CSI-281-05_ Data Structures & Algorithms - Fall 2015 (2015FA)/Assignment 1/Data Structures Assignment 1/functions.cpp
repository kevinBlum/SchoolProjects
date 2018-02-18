#include "header.h"
#include "generalOperations.h"
#include <iostream>

//Main menu screen

int menu(){

   int menuInput = -1;
   clearScreen();

   cout << "Patient Database Menu" << endl << endl;
   cout << "1. Add Patient" << endl;
   cout << "2. Remove Patient" << endl;
   cout << "3. Search for a Patient" << endl;
   cout << "4. Update Name" << endl;
   cout << "5. Exit the program" << endl;

   cin >> menuInput;
   return menuInput;
}
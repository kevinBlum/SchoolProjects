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

int Iteration::computersCreated = 0;

//default constructor for Gaming
Gaming::Gaming(){

   name = "";
   quality = "";
   graphicsCard = "";

}

//alternate constructor for Gaming
Gaming::Gaming(string input){

   name = input;

}

//default constructor for Casual
Casual::Casual(){

   name = "";
   quality = "";

}

//alternate constructor for Casual
Casual::Casual(string input){

   name = input;
   

}

//virtual function to get description for Gaming
void Gaming::getDescription(){

   cout << "Graphics Card:  " << graphicsCard << endl << "Quality: " << quality << endl;

}

//virtual function to get description for Casual
void Casual::getDescription(){

   cout << "Quality: " << quality << endl;

}

//default constructor for Desktop
Desktop::Desktop(){

   name = "";
   pSize = "";

}

//build Desktop function, redirects from first menu option
void Desktop::buildDesktop(Desktop* ptr){

   int price = 0;
   
   double answer = 0.0;
   string response = "";
   char styleChar;

   string fileName = "";
   ofstream compOut;

   cout << "What would you like to name your computer?" << endl;
   getline(cin, response);
   ptr->name = response;

   cout << "What size case would you like: " << endl << endl << "1. Mini ITX (Small - $75)" << endl << "2. Mid Tower (Standard - $100)" << endl << "3. Full Tower (Large - $130)" << endl;
   cin >> answer;
   cin.ignore();
   if (answer == 1){
      ptr->pSize = "Mini ITX";
      price += 75;
   }
   else if (answer == 2){
      ptr->pSize = "Mid Tower";
      price += 100;
   }
   else if (answer == 3){
      ptr->pSize = "Full Tower";
      price += 130;
   }

   cout << "What style computer are you looking for, gaming or casual? ('G' or 'C')" << endl;
   cin >> styleChar;
   cin.ignore();
   if (styleChar == 'G' || styleChar == 'g'){

      Gaming newGaming(response);
      Gaming* ptrGaming = &newGaming;

      cout << "What graphics card brand would you like, nVidia or AMD? ('N' or 'A')" << endl;
      cin >> styleChar;
      if (styleChar == 'N' || styleChar == 'n'){
         cout << "Which graphics card would you like: " << endl << endl << "1. GTX 770 (Solid - $260)" << endl << "2. GTX 980 (Powerful - $560)" << endl << "3. Titan Black (Best - $1000)" << endl;
         cin >> answer;
         cin.ignore();

         if (answer == 1){
            ptrGaming->graphicsCard = "GTX 770";
            price += 260;
         }
         else if (answer == 2) {
            ptrGaming->graphicsCard = "GTX 980";
            price += 560;
         }
         else if (answer == 3) {
            ptrGaming->graphicsCard = "Titan Black";
            price += 1000;
         }
      }
   
      if (styleChar == 'A' || styleChar == 'a'){
         cout << "Which graphics card would you like: " << endl << endl << "1. R9 280x (Solid - $260)" << endl << "2. R9 290x (Powerful - $560)" << endl << "3. Two R9 295x's (Best - $1000)" << endl;
         cin >> answer;
         cin.ignore();

         if (answer == 1){
            ptrGaming->graphicsCard = "R9 280x";
            price += 260;
         }
         else if (answer == 2) {
            ptrGaming->graphicsCard = "R9 290x";
            price += 560;
         }
         else if (answer == 3) {
            ptrGaming->graphicsCard = "Two R9 295x's";
            price += 1000;
         }
      }

      cout << "What about the rest of the quality of the machine (CPU, Motherboard, Memory, Storage): " << endl << endl;
      cout << "1. Solid Quality - $500" << endl << "2. High Quality - $800" << endl << "3. Superb Quality - $1200" << endl;

      cin >> answer;
      cin.ignore();

      if (answer == 1){
         ptrGaming->quality = "Solid";
         price += 500;
      }
      else if (answer == 2) {
         ptrGaming->quality = "High";
         price += 800;
      }
      else if (answer == 3) {
         ptrGaming->quality = "Superb";
         price += 1200;
      }
   
      cout << "Your new computer specs and budget estimation are as follows : " << endl << endl;
      ptr->callShape();
      newGaming.getDescription();
      cout << "Price: $" << price << endl;

      cout << "Enter a file name for your computer specifications (INCLUDE .txt)" << endl;
      cin >> fileName;
      compOut.open(fileName);
      compOut << "Name: " << ptr->name << endl << "Size: " << ptr->pSize << endl << "Graphics Card: " << ptrGaming->graphicsCard << endl << "Build Quality: " << ptrGaming->quality << endl << "Price: $" << price;
   
      ptrGaming = NULL;
      delete ptrGaming;

      Iteration::computersCreated++;
      system("CLS");

   }
   else if (styleChar == 'C' || styleChar == 'c'){

      Casual newCasual(response);
      Casual* ptrCasual = &newCasual;

      cout << "What kind of quality would you like for your desktop" << endl<< "(CPU, Motherboard, Memory, Storage): " << endl << endl;
      cout << "1. Solid Quality - $500" << endl << "2. High Quality - $800" << endl << "3. Superb Quality - $1200" << endl;

      cin >> answer;
      cin.ignore();

      if (answer == 1){
         ptrCasual->quality = "Solid";
         price += 300;
      }
      else if (answer == 2) {
         ptrCasual->quality = "High";
         price += 500;
      }
      else if (answer == 3) {
         ptrCasual->quality = "Superb";
         price += 800;
      }
      
      cout << "Your new computer specs and budget estimation are as follows : " << endl << endl;
      ptr->callShape();
      newCasual.getDescription();
      cout << "Price: $" << price << endl;

      cout << "Enter a file name for your computer specifications (INCLUDE .txt)" << endl;
      cin >> fileName;
      compOut.open(fileName);
      compOut << "Name: " << ptr->name << endl << "Size: " << ptr->pSize << endl << "Build Quality: " << ptrCasual->quality << endl << "Price: $" << price;

      ptrCasual = NULL;
      delete ptrCasual;
      
      Iteration::computersCreated++;
      system("CLS");

   }
   
}

//defualt constructor for Laptop
Laptop::Laptop(){

   name = "";
   pSize = 0.0;

}

//build laptop function that redirects from the second menu option
void Laptop::buildLaptop(Laptop* ptr){

   int price = 0;

   double answer = 0.0;
   string response = "";
   char styleChar;

   string fileName = "";
   ofstream compOut;

   cout << "What would you like to name your computer?" << endl;
   getline(cin, response);
   ptr->name = response;

   cout << "What size laptop are you looking for: " << endl << endl << "1. 11.5 inches (Small - $300)" << endl << "2. 15.6 inches (Medium - $500)" << endl << "3. 18 inches (Large - $750)" << endl;
   cin >> answer;
   cin.ignore();
   
   if (answer == 1){
      ptr->pSize = 11.5;
      price += 300;
   }
   else if (answer == 2){
      ptr->pSize = 15.6;
      price += 500;
   }
   else if (answer == 3){
      ptr->pSize = 18;
      price += 750;
   }
   

   cout << "What style computer are you looking for, gaming or casual? ('G' or 'C')" << endl;
   cin >> styleChar;
   cin.ignore();
   if (styleChar == 'G' || styleChar == 'g'){

      Gaming newGaming(response);
      Gaming* ptrGaming = &newGaming;

      cout << "What about the rest of the quality of the machine (CPU, Motherboard, Memory, Storage): " << endl << endl;
      cout << "1. Solid Quality - $500" << endl << "2. High Quality - $800" << endl << "3. Superb Quality - $1200" << endl;

      cin >> answer;
      cin.ignore();

      if (answer == 1){
         ptrGaming->quality = "Solid";
         price += 500;
      }
      else if (answer == 2) {
         ptrGaming->quality = "High";
         price += 800;
      }
      else if (answer == 3) {
         ptrGaming->quality = "Superb";
         price += 1200;
      }
      
      cout << "Your new computer specs and budget estimation are as follows : " << endl << endl;
      ptr->callShape();
      cout << "Quality: " << ptrGaming->quality << endl;
      cout << "Price: $" << price << endl;

      cout << "Enter a file name for your computer specifications (INCLUDE .txt)" << endl;
      cin >> fileName;
      compOut.open(fileName);
      compOut << "Name: " << ptr->name << endl << "Size: " << ptr->pSize << " inches" << endl << "Build Quality: " << ptrGaming->quality << endl << "Price: $" << price;

      ptrGaming = NULL;
      delete ptrGaming;

      Iteration::computersCreated++;
      system("CLS");
   
   }

   else if (styleChar == 'C' || styleChar == 'c'){

         Casual newCasual(response);
         Casual* ptrCasual = &newCasual;

         cout << "What kind of quality would you like for your desktop" << endl << "(CPU, Motherboard, Memory, Storage): " << endl << endl;
         cout << "1. Solid Quality - $500" << endl << "2. High Quality - $800" << endl << "3. Superb Quality - $1200" << endl;

         cin >> answer;
         cin.ignore();

         if (answer == 1){
            ptrCasual->quality = "Solid";
            price += 300;
         }
         else if (answer == 2) {
            ptrCasual->quality = "High";
            price += 500;
         }
         else if (answer == 3) {
            ptrCasual->quality = "Superb";
            price += 800;
         }

         cout << "Your new computer specs and budget estimation are as follows : " << endl << endl;
         ptr->callShape();
         cout << "Quality: " << ptrCasual->quality << endl;
         cout << "Price: $" << price << endl;

         cout << "Enter a file name for your computer specifications (INCLUDE .txt)" << endl;
         cin >> fileName;
         compOut.open(fileName);
         compOut << "Name: " << ptr->name << endl << "Size: " << ptr->pSize << " inches" << endl << "Build Quality: " << ptrCasual->quality << endl << "Price: $" << price;
         
         ptrCasual = NULL;
         delete ptrCasual;

         Iteration::computersCreated++;
         system("CLS");


   }
}

//virtual function for Desktop
void Desktop::callShape(){

   cout << "The specifications of your new Desktop: " << endl << "Name : " << name << endl << "Size : " << pSize << endl;

}

//virtial function for Laptop
void Laptop::callShape(){

   cout << "The specifications of your new Laptop: " << endl << "Name : " << name << endl << "Size : " << pSize << " inches" << endl;

}


//operator overload to clear the log file of any text
ostream& operator<<(ostream& output, Iteration& newIter){

   ofstream fout;
   fout.open("fileLog.txt");
   fout.close();

   output << "The Log file is now clear." << endl;
   system("pause");
   system("CLS");
   return output;
}

//operator overloa to add new information to log file
Iteration Iteration::operator+(Iteration& newIter){

   string newInput;
   cout << "What would you like to add?" << endl;
   getline(cin, newInput);
   ofstream fout;
   fout.open("fileLog.txt", ofstream::out | ofstream::app);
   fout << newInput << endl;

   system("pause");
   system("CLS");

   return newIter;
}


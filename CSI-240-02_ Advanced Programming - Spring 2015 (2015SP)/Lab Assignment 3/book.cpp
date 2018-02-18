/*
main.cpp
lab3

Author:  Kevin Blum
Class:   240-02
Assignment:  Lab 3
Date Assigned: 1/22/14
Due Date: 1/26/14

Description:   The purpose of the program is to read in information about books from a text file then organize the information such as the name, type, page and weight
using a class and number of functions then format the information and output the formatted information.

Certification of Authenticity:  I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or -
Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking


Created by Brian R. Hall on 1/8/14.
Copyright (c) 2014 Brian R. Hall. All rights reserved.
*/

#include "book.h"

//Default Constructor
Book::Book(){

   bName = " ";
   bType = UNKNOWN;
   bPages = 0;
   bOunces = 0.0f;

}

//Constructor with the parameters from the text file
Book::Book(const string& name, Type type, int pages, float ounces){
   
   bName = name;
   bType = type;
   bPages = pages;
   bOunces = ounces;

}

//Function to convert the weight of the book from ounces to pounds
float getWeightLbs(float bOunces){

   bOunces = bOunces / 16;

   return bOunces;
}

//Function to convert the enum Type into the string name for the type
string getTypeName(Type bType){

   string str = " ";

   if (bType = PAPERBACK)
      str = "Paperback";
   else if (bType = HARDBACK)
      str = "Hardcover";

   return str;
}

//Function that takes all boook information and formats it into a cout statement
void formatReportLine(const string& bName, Type type, int bPages, float bOunces){
   
   float pounds = getWeightLbs(bOunces);
   string stringType = getTypeName(type);

   cout << bName << " | Type: " << stringType << " Pages: " << bPages << " Weight(lbs): " << pounds << endl;


}


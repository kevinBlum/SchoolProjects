/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Lab 1
Date Assigned : 1 / 14 / 15
Due Date : 1 / 19 / 15

Description : The purpose of the program is to read in information from a text file to load into a 2D array and then format the information from the 2D array and an array of strings
and concatenate them into one coherent string then output the entire statement.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or -
Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking

*/

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "functions.h"

using namespace std;


int loadLanguages(const string& filename, string names[], int maxLanguages)
{
   int numNames = 0;

   ifstream input(filename);
   if (input.is_open()){
      while (!input.eof() && numNames < maxLanguages){
         getline(input, names[numNames]);
         numNames++;
      }
      input.close();
   }
   return numNames;
}


bool loadInfo(const string& filename, int infoArray[][INFO], int numLanguages)
{ //I believe that I have loaded the 2D array properly with the file input but I am not entirely sure because I had trouble
   //getting the array to display and output properly outside of this function.

   int num = 0;
   int year = 0;

   ifstream fin;
   fin.open(filename);
   if (fin.is_open()){
      for (int i = 0; i < 13; i++){
         fin >> num;
         infoArray[i][numLanguages] = num;
         cout << infoArray[i][numLanguages];
         for (int j = 0; j < 1; j++){

            fin >> year;
            infoArray[i][j] = year;
         }
      }
   }
   fin.close();

   return true;
}


string formatReportLine(int languageRank, int infoArray[][INFO], string names[])
{  //I had trouble here because the infoArray never displayed properly for me, it always came out with odd symbols that I wasn't sure where they came from
   //and I wish I understood why. I thought it could be either from the stringstream or the function being overloaded somehow but I couldn't figure it out.

   stringstream ss;
   string str;
   ss >> str;

   for (int i = 0; i < 12; i++){
      for (int j = 0; j < 1; j++){
         str = names[languageRank];
         str += infoArray[i][j];
      }
   }
   ss << str;

   return str;
}
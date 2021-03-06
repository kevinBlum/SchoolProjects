/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Programming Assignment 3
Date Assigned : 2/12/15
Due Date : 2/19/15
Description : The purpose of the program is to prompt a user for input to dynamically create an array of strings using classes, and allow the user to change the size of the arrow using
pointers.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#include "class.h"

//static member function
int Array::arraySize;
int Array::counter;

//constructor
Array::Array(){

   arraySize = 0;

}

//creates an array from text file
void Array::createTextArray(int size){

   ifstream fin("stringFile.txt");
   arraySize = size;
   string input = "";
   stringArray[arraySize];
   Array::counter = 0;

   for (int i = 0; i < arraySize; i++){
   
      getline(fin, input);
      stringArray[i] = input;
      counter += 1;

   }

}

//creates and array from the user
void Array::createUserArray(int size){

   arraySize = size;
   stringArray[arraySize];
   string newWord = "";
   counter = 0;

   cout << "Enter the words you would like to add to the array: \n";

   for (int i = 0; i < arraySize; i++){
      
      cin >> newWord;
      stringArray[i] = newWord;
      counter += 1;

   }

}

//displays the number of words in the array
void Array::displaySize(){

   cout << "The number of words in the array is: " << counter << endl;


}

//displays the words in the array
void Array::displayContents(){

   string arrayWord = "";
   cout << "The words in the array are: ";

   for (int i = 0; i < arraySize; i++){

      arrayWord = stringArray[i];
      cout << arrayWord << endl;
   
   }

}

//changes the size of the array
void Array::switchArray(int size, int newSize){

   string* arrayNew;
   arrayNew = new string[size];
   counter = 0;
   string word = "";
   string blank = "";

   for (int i = 0; i < size; i++){
      word = stringArray[i];
      arrayNew[i] = word;
      stringArray[i] = blank;

   }
   for (int i = 0; i < newSize; i++){

      stringArray[i] = arrayNew[i];
      counter++;
   }

   delete[] arrayNew;
}
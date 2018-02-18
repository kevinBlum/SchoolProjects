/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Lab
Date Assigned : 2/5/15
Due Date : 2/9/15

Description : The purpose of the program is to prompt the user for a number to create the size of an array and then using dynamic memory allocation create the array
with a pointer and the user submitted size, then populate the array with random values and display the array, then using bubble sort, sort the array and display the array again.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment : 
-Reproduce this assignment and provide a copy to another member of academic staff; and / or - 
Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/


#include <iostream>
#include <ctime>

using namespace std;

//Function prototypes
int promptSize();
void populate(int size, int *ptr);
void display(int size, int *ptr);
void sort(int size, int *ptr);

int main(){

   //Creating a random value based on the time
   srand(unsigned(time(NULL)));

   int size = promptSize();

   int *ptr = new int[size];

   populate(size, ptr);

   cout << "The values in the array: " << endl;
   display(size, ptr);

   sort(size, ptr);

   cout << "The array after being sorted: " << endl;
   display(size, ptr);


   system("pause");
   delete ptr;
   return 0;
}

//Function to prompt the user for a size
int promptSize(){

   int size = 0;
   cout << "Enter a size for the array: ";
   cin >> size;

   return size;
}

//Function to populate the array with random values
void populate(int size, int* ptr){
   

   for (int i = 0; i < size; i++){

      ptr[i] = rand() % 50 + 1;

   }

}

//Function to display the array of integers
void display(int size, int* ptr){

   for (int i = 0; i < size; i++){

      cout << ptr[i] << " ";

   }

   cout << endl;

}

//Function to sort the array of integers
void sort(int size, int* ptr){

int i, j, flag = 1;   
int temp;  
           
      for (i = 1; (i < size) && flag; i++)
         {
            flag = 0;
            for (j = 0; j < size; j++)
            {
               if (ptr[j - 1] > ptr[j])      
               {
                  temp = ptr[j];             
                  ptr[j] = ptr[j - 1];
                  ptr[j - 1] = temp;
                  flag = 1;               
               }
            }
         }

}


/*
Author:  Kevin Blum
Class : 281-05
Assignment : Assignment #2
Date Assigned : 9/16/15
Due Date : 9/23/15

Description : The purpose of the program is to implement the sorting algorithms of bubble, insertion, selection, and merge in order to test their speed at sorting 
an array filled with random numbers and shuffled. The program will also merge two existing and sorted arrays into one array.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#include "header.h"


int main(){

   srand(time(NULL));
   const int size = 10;
   int sortArray[size];

   //Populating the array and then shuffling it
   createArray(sortArray, size);
   random_shuffle(begin(sortArray), end(sortArray));
   cout << "The original array is: " << endl;
   outputArray(sortArray, size);

   //Putting the array through the standard sort function then shuffling it
   clock_t start = clock();
   sort(begin(sortArray), end(sortArray));
   clock_t ending = clock();
   double time = (double)(ending-start);
   cout << "It took standard sort " << time * 1000 << " milliseconds to sort the array" << endl;
   outputArray(sortArray, size);
   system("pause");
   system("CLS");
   random_shuffle(begin(sortArray), end(sortArray));


   //Putting the array through the bubble sort function then shuffling it
   bubbleSort(sortArray, size);
   random_shuffle(begin(sortArray), end(sortArray));

   //Putting the array though the insertion sort function then shuffling it
   insertionSort(sortArray, size);
   random_shuffle(begin(sortArray), end(sortArray));

   //Putting the array through the selection sort function then shuffling it
   selectionSort(sortArray, size);
   random_shuffle(begin(sortArray), end(sortArray));

   //Putting the array through the merge sort function
   clock_t startMerge = clock();
   mergeSort(sortArray, 0, size - 1);
   clock_t endMerge = clock();
   double timeMerge = (double)(endMerge - startMerge);
   cout << "It took Merge sort " << timeMerge * 1000 << " milliseconds to sort the array" << endl;
   outputArray(sortArray, size);
   system("pause");
   system("CLS");

   //Variables and function to sort two already merged arrays
   const int sizeA = 5;
   const int sizeB = 10;
   const int sizeC = sizeB + sizeA;
   cout << "This function will now merge two already sorted arrays, A: {1, 2, 4, 5, 20} and B: {3, 5, 6, 7, 8, 9, 10, 11, 15, 19}" << endl;
   int A[sizeA] = {1, 2, 4, 5, 20};
   int B[sizeB] = {3, 5, 6, 7, 8, 9, 10, 11, 15, 19};
   int C[sizeC];

   mergeTwoSorted(sizeA, sizeB, A, B, C);

   system("pause");
   return 0;
}
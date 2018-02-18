/*
Author:  Kevin Blum
Class : 281-05
Assignment : Assignment #3
Date Assigned : 9/21/15
Due Date : 9/27/15

Description : The purpose of the program is to implement the sorting algorithms of shell and quick sort in order to test their speed at sorting
an array filled with random numbers and shuffled.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#include "header.h"



int main(){

   //random number generation based on time
   srand(time(NULL));



   //variable of size and creation of array
   //pow(2,10) = 1024
   const int size = 1024;
   int mArray[size];

   //populating the array
   createArray(mArray, size);


   cout << "Quick Sort" << endl << "The original list: " << endl;
   outputArray(mArray, size);

   //vairables based on the clock time for timing how long the algorithm takes to complete in milliseconds
   clock_t startQuick = clock();
   
   //function call to the algorithm to sort the array   
   quickSort(mArray, 0, size - 1, size);

   clock_t endQuick = clock();
   double timeQuick = (double)(endQuick - startQuick);

   cout << "It took Quick sort " << timeQuick * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");

   //function to shuffle the array so the next algorithm isnt handed a sorted array
   random_shuffle(begin(mArray), end(mArray));

   //vairables based on the clock time for timing how long the algorithm takes to complete in milliseconds
   clock_t startShell = clock();

   //function call to the algorithm to sort the array   
   shellSort(mArray, size);

   clock_t endShell = clock();
   double timeShell = (double)(endShell - startShell);

   cout << "It took Shell sort " << timeShell * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");


   //second array using 2^13 size instead
   //pow(2,13) = 8192
   const int size2 = 8192;
   int nArray[size2];

   createArray(nArray, size2);

   cout << "Quick Sort" << endl << "The original list: " << endl;
   outputArray(nArray, size2);

   clock_t startQuick2 = clock();
   quickSort(nArray, 0, size2 - 1, size2);
   clock_t endQuick2 = clock();
   double timeQuick2 = (double)(endQuick2 - startQuick2);

   cout << "It took Quick sort " << timeQuick2 * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");


   random_shuffle(begin(nArray), end(nArray));


   clock_t startShell2 = clock();
   shellSort(nArray, size2);
   clock_t endShell2 = clock();
   double timeShell2 = (double)(endShell2 - startShell2);

   cout << "It took Shell sort " << timeShell2 * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");



   //third array using 2^16 size instead
   //pow(2,16) = 65536
   const int size3 = 65536;
   int oArray[size3];

   createArray(oArray, size3);

   cout << "Quick Sort" << endl << "The original list: " << endl;
   outputArray(oArray, size3);

   clock_t startQuick3 = clock();
   quickSort(oArray, 0, size3 - 1, size3);
   clock_t endQuick3 = clock();
   double timeQuick3 = (double)(endQuick3 - startQuick3);

   cout << "It took Quick sort " << timeQuick3 * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");


   random_shuffle(begin(oArray), end(oArray));


   clock_t startShell3 = clock();
   shellSort(oArray, size3);
   clock_t endShell3 = clock();
   double timeShell3 = (double)(endShell3 - startShell3);

   cout << "It took Shell sort " << timeShell3 * 1000 << " milliseconds to sort the array" << endl;
   

   system("pause");
return 0;
}
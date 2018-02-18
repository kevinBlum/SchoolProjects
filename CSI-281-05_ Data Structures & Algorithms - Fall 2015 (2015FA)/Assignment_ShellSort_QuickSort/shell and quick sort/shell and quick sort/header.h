#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <algorithm>

using namespace std;

//template to fill an array of random values
template <typename A>
void createArray(A mArray[], A size){

   for (int i = 0; i < size; i++){

      mArray[i] = rand()%size+1;

   }


}

//Template for the shell sort function 
template <typename T>
T shellSort(T mArray[], T size){

   cout << "Shell Sort" << endl << "The original list: " << endl;
   outputArray(mArray, size);

   int gap, i, j, temp;


   for (gap = size / 2; gap > 0; gap /= 2)

   for (i = gap; i < size; i++)

   for (j = i - gap; j >= 0 && mArray[j]>mArray[j + gap]; j -= gap) {

      cout << "Swapping " << mArray[j] << " and " << mArray[j + gap] << endl;

      temp = mArray[j];

      mArray[j] = mArray[j + gap];

      mArray[j + gap] = temp;

      cout << "The resulting list: " << endl;
      outputArray(mArray, size);

   }

return 0;
}

//function to swap the values for the quicksort algorithm
void change(int& a, int& b){

   cout << "Swapping " << a << " and " << b << endl;

   int temp = a;
   a = b;
   b = temp;


}

//function for the quicksort algorithm to create a pivot in the array and swap the values based on the pivot element
int pivot(int mArray[], int first, int last, int size){

   int  p = first;
   int pivotElement = mArray[first];

   for (int i = first + 1; i <= last; i++)
   {
      
      if (mArray[i] <= pivotElement)
      {
         p++;
         change(mArray[i], mArray[p]);
      }
   }

   change(mArray[p], mArray[first]);
   cout << "The resulting list: " << endl;
   for (int i = 0; i < size; i++){

      cout << mArray[i] << endl;

   }

   return p;
}

//template for the quicksort algorithm
template <typename F>
F quickSort(F mArray[], F first, F last, F size){

   
   int pivotElement;

   if (first < last)
   {
      pivotElement = pivot(mArray, first, last, size);
      quickSort(mArray, first, pivotElement - 1, size);
      quickSort(mArray, pivotElement + 1, last, size);
   }

   


return 0;
}

//function to output a given array
void outputArray(int mArray[], int size){

   for (int i = 0; i < size; i++){

      cout << mArray[i] << endl;

   }


}
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

//Function to population the array with random values
template <typename A>
void createArray(A sortArray[], A size){

   
   for (int i = 0; i < size; i++){

      sortArray[i] = rand() % size + 1;

   }


}

//Function to output array
void outputArray(int sortArray[], int size){

   cout << "The resulting list: " << endl;
   for (int f = 0; f < size; f++){
      cout << sortArray[f] << endl;
   }
   cout << endl << endl;

}

//Function to perform bubble sort algorithm
template <typename T>
void bubbleSort(T sortArray[], T size){


   cout << "Bubble Sort: " << endl;
   cout << "*** original list: ";
   for (int k = 0; k < size; k++){
      cout << sortArray[k] << ", ";
   }
   cout << endl << endl;

   bool swapFlag = true;
   int j = 0;
   int temp;

   clock_t start = clock();

   while (swapFlag) {
      swapFlag = false;
      
      for (int i = 0; i < size - 1; i++){

         if (sortArray[i] > sortArray[i + 1]){

            j++;
            cout << "Swap #" << j << endl;
            
            cout << "Swapping " << sortArray[i] << " with " << sortArray[i + 1] << endl;

            temp = sortArray[i];
            sortArray[i] = sortArray[i + 1];
            sortArray[i + 1] = temp;
            swapFlag = true;

            outputArray(sortArray, size);

         }

      }

   }

   clock_t ending = clock();
   double time = (double)(ending - start);
   cout << "It took bubble sort " << time * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");

}

//Function to perform insertion sort algorithm
template <typename T>
void insertionSort(T sortArray[], T size){

   int i, j, temp;
   
   cout << "Insertion Sort: " << endl;
   cout << "*** original list: ";
   for (int k = 0; k < size; k++){
      cout << sortArray[k] << ", ";
   }
   cout << endl << endl;

   clock_t start = clock();
   for (j = 1; j < size; j++){

      temp = sortArray[j];

      for (i = j - 1; i >= 0 && sortArray[i] > temp; i--){

         cout << "Swapping " << sortArray[i] << " and " << sortArray[i+1] << endl;
         sortArray[i + 1] = sortArray[i];
     
      
      }
      
      sortArray[i+1] = temp;

      cout << "The resulting list: " << endl;
      for (int f = 0; f < size; f++){
         cout << sortArray[f] << endl;
      }
      cout << endl << endl;
      

   }
   
   clock_t ending = clock();
   double time = (double)(ending - start);
   cout << "It took Insertion sort " << time * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");
}

//Function to perform selection sort algorithm
template <typename T>
void selectionSort(T sortArray[], T size){

   cout << "Selection Sort: " << endl;
   cout << "*** original list: ";
   for (int k = 0; k < size; k++){
      cout << sortArray[k] << ", ";
   }
   cout << endl << endl;

   int first, temp;

   clock_t start = clock();
   for (int i = 0; i < size - 1; i++)
   {
      first = i;

      for (int j = i + 1; j < size; j++)
      {

         if (sortArray[j] < sortArray[first])
            first = j;

      }


      if (first != i)
      {

         //cout << "Swapping " << sortArray[i] " and " << sortArray[first] << endl;
         temp = sortArray[i];
         sortArray[i] = sortArray[first];
         sortArray[first] = temp;

         cout << "The resulting list: " << endl;
         for (int f = 0; f < size; f++){
            cout << sortArray[f] << endl;
         }
         cout << endl << endl;
      }
   }


   clock_t ending = clock();
   double time = (double)(ending - start);
   cout << "It took Selection sort " << time * 1000 << " milliseconds to sort the array" << endl;

   system("pause");
   system("CLS");
}

//Function to perform merge sort algorithm
template <typename T>
void mergeSort(T sortArray[], T p, T r)
{

   clock_t start = clock();

   int size = sizeof(sortArray);
   int q;
   if (p<r)
   {
      q = (p + r) / 2;
      mergeSort(sortArray, p, q);
      mergeSort(sortArray, q + 1, r);
      merge(sortArray, p, q, r);
   }
   cout << "The resulting list: ";
   for (int f = 0; f < size; f++){
      cout << sortArray[f] << ", ";
   }
   cout << endl << endl;

}

//Function to merge the arrays together for the merge sort algorithm
template <typename T>
void merge(T sortArray[], T p, T q, T r)
{
   int size = sizeof(sortArray);
   cout << "Beginning Merge" << endl;
   int n1 = q - p + 1;
   int n2 = r - q;
   int *L = new int[n1 + 1];
   int *R = new int[n2 + 1];
   for (int i = 1; i <= n1; i++)
   {
      L[i] = sortArray[p + i - 1];
   }
   for (int j = 1; j <= n2; j++)
   {
      R[j] = sortArray[q + j];
   }
   L[n1 + 1] = 999;
   R[n2 + 1] = 999;
   int i = 1, j = 1;
   for (int k = p; k <= r; k++)
   {
      if (L[i] <= R[j])
      {
         sortArray[k] = L[i];
         i = i + 1;
      }
      else
      {
         sortArray[k] = R[j];
         j = j + 1;
      }
   }

   cout << "The resulting list: ";
   for (int f = 0; f < size; f++){
      cout << sortArray[f] << ", ";
   }
   cout << endl << endl;
}

//Function to merge two already sorted arrays
template <typename T>
void mergeTwoSorted(T sizeA, T sizeB, T A[], T B[], T C[]) {

   int i, j, k;

   i = 0;
   j = 0;
   k = 0;

   while (i < sizeA && j < sizeB) {

      if (A[i] <= B[j]) {

         C[k] = A[i];

         i++;

      }
      else {

         C[k] = B[j];

         j++;

      }

      k++;

   }

   if (i < sizeA) {

      for (int p = i; p < sizeA; p++) {

         C[k] = A[p];

         k++;

      }

   }
   else {

      for (int p = j; p < sizeB; p++) {

         C[k] = B[p];

         k++;

      }

   }

   cout << "The resulting list: ";
   for (int f = 0; f < sizeA + sizeB; f++){
      cout << C[f] << ", ";
   }
   cout << endl << endl;

}
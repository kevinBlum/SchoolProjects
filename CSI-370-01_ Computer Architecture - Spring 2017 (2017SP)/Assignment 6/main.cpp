/*
main.cpp
Kevin Blum
cpp functions to be called from assembly program


*/

#include <iostream>

using namespace std;

//Extern "C" because it is an external function with the cdecl calling convention
extern "C" void getNum(int, int);
extern "C" void outputSum(int);


void getNum(int one, int two){


   cout << "Choose the first integer: ";
   cin >> one;
   cout << "Choose the second integer: ";
   cin >> two;

}

void outputSum(int sum){

   cout << "The sum is " << sum;

}
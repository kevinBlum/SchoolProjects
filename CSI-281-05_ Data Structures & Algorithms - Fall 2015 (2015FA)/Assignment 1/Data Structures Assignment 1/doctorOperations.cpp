#include "doctorOperations.h"
#include "constants.h"
#include <fstream>

//Returns the index value of the Doctor or none if it doesnt exist
int getDoctorIndex(Doctor doctors[], int numberofDoctor, string doctorName){

   for (int i = 0; i < numberofDoctor; i++){

      if (doctors[i].getName() == doctorName){


         return i;
      }
   }

   return 0;
}

//Checks if the Doctor exists or not
bool isDoctorExist(Doctor doctors[], int numberofDoctor, string doctorName){

   bool flag = false;

   for (int i = 0; i < numberofDoctor; i++){

      if (doctors[i].getName() == doctorName){

         flag = true;

      }
   }

   return flag;
}

//Loads Doctor information from the file
int loadDoctor(Doctor doctors[]){

   ifstream input(DOCTOR_FILE);
   int i = 0;

   while (!input.eof()){

      input >> doctors[i];
      i++;

   }

   input.close();

   return i;
}

//Stores Doctor information to the file
void storeDoctor(Doctor doctors[], int numberOfDoctor){

   ofstream output(DOCTOR_FILE);
   for (int i = 0; i < numberOfDoctor; i++){

      if (i != 0)
         output << endl;
      output << doctors[i];

   }

   output.close();
}
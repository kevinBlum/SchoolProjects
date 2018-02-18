#include "header.h"
#include "doctor.h"
#include "patient.h"
#include "doctorOperations.h"
#include "patientOperations.h"

int main(){

   int menuInput = 0,
   numberOfDoctors = 0;

   Doctor doctors[NUM_OF_DOCTOR];
   Patient patients[NUM_OF_PATIENT][NUM_OF_DOCTOR];

   numberOfDoctors = loadDoctor(doctors);
   loadPatient(patients, doctors, numberOfDoctors);

   //do while statement from the main menu to select which function to invoke


   do{

      menuInput = menu();


      if (menuInput == ADD){

         addPatient(patients, doctors, numberOfDoctors);

      }

      else if (menuInput == REMOVE){

         removePatient(patients, doctors, numberOfDoctors);

      }

      else if (menuInput == SEARCH){

         searchPatient(patients, doctors, numberOfDoctors);

      }

      else if (menuInput == UPDATE){

         updatePatientName(patients, doctors, numberOfDoctors);

      }

   } while (menuInput != EXIT);

   storePatient(patients, doctors, numberOfDoctors);
   storeDoctor(doctors, numberOfDoctors);

   return 0;
}
#include "patientOperations.h"
#include "generalOperations.h"
#include <iostream>
#include <fstream>


//Functions takes user input and creates a new patient and adds it to the array as long as the information is valid
void addPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctor){

   clearScreen();

   string name = "",
   id = "",
   address = "",
   doctorName = "",
   phoneNumber = "";

   cin.ignore();
   cout << "Name: " << endl;
   getline(cin, name);

   cout << endl << "Id: " << endl;
   getline(cin, id);

   cout << endl << "Address: " << endl;
   getline(cin, address);

   cout << endl << "Doctor's Name: " << endl;
   getline(cin, doctorName);

   cout << endl << "Phone Number: " << endl;
   getline(cin, phoneNumber);

   bool canAdd = false;
   int doctorIndex = -1;

   for (int i = 0; i < numberOfDoctor; i++){

      if (doctors[i].getName() == doctorName){

         canAdd = true;
         doctorIndex = i;
      }
   }

   for (int i = 0; i < NUM_OF_PATIENT; i++){

      for (int j = 0; j < numberOfDoctor; j++){

         if (id == patients[i][j].getId()){

            canAdd = false;

         }
      }
   }

   if (doctors[doctorIndex].getName() == doctorName && doctors[doctorIndex].getNumberOfPatients() == NUM_OF_PATIENT + 1){

      canAdd = false;

   }

   if (canAdd == true){

      for (int i = 0; i < NUM_OF_PATIENT; i++){

         if (patients[i][doctorIndex].getId() == ""){

            cout << "Patient was created" << endl;

            patients[i][doctorIndex].setAddress(address);
            patients[i][doctorIndex].setDoctorId(doctors[doctorIndex].getId());
            patients[i][doctorIndex].setId(id);
            patients[i][doctorIndex].setName(name);
            patients[i][doctorIndex].setPhoneNumber(phoneNumber);
            doctors[doctorIndex].setNumberOfPatients(doctors[doctorIndex].getNumberOfPatients() + 1);

            i = NUM_OF_PATIENT;

         }
      }
   }
   else{

      cout << "Patient was not created" << endl;

   }

   pause();

}

//Returns patient and corresponding doctor indexes
void getPatientIndex(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor, string patientId, int &patientIndex, int &doctorIndex){

   for (int i = 0; i < NUM_OF_PATIENT; i++){

      for (int j = 0; j < numberofDoctor; j++){

         if (patients[i][j].getId() == patientId){

            patientIndex = i;
            doctorIndex = j;

         }
      }
   }
}

//Verifies that the patient exists based on ID and returns true or false
bool isPatientExist(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor, string id){

   bool flag = false;

   for (int i = 0; i < NUM_OF_PATIENT; i++){

      for (int j = 0; j < numberofDoctor; j++){

         if (patients[i][j].getId() == id){

            flag = true;

         }
      }
   }

   return flag;
}


//Loads patient information
void loadPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor){

   for (int i = 0; i < numberofDoctor; i++){

      string fileName = doctors[i].getId() + ".txt";
      ifstream input(fileName);
      int j = 0;

      while (!input.eof() && doctors[i].getNumberOfPatients() != 0){

         input >> patients[j][i];
         j++;
      }

      input.close();
   }
}

//Removes patient from array given a patient ID
void removePatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor){

   clearScreen();

   string id = "";
   bool flag = false;

   cout << "Enter a patient's ID: " << endl;
   cin >> id;

   for (int i = 0; i < NUM_OF_PATIENT; i++){

      for (int j = 0; j < numberofDoctor; j++){

         if (patients[i][j].getId() == id){

            flag = true;

            patients[i][j].setAddress("");
            patients[i][j].setDoctorId("");
            patients[i][j].setId("");
            patients[i][j].setName("");
            patients[i][j].setPhoneNumber("");
            cout << "Deleted" << endl;
            doctors[j].setNumberOfPatients(doctors[j].getNumberOfPatients() - 1);

         }
      }
   }

   if (flag == false){

      cout << "Patient ID doesn't exist" << endl;

   }

   pause();
}

//Searches for a patient using patient ID and outputs patient info if true
void searchPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor){

   clearScreen();

   string id = "";
   bool flag = false;

   cout << "Enter patient's ID: " << endl;
   cin >> id;

   for (int i = 0; i < NUM_OF_PATIENT; i++){

      for (int j = 0; j < numberofDoctor; j++){

         if (patients[i][j].getId() == id){

            cout << patients[i][j].getName() << endl << patients[i][j].getId() << endl << patients[i][j].getAddress() << endl << patients[i][j].getPhoneNumber() << endl << doctors[j].getName() << endl;
            flag = true;

         }
      }
   }

   if (flag == false){

      cout << "Patient doesn't exist" << endl;

   }

   pause();
}

//Stores patient information
void storePatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor){

   for (int j = 0; j < numberofDoctor; j++){

      string fileName = doctors[j].getId() + ".txt";
      ofstream output(fileName);

      for (int i = 0; i < NUM_OF_PATIENT; i++){

         if (i != 0){
            output << endl;
         }

         output << patients[i][j];
      }

      output.close();
   }
}

//Updates patient information
void updatePatientName(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor){

   clearScreen();

   string id = "";
   bool flag = false;

   cout << "Enter a patient's ID: " << endl;
   cin >> id;

   for (int i = 0; i < NUM_OF_PATIENT; i++){

      for (int j = 0; j < numberofDoctor; j++){

         if (patients[i][j].getId() == id){

            string name;

            cout << "Enter Patient's New Name: " << endl;
            cin.ignore();
            getline(cin, name);
            patients[i][j].setName(name);
            cout << "Name has been changed" << endl;

            flag = true;

         }
      }
   }

   if (flag == false){

      cout << "Patient doesn't exist" << endl;

   }

   pause();
}
/*
Author:  Celeborn
Class : 281-05
Assignment : Assignment #1
Date Assigned : 8/31/15
Due Date : 9/7/15

Description : The purpose of the program is to keep track of patient and doctor information for a clinic. The program is supposed to add new patients, search and remove for existing patients using
arrays for the patients and doctors with the use of text files.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#ifndef PatOp
#define PatOp

#include "patient.h"
#include "doctor.h"
#include "constants.h"

//Function prototypes for the patient class functions

void addPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctor);

void getPatientIndex(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor, string patientId, int &patientIndex, int &doctorIndex);

bool isPatientExist(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor, string id);

void loadPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor);

void removePatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor);

void searchPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor);

void storePatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor);

void updatePatientName(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberofDoctor);

#endif

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

#ifndef Pat
#define Pat

#include "person.h"

//Patient class

class Patient{

private:

   //Private members of patient class
   Person mPatient;
   string mAddress;
   string mDoctorId;
   string mPhoneNumber;

public:

   //Constructors
   Patient();
   Patient(string mDoctorId, string mName, string mId, string mAddress, string mPhoneNumber);
   ~Patient();

   //Accessor functions
   string getAddress(){ return mAddress; };
   string getDoctorId(){ return mDoctorId; };
   string getId(){ return mPatient.mId; };
   string getName(){ return mPatient.mName; };
   string getPhoneNumber(){ return mPhoneNumber; };

   //Mutator functions
   void setAddress(string newAddress);
   void setDoctorId(string newDoctorId);
   void setId(string newId);
   void setName(string newName);
   void setPhoneNumber(string newPhoneNumber);

   //Overloaded functions for the input and output streams and equal to operator
   friend ostream& operator<<(ostream& fout, Patient& pat);
   friend istream& operator>>(istream& fin, Patient& pat);
   bool Patient::operator==(const Patient &rhs) const;
};

#endif
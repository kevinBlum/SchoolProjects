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

#ifndef Doc
#define Doc

#include "person.h"

//Doctor class

class Doctor{

private:

   //Private members of the doctor class
   Person mDoctor;
   int mIndex;
   int mNumberOfPatients;

public:

   //Constructors
   Doctor();
   Doctor(string name, string id);
   ~Doctor();

   //Accessor functions
   string getId(){ return mDoctor.mId; };
   int getIndex(){ return mIndex; };
   string getName(){ return mDoctor.mName; };
   int getNumberOfPatients(){ return mNumberOfPatients; };

   //Mutator functions
   void setId(string newId);
   void setIndex(int newIndex);
   void setName(string newName);
   void setNumberOfPatients(int newNumberOfPatients);

   //Overloaded functions for the input and output streams and equal to operator
   friend ostream& Doctor::operator<<(ostream& fout, Doctor& doc);
   friend istream& operator>>(istream& fin, Doctor& doc);
   bool Doctor::operator==(const Doctor &rhs) const;
};

#endif

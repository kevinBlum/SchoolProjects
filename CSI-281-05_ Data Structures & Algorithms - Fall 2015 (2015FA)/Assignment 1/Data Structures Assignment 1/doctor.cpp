#include "doctor.h"

//Function implementations for doctor class and functions


//Default Constructor
Doctor::Doctor(){

   mDoctor.mName = "";
   mDoctor.mId = "";
   mIndex = 0;
   mNumberOfPatients = 0;

}

//Constructor
Doctor::Doctor(string name, string id){

   mDoctor.mName = name;
   mDoctor.mId = id;
   mIndex = 0;
   mNumberOfPatients = 0;

}

//Deconstructor
Doctor::~Doctor(){

   mDoctor.mName = "";
   mDoctor.mId = "";
   mIndex = 0;
   mNumberOfPatients = 0;

}

//Mutators for doctor class members

void Doctor::setId(string newId){

   mDoctor.mId = newId;

}

void Doctor::setIndex(int newIndex){

   mIndex = newIndex;

}

void Doctor::setName(string newName){

   mDoctor.mName = newName;

}

void Doctor::setNumberOfPatients(int newNumberOfPatients){

   mNumberOfPatients = newNumberOfPatients;

}

//Overloaded functions for input and output streams to input and output data

ostream& operator<<(ostream& fout, Doctor& doc){

   fout << doc.getName() << endl << doc.getId() << endl << doc.getIndex() << " " << doc.getNumberOfPatients();

   return fout;

}

istream& operator>>(istream& fin, Doctor& doc){

   std::string name = "",
      id = "";

   int index;
   int numberOfPatients;

   getline(fin, name);
   getline(fin, id);

   fin >> index >> numberOfPatients;
   fin.ignore();
   doc.setName(name);
   doc.setId(id);
   doc.setNumberOfPatients(numberOfPatients);
   doc.setIndex(index);

   return fin;

}

//Overloaded equal to operator comparing the names of doctors and returning true if they match
bool Doctor::operator==(const Doctor &rhs) const{

   bool flag = false;

   if (mDoctor.mName == rhs.mDoctor.mName){

      flag = true;

   }

   return flag;

}
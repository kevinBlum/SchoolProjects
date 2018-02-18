#include "patient.h"

//Function implementations for doctor class and functions

//Default Constructor
Patient::Patient(){

   mPatient.mName = "";
   mPatient.mId = "";
   mAddress = "";
   mDoctorId = "";
   mPhoneNumber = "";

}

//Constructor
Patient::Patient(string doctorId, string name, string id, string address, string phoneNumber){

   mPatient.mName = name;
   mPatient.mId = id;
   mAddress = address;
   mDoctorId = doctorId;
   mPhoneNumber = phoneNumber;

}

//Deconstructor
Patient::~Patient(){

   mPatient.mName = "";
   mPatient.mId = "";
   mAddress = "";
   mDoctorId = "";
   mPhoneNumber = "";

}

//Mutator funtions for the patient class members

void Patient::setAddress(std::string newAddress){

   mAddress = newAddress;

}

void Patient::setDoctorId(std::string newDoctorId){

   mDoctorId = newDoctorId;

}

void Patient::setId(std::string newId){

   mPatient.mId = newId;

}

void Patient::setName(std::string newName){

   mPatient.mName = newName;

}

void Patient::setPhoneNumber(std::string newPhoneNumber){

   mPhoneNumber = newPhoneNumber;

}

//Overloaded functions for input and output streams to input and output data

ostream& operator<<(std::ostream& fout, Patient& pat){

   fout << pat.getName() << endl << pat.getId() << endl << pat.getAddress() << endl << pat.getPhoneNumber() << endl << pat.getDoctorId();

   return fout;
}

istream& operator>>(istream& fin, Patient& pat){

   string name = "",
      id = "",
      address = "",
      phoneNumber = "",
      doctorId = "";

   getline(fin, name);
   getline(fin, id);
   getline(fin, address);
   getline(fin, phoneNumber);
   getline(fin, doctorId);
   pat.setName(name);
   pat.setId(id);
   pat.setAddress(address);
   pat.setPhoneNumber(phoneNumber);
   pat.setDoctorId(doctorId);

   return fin;

}

//Overloaded equal to operator comparing the ID of patients and returning true if they match
bool Patient::operator==(const Patient &rhs) const{

   bool flag = false;

   if (mPatient.mId == rhs.mPatient.mId){

      flag = true;

   }

   return flag;
}
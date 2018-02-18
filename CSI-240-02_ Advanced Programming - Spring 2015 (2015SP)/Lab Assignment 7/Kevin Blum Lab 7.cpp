/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Lab 7
Date Assigned : 3/23/15
Due Date : 3/30/15
Description : The purpose of the program is to demonstrate class inheritance by creating class objects using derived and base class constructors with mutators and accessors

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/


#include <iostream>
#include <string>

using namespace std;

enum Discipline {
   COMPUTER_SCIENCE, UNKNOWN
};

const string DISCIPLINE_STRINGS[2] = { "Computer Science",
   "Unknown",
};

//Superclass that contains the name of the person object, default and alternate constructors and mutators and accesors for name.
class Person{

public:


   //mutator and accessor for name
   string getName() const { return pName; };
   void setName(string name) {pName = name;}

   //default constructor
   Person()
   {
      pName = "";
      cout << "Person Object created using default constructor" << endl;
   };

   //alternator constructor
   Person(string name, Discipline)
   {
      setName(name);
   };

   //destructor
   ~Person()
   {
      cout << "Person object destroyed" << endl;
      system("pause");
   };

private: 

   string pName;


};

//derived class containing the enum Discipline, default and alternate constructors, and mutators and accessors for the major
class Student : public Person {

public:

   //mutator and accessor for major
   string getMajor() const { return stringMajor;};
   void setMajor(Discipline Major) {
     stringMajor = DISCIPLINE_STRINGS[Major]; 
   };

   //default constructor
   Student(){};

   //alternate constructor
   Student(string name, Discipline Major)
   {
      Person::setName(name);
      setMajor(Major);
      cout << "Student Object Created using Alternate constructor" << endl;
   }

   //destructor
   ~Student()
   {
      cout << "Student object destroyed" << endl;
   };

private:

   Discipline Major;
   string stringMajor;

};

//derived class containing the enum Discipline, default and alternate constructors, and mutators and accessors for the department
class Faculty : public Person {

public:

   //mutator and accessor for the department
   string getDepartment() const { return stringDepartment;};
   void setDepartment(Discipline Department) 
   {
      stringDepartment = DISCIPLINE_STRINGS[Department];
   };

   //default constructor
   Faculty(){};

   //alternate constructor
   Faculty(string name, Discipline Department)
   {
      Person::setName(name);
      setDepartment(Department);
      cout << "Faculty Object Created using Alternate constructor" << endl;
   };

   //destructor
   ~Faculty()
   {
      cout << "Faculty object destroyed" << endl;
   };

private:

   Discipline Department;
   string stringDepartment;

};


int main()
{
   
   Faculty prof("Brian Hall", COMPUTER_SCIENCE);
   Student stu("Kevin Blum", COMPUTER_SCIENCE);

   cout << endl << "I, " << stu.getName() << ", am majoring in " << stu.getMajor() << "." << endl;
   cout << "I am taking CSI 240 with Prof. " << prof.getName() << ", who teaches "
        << prof.getDepartment() << " courses." << endl << endl;
   
   return 0;
}
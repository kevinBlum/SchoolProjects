/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Final Project
Date Assigned : 4/16/15
Due Date : 4/24/15
Description : The purpose of the program is to create a mock computer builder that presents the user with options to build desktops or laptops that are meant for casual or gaming use and to decide based
on price the quality of the computers, dimension or size, and the graphics card if meant for a gaming PC and outputs the potential price of said computer.
It utilizies two different class hierarchies with polymorphism to create the computer objects
and operator overloading to add information or clear a log file to keep track of information deemed important by the user.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
- Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//base class
class CompStyle{

public:
   //pure virtual function
   virtual void getDescription()=0;
   friend class Iteration;

}; 

//derived class of CompStyle
class Gaming : public CompStyle{

public:
   
   string quality;
   string graphicsCard;
   string name;
   virtual void getDescription();
   Gaming();
   Gaming(string name);
   ~Gaming(){};


};

//derived class of CompStyle
class Casual : public CompStyle{

public:

   string quality;
   string name;
   virtual void getDescription();
   Casual();
   Casual(string name);
   ~Casual(){};

};

//abstract base class
class CompShape{

   public:
      virtual void callShape()=0;
      friend class Iteration;

};

//derived class of CompShape
class Desktop : public CompShape{

   public:
      string name;
      virtual void callShape();
      void buildDesktop(Desktop*);
      Desktop();
      ~Desktop(){};
   private:
      string pSize;
};

//derived class of CompShape
class Laptop : public CompShape{

   public:   
      string name;
      virtual void callShape();
      void buildLaptop(Laptop*);
      Laptop();
      ~Laptop(){};

   private:
      double pSize;

};

//friend class compStyle
class Iteration{

   public:
      //variable to keep track of number of computers created in the session
      static int computersCreated;
      Iteration(){};
      ~Iteration(){};

      //operator overloading functions to alter the log file
      friend ostream &operator<<(ostream& output, Iteration& newIter);
      Iteration operator+(Iteration&);

};


/*
main.cpp
lab3

Author:  Kevin Blum
Class:   240-02
Assignment:  Programming Assignment One
Date Assigned: 1/22/14
Due Date: 1/28/14

Description:   The purpose of the program is to read in information about books from a text file then organize the information such as the name, type, page, weight and reviews for each book
using a class and number of functions then format the information and output the formatted information.

Certification of Authenticity:  I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or -
Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking


Created by Brian R. Hall on 1/8/14.
Copyright (c) 2014 Brian R. Hall. All rights reserved.
*/

#ifndef __lab3__book__
#define __lab3__book__

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

enum Type
{
	UNKNOWN = -1,
   PAPERBACK,
	HARDBACK
};

const string TYPE_WORDS[] = { "Paperback", "Hardback" };

const int arraySize = 5;

class Book
{
public:
	//default constructor - not actually used but should be implemented anyway
	Book();
	//constructor
   Book(const string& name, Type type, int pages, float ounces, string reviewFile);
	//destructor
	~Book(){};
   
   float getWeightLbs();  //calculate and return the weight of the book in lbs
   string getTypeName();  //return the string which correlates with the book type
   string formatReportLine();  //return a string with all the info for the book
   void addReviews(); //reads the passed in reviews file and adds review data to the book 
   float calculateAverageReview();  //calculate the average of the reviews
   int getMostFrequentReview();  //get the review (number of stars) with the highest count 
   
   const int size = 5;
   int reviewsArray[arraySize];

   
	//accessors
	string getName(){ return bName; };
	Type getType(){ return bType; };
	int getPages(){ return bPages; };
	float getOunces(){ return bOunces; };
   string getFileName() {return bFile; };
   
private:
	string bName;  //name of the book
	Type bType;  //the type of book (Type is an enumerated type)
	int bPages;  //how many pages the book contains
	float bOunces;  //how much the book weighs in ounces
   string bFile;
};


#endif /* defined(__lab3__book__) */

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

#include <iostream>
#include <fstream>
#include <string>
#include "book.h"

using namespace std;



int main()
{
	const string FILENAME("books.txt");
   
	ifstream input(FILENAME);


	if( input.good() )
	{
		while( !input.eof() )
		{
			string name;
			int typeNum;
			int pages;
			float ounces;
         string reviewFile = " ";
         string output = " ";
			getline( input, name );
			input >> typeNum >> pages >> ounces >> reviewFile;
			input.ignore(INT_MAX, '\n');  
         
         Type type = static_cast<Type>(typeNum);

         Book NewBook(name, static_cast<Type>(typeNum), pages, ounces, reviewFile);
			
         NewBook.addReviews();
         output = NewBook.formatReportLine();
         cout << output;

     			        
		}
	}
	else
	{
		cout << "File not found: " << FILENAME << endl;
	}
   system("pause");
	return 0;
}
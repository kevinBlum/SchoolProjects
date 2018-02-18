/*
Author:  Kevin Blum
Class : 240 - 02
Assignment : Lab 1
Date Assigned : 1 / 14 / 15
Due Date : 1 / 19 / 15

Description : The purpose of the program is to read in information of programmers from a text file to load into a struct of id's, names and lines of code written. There are multiple functions
the first of which loads in the data from the text file into the struct, then counts up the total number of programmers, the next sums up the total lines of code written among the programmers
and the following averages out the lines of code written. The final function displays all the information of each programmer.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or -
Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking

*/


#include "programmer.h"

//implement function here!

//returns the number of programmers - fills in the programmers array from the ifstream
int readProgrammers( ifstream& inputFile, Programmer programmers[], int maxProgrammers )
{
   int num = 0;
   string names = " ";
   int code = 0;
   int count = 0;
   for (int i = 0; i < maxProgrammers; i++){
      inputFile >> num >> names >> code;
      programmers[i].programmer_id = num;
      programmers[i].name = names;
      programmers[i].lines = code;
      count += 1;
   }

   
	return count;
}

//returns the total of the lines field for all programmers
int calcTotalLines( Programmer programmers[], int numProgrammers )
{  
   int sum = 0;
   
   for (int i = 0; i < numProgrammers; i++){
      sum += programmers[i].lines;

   }
	return sum;
}

//returns the average lines coded for all programmers as a float
float calcAverageLines( Programmer programmers[], int numProgrammers )
{
   int count = 0;
   int sum = 0;
   float average = 0;
   
   for (int i = 0; i < numProgrammers; i++){
      sum += programmers[i].lines;
      count += 1;
   }
   average = sum / count;

	return average;
}


//generate report for all programmers
//call calcTotalLines, calcAverageLines, and generateProgrammerInfo functions
void generateProgrammerReport( ostream& output, Programmer programmers[], int numProgrammers )
{
	//just a stub!
	output << "These are all the programmers: ";
   
	for( int i = 0; i < numProgrammers; i++ )
	{
		output << "\nProgrammer info "; //this should output the programmer info for each programmer
      output << programmers[i].programmer_id << " " << programmers[i].name << " " << programmers[i].lines;
	}
   
   output << "\nTotal lines = " << calcTotalLines(programmers, numProgrammers); //this should ouptut the total lines
   output << "\nAverage lines = " << calcAverageLines(programmers, numProgrammers); //this should output the average lines
	output << endl;
}
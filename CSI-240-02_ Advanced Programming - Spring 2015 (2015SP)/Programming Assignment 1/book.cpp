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

#include "book.h"

//Default Constructor
Book::Book(){

   bName = " ";
   bType = UNKNOWN;
   bPages = 0;
   bOunces = 0.0f;
   bFile = " ";

}

//Constructor with the parameters from the text file
Book::Book(const string& name, Type type, int pages, float ounces, string reviewFile){
   
   bName = name;
   bType = type;
   bPages = pages;
   bOunces = ounces;
   bFile = reviewFile;
   

}

//Function to convert the weight of the book from ounces to pounds
float Book::getWeightLbs(){

   bOunces = bOunces / 16;

   return bOunces;
}

//Function to convert the enum Type into the string name for the type
string Book::getTypeName(){

   string str = " ";

   if (bType == PAPERBACK)
      str = "Paperback";
   else if (bType == HARDBACK)
      str = "Hardcover";

   return str;
}

//Function to use the file stream and input the review numbers from each book file and fill the array with the review values
void Book::addReviews(){
    
   ifstream fin(bFile);
   int reviewScore = 0;

   for (int i = 0; i < size; i++){

      fin >> reviewScore;
      reviewsArray[i] = reviewScore;

   }
 
}

//Function that calculates the average review number from the array of reviews
float Book::calculateAverageReview(){

   float averageReview = 0.0; 
   float count = 0.0;

   for (int i = 0; i < size; i++){
      
      averageReview += reviewsArray[i];
      count = count + (reviewsArray[i] * (5-i));
      
   }
   
   averageReview = count / averageReview;

   return averageReview;
}

//Function that calculates the most frequent review number from the array of reviews
int  Book::getMostFrequentReview(){

   int mostFrequent = 0;
   int reviewNum = 0;
   int comparisonReviewNum = 0;

   for (int i = 0; i < size; i++){

      reviewNum = reviewsArray[i];
         if (reviewNum > comparisonReviewNum){
            mostFrequent = (5-i);
         }
         comparisonReviewNum = reviewNum;

   }

   return mostFrequent;
}


//Function that takes all boook information and formats it into stringstream and returns the stream
string Book::formatReportLine(){
   stringstream ss;
   string str = " ";
   float pounds = getWeightLbs();
   string stringType = getTypeName();
   float avgReview = calculateAverageReview();
   int frequentReview = getMostFrequentReview();

   ss << bName << " | Type: " << stringType << " Pages: " << bPages << " Weight(lbs): " << pounds << endl << "Reviews | Average Stars: " << avgReview << " Most Frequent Review: " << frequentReview << endl;

   return ss.str();
}


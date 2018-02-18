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

#ifndef CONST_H
#define CONST_H

#include <iostream>
#include <string>

using namespace std;

const int NUM_OF_DOCTOR = 5, NUM_OF_PATIENT = 10, NUM_OF_DAYS = 5, NUM_OF_TIME_SLOT = 28;
const string FILE_EXT = ".txt";
const string DOCTOR_FILE = "doctors.txt", SCHEDULE_FILE = "schedule.txt";
const int SPACE = 25;
const int TIME_SPACE = 15;

enum MENU_OP { ADD = 1, REMOVE, SEARCH, UPDATE, EXIT };
enum SCHEDULER_OP { VIEW_SCHEDULE = 1, ADD_APP, REMOVE_APP, CHANGE_APP, EXIT_SCHEDULE };

const string DAYS[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY" };

const string TIME_SLOT[] = { "09:00 - 09:15", "09:15 - 09:30", "09:30 - 09:45", "09:45 - 10:00",
"10:00 - 10:15", "10:15 - 10:30", "10:30 - 10:45", "10:45 - 11:00",
"11:00 - 11:15", "11:15 - 11:30", "11:30 - 11:45", "11:45 - 12:00",
"13:00 - 13:15", "13:15 - 13:30", "13:30 - 13:45", "13:45 - 14:00",
"14:00 - 14:15", "14:15 - 14:30", "14:30 - 14:45", "14:45 - 15:00",
"15:00 - 15:15", "15:15 - 15:30", "15:30 - 15:45", "15:45 - 16:00",
"16:00 - 16:15", "16:15 - 16:30", "16:30 - 16:45", "16:45 - 17:00" };

#endif
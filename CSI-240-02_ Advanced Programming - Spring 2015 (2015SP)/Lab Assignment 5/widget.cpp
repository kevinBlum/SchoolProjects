/*

Name: Kevin Blum
Assignment: Lab 5
Class: CSI-240-02
Date Assigned: 2/9/14
Date Due: 2/12/15

Description: The Purpose of this program is to create widget objects using the widget class, creating the first three 
objects using the parametrical constructor and then creating the last three with the copy constructor. The widgets are
created using class functions, static member variables and the this pointer.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. 
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment: 
- Reproduce this assignment and provide a copy to another member ofacademic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this 
assignment on its database for the purpose of future plagiarism checking)

*/

#include "widget.h"

int Widget::count = 0;

Widget::Widget(WidgetType type){
   
   wType = type;
   count += 1;
   wID = count;
   generateModelName();
   

}

Widget::Widget(const Widget& rhs){

   this->wType = rhs.wType;
   count += 1;
   wID = count;
   generateModelName();
   

}

void Widget::generateModelName(){
   
   stringstream ss;

   switch (wType){
      case 0: 
         wModelName = WIDGET_NAMES[wType];
      case 1:
         wModelName = WIDGET_NAMES[wType];
      case 2:
         wModelName = WIDGET_NAMES[wType];
   }
 
   ss << wModelName << " " << wID << " " << this;
   wModelName = ss.str();
}


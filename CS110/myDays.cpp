//Objective: Calculates my age in days
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  // introduction
  cout << "Objective: This program outputs my age in days\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  //my age in days
  int days;
  //due date;
  string dueDate = "June 22, 2017";
  //date of birth
  string dateOfBirth = "June 17, 1999";

  //Calculations
  days = 365 * 19;
  days = days + 5;
  days = days - 168;
  days = days - 192;

  //Output of date of birth, due date, and my birthday
  cout << "DOB: " << dateOfBirth << endl;
  cout << "Due: " << dueDate << endl;
  cout << "My birthday is days: " << days << endl;

}//main
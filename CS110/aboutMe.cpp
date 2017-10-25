//Objective: About me
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <string>
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
  cout << "Objective: This program will display information about me\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  //my favorite number
  int luckyNumber = 4; 
  //how much money I want to save for the rest of my life
  double amountEarned = 100000.00;
  //my favorite movie
  string movie = "Gone Girl";
  //my initial
  char initial = 'E';

  //output data
  cout << "My favorite number: " << luckyNumber << endl; 
  cout << "How much money I want to save for the rest of my life: " << amountEarned << endl; 
  cout << "My favorite movie: " << movie << endl; 
  cout << "My initial: " << initial << endl; 

}//main
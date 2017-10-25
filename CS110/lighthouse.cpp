//Objective: Determines how far away a boat can see a lighthouse at sea. 
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
#include <iostream>
using namespace std;

#include <cmath>

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
  cout << "Objective: This program determines how far away a boat can see a lighthouse at sea. \n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //DATA
  double height; // the lighthouse's height (in feet) (decimal) (positive)
  int distance; // the distance of how far away a boat can see the lighthouse (in miles) (decimal)

  //Get user's height
  cout << "What's the lighthouse height in feet (decimal) (positive) ('EXIT' to END)? ";
  cin >> height;
  cin.ignore(1000, 10);

  //Calculate the distance of how far away a boat can see the lighthouse
  distance = sqrt(.894427191 * height);

  //Output the distance of how far away a boat can see the lighthouse
  cout << "A " << height << " foot tall lighthouse can be seen from " << distance << " miles away";
  
}
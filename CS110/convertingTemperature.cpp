//Objective: Converting Fahrenheit To Celsius
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
  cout << "Objective: Converting Fahrenheit To Celsius\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  // degrees Celsius 
  double c; 
  // degrees Fahrenheit
  double f; 

  //Get user to enter Fahrenheit 
  cout << "Enter the temperature in degrees Fahrenheit: "; 
  cin >> f; 

  //Converting Fahrenheit input to Celsius
  c = 5 * (f - 32) / 9; 
  
  //output results
  cout << " That's " << c << " degrees Celsius!" << endl; 

}//main
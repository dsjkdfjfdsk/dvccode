//Objective: Calculating The Area Of A Circle
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> 
#include <cmath> 
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
  cout << "Objective: Calculating The Area Of A Circle\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  double r; 
  double area; 
  // 4 times the angle whose tangent is 1
  double pi = 4 * atan(1.0); 

  //Get user to enter a circle's radius 
  cout << "Enter the radius of a circle: "; 
  cin >> r; 

  //Calculate area of circle
  area = pi * r * r; 
  
  //output results
  cout << " The area is " << area << endl; 

}//main
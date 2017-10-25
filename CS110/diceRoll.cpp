//Objective: Simulate dice roll.
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> 
#include <cstdlib> 
#include <ctime> 
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
  // initialize the random number generator
  srand(time(0)); 
  rand(); 

  // introduction
  cout << "Objective: This program simulates a dice roll.\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  // the name of the first die
  int a;  
  // the name of the second die 
  int b; 
  // the result 
  int total; 

  //Simulate dice roll
  a = 1 + rand() % 6; 
  b = 1 + rand() % 6; 
  total = a + b; 
  
  //output results
  cout << "Dice result: " << total << " (" << a << " and " << b << ")" << endl; 

}//main
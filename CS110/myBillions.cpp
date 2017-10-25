//Objective: Calculates and outputs the number of weeks that it will take to reach a total of one billion dollars or greater if you double your amount after every week.
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //for output
#include <string>  //for using string built in functions
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //program introductions

//main program
int main()
{
  //Data
  string objective = "Calculates and outputs the number of weeks that it will take to reach a total of one billion dollars or greater if you double your amount after every week.";
  int amountStart; // amount of cents inputted by user
  double amount; // amount in dollars 
  int weeks = 0;

  //program introduction
  introduction(objective);

  //Get user input 
  cout << "How many cents to start off with (whole number) (positive)? ";
  cin >> amountStart;
  cin.ignore(1000,10);
  amount = amountStart / 100.0; //convert to dollars

  //Calculate how many weeks it will take
  while (amount < 1000.0)
  {
    amount = amount * 2.0;
    weeks += 1;
  } // while loop to check thousandaire
  cout << "In " << weeks << " weeks, I will be a thousandaire!" << endl;
  while (amount < 1000000.0)
  {
    amount = amount * 2.0;
    weeks += 1;
  } // while loop to check millionaire
  cout << "In " << weeks << " weeks, I will be a millionaire!" << endl;
  while (amount < 1000000000.0)
  {
    amount = amount * 2.0;
    weeks += 1;
  } // while loop to check billionaire
  cout << "In " << weeks << " weeks, I will be a billionaire!" << endl;
  
}//main

//program introduction
void introduction(string obj)
{
  //Data
  //obj = program objective

  // output my name and objective and program information
  cout << "Objective: This Program ";
  cout << obj << endl;
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
} //introduction
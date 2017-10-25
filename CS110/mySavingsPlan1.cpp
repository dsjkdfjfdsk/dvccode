//Objective: Calculate how much money to save every month for number of years before retirement and how much money would you have when you retire.
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
#include <iostream>
using namespace std;

#include <cmath> //exponent calculation

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
  cout << "Objective: Calculate how much money to save every month for number of years before retirement and how much money would you have when you retire. \n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  int deposit = 100; //my selected amount
  double interestRate = .075; //my selected annual interest rate
  int years = 10; //my selected amount of years
  double amountSaved; //how much money I will have when I retire
  int time; //number of months in years

  //Calculating interest rates
  interestRate = interestRate / 12;
  time = years * 12;
  amountSaved = deposit * ((pow(1 + interestRate, time) - 1) / interestRate);
  interestRate = (interestRate * 100) * 12;

  //Output years, rate, deposit, and amountSaved
  cout << "In " << years << " years at " << interestRate << "%, ";
  cout << "$" << deposit << " deposited per month ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << "will grow to $" << amountSaved << endl;

}//main
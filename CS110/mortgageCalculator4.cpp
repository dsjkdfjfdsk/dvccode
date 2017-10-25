//Objective: Collects all the mortgage data in a single item
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //for file output
#include <iomanip> //for formatting
#include <iostream> //for output
#include <string>  //for using string built in functions
using namespace std;

#include <cmath> //for power function

//Programmer defined data types
struct Mortgage
{ 
  int borrowed;
  double interest;
  double payback;
  double payment; 
}; //mortgage object

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//ALPHABETISIZE DON'T FORGET
void introduction(string obj); //program introductions
void setValues(Mortgage& m); //set mortgage values
bool passwordCheck(); //gives three tries for the user to inputu the correct password
void outputMortgage(Mortgage& m); //calculates and output results to file and console

//main program
int main()
{
  //Data
  string objective = "collects all the mortgage data in a single item";
  Mortgage m; //mortgage object
  m.payback = 30; //payment period

  //program introduction
  introduction(objective);

  if (passwordCheck())
  {
    setValues(m);
    outputMortgage(m);
  }
  else
  {
    cout << "You have tried the maximum amount of attempts." << endl;
  }
 
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

//Check if password is correct
bool passwordCheck()
{
  //Data
  int i = 0; //index for for loop
  string password = "1671366"; //correct password
  bool correctPassword = false;
  string userPassword; //user password
  for(i = 0; i < 3; i++)
  {
    cout << "Enter password (the password is = 1671366): ";
    getline(cin, userPassword);
    if(password == userPassword)
    {
      correctPassword = true;
      break;
    }
    else
    {
      cout << "Incorrect. Please Try Again." <<endl;
    }
  }

  return correctPassword;
}

//mortgage calculations
void setValues(Mortgage& m)
{
  //Data
  //m = mortgage object
  int borrowed; //amount borrowed (whole number) (positive)
  double interest;  //the monthly interest rate (decimal) (positive)
  m.payback = 30; //the number of monthly payments in the payback period (whole number) (positive)
  int i = 0;
  ifstream fin;
  string filename;

  //Get user input
  cout << "What's the text file (with .txt extension)? ";
  getline(cin, filename);

  fin.open(filename.c_str());
  if (!fin.good()) throw "I/O error"; 
  fin >> m.borrowed;
  fin.ignore(1000,10);
  fin >> m.interest;
  fin.ignore(1000,10);

  if(m.borrowed < 0)
  {
    cout << "Invalid borrowed value. Please fix it to a positive whole number and try again" << endl;
  }

  if(m.interest < 0)
  {
    cout << "Invalid interest value. Please fix it to a positive decimal number and try again" << endl;
  } 

  fin.close();
}

void outputMortgage(Mortgage& m)
{
  //Data
  //m = mortgage object
  double payment; //monthly payment
  ofstream fout; //file output
  double interestMonthly;
  double paybackMonthly  = 12 * 30;

  //calculate mortgage payment
  interestMonthly = m.interest / 1200;
  paybackMonthly = 12 * 30;
  m.payment = (m.borrowed * (pow(1 + interestMonthly, paybackMonthly)*interestMonthly)/((pow(1+interestMonthly,paybackMonthly))-1));
  
  //output results
  cout << "Amount borrowed " << m.borrowed << endl;
  cout << "Annual interest rate " << m.interest << endl;
  cout << "Payback period " << m.payback << " years" << endl;
  cout << "Monthly payment " << m.payment << endl;
  
  //add to output file mortgage.txt
  fout.open("mortgage.txt");
  if (!fout.good()) throw "I/O error"; 
  fout << m.borrowed << endl;
  fout << m.interest << endl;
  fout.setf( ios:: fixed | ios:: showpoint);
  fout << setprecision(2);
  fout << m.payback << endl;
  fout << m.payment << endl;
  fout.close();
}
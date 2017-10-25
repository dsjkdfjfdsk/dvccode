//Objective: Calculate a value in the "Fibonacci number" series
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //for output
#include <string>  //for using string built in functions
using namespace std;

//Programmer defined data types

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
int getFibonacci(int index); //get the fibonacci number based on index
void introduction(string obj, string instructions, string example); //program introductions

//main program
int main()
{
  //Data
  string objective = "calculates a value in the Fibonacci number series"; //objective for intro
  string instructions = "Fibonacci numbers are the numbers in the following integer sequence and characterized by the fact that every number after the first two is the sum of the two preceding ones."; //instructions of what a fibonacci cnumber is
  string example = "For example, here are the first 5 fibonacci numbers: 0, 1, 1, 2, 3. Index 3 would be 2."; //example of fibonacci numbers
  int numberSequence; //the index for fibonacci number
  int fib; //the fibonacci number correseponding to the numberSequence index

  //program introduction
  introduction(objective, instructions, example);

  //get user input for index of fibonacci number
  do
  {
    cout << "Enter an index [0 or greater]: ";
    cin >> numberSequence;
    cin.ignore(1000,10);
    if(numberSequence < 0)
    {
      cout << "Invalid number. Please try again with a number 0 or greater." << endl;
    }
  } while(numberSequence < 0);

  //calculate fib number
  fib = getFibonacci(numberSequence);

  //output results
  cout << "The Fibonacci number at index " << numberSequence << " is " << fib << endl;

}//main

//program introduction
void introduction(string obj, string instructions, string example)
{
  //Data
  //obj = program objective
  //instructions = fibonacci number explanation. 
  //example = fibonacci example

  // output my name and objective and program information
  cout << "Objective: This Program ";
  cout << obj << endl;
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << instructions << endl;
  cout << example << endl << endl;
} //introduction

//get fibonacci number
int getFibonacci(int index)
{
  //Data
  //index = index of the corresponding fibonacci number 

  //if user types in 0 for fib number
  if (index == 0)
  {
    return 0;
  } //if

  //base case for second index which is the third fib number which is 1. recurse otherwise
  if (index <= 2)
  {
    return 1;
  }
  else
  {
    return getFibonacci(index - 1) + getFibonacci(index - 2);
  } //if else
}
//Objective: User guesses a number between 1 and 10 and see if it's correct
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <cstdlib> 
#include <ctime>
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
  cout << "Objective: This program makes user guess a number between 1 and 10 and see if it's correct\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  int guess; //the user's guess (whole number) (1-10)
  srand(time(0));  
  rand(); 
  int number = rand() % 10 + 1; //the correct number which is randomly generated (whole number) (1-10)
  
  //Get user input for the guess
  while(true)
  {
    cout << "What is your guess [1-10] (whole number): ";
    cin >> guess;
    cin.ignore(1000, 10);
    if (guess < 1 || guess > 10) 
    {
      cout << "I really want a number between 1 and 10" << endl; 
    }
    else if (guess == number)
    {
      cout << "You guessed it. Congrats!" << endl;
      break;
    } 
    else
    {
      cout << "Try again..." << endl;
    } // if statement that validates user input and compares user input to the random number
  } //While loop that allows user to keep on guessing
  
}//main
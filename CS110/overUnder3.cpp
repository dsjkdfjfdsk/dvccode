//Objective: User guesses a number between 1 and 10 and sees if it's correct. The program stores guesses in a list and checks if it's been asked before
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <cstdlib> //for random number generator
#include <ctime> //for time
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
int addValidateGuesses(int userGuesses[], int nSize); //validate if the guesses are valid
void introduction(string obj); //program introductions
bool outputResult(int guess, int correct); //output results

//main program
int main()
{
  //"seed" random generator
  srand(time(0));  
  rand(); 

  //Data
  string objective = "User guesses a number between 1 and 10 and sees if it's correct. The program stores guesses in a list and checks if it's been asked before";
  int guess;
  const int MAX_GUESSES = 100;
  int userGuesses[MAX_GUESSES];
  bool left; //if user quits
  int correct = rand() % 100 + 1;//the correct number which is randomly generated (whole number) (1-100)
  bool won = false;
  int nGuesses = 0;

  //program introduction
  introduction(objective);

  //Get user input and validates it and adds it to the userGuesses object
  while (!won)
  {
    guess = addValidateGuesses(userGuesses, nGuesses);

    if(guess == -99999)
    {
      break;
    }

    //add score to userGuesses
    if(nGuesses < MAX_GUESSES)
    {
      userGuesses[nGuesses++] = guess;
    }

    won = outputResult(guess, correct);
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

//Validate input and adds it if true
int addValidateGuesses(int userGuesses[], int nSize)
{
  //Data
  //userGuesses = user guesses list
  int guess;
  bool inList = false; //if number is in list
  int i = 0; // index for for loop

  //to check if the guess is in list as well if it's a sentinel value
  cout << "What is your guess [1-100] (whole number): ";
  do
  {
    inList = false;
    cin >> guess;
    cin.ignore(1000, 10);

    if(guess == -1)
    {
      return -99999;
    }
    
    for (i; i < nSize; i++)
    {
      if(guess == userGuesses[i])
      {
        inList = true;
        cout << "You already guessed " << guess << "-- guess again: ";
      } 
    }
  } while (inList);

  //to check if the guess is not sentinel value
  while(guess < 1 || guess > 100)
  {
    cout << "I really want a number between 1 and 100 (type -1 to EXIT): ";
    cin >> guess;
    cin.ignore(1000, 10);
  }
  
  return guess;
}

//output result of whether it's higher or lower or correct
bool outputResult(int guess, int correct)
{
  //DATA
  // guess = user's guess
  //correct = correct answer
  bool won = false;

  if (guess == correct)
  {
    cout << "That's Correct!" <<endl;
    return true;
  } 
  else if (guess < correct)
  {
    cout << "That's too low. guess again: " <<endl;
  }
  else 
  {
    cout << "That's too high. guess again: " << endl;
  }

  return won;
}
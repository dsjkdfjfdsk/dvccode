//Objective: Play the Mastermind game. 
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //for output
#include <string>  //for using string built in functions
#include <stdlib.h>
#include <time.h>  //for random generator
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
bool evaluateAnswer(string userGuess, string answer); //evaluates how many colors are correct and are in position
string guessValidation(); //guess validation
void introduction(string obj); //program introductions

//main program
int main()
{
  //initialize random generator
  srand(time(0));

  //Data
  string objective = "plays the Mastermind game. ";
  string guess; //4 letter combination of B, G, R, Y, O, and P inputted by user
  string computerChoices = ""; //4 letter combination of B, G, R, Y, O, and P randomly generated by computer (Any 4 letter combination of B for Blue, G for Green, R for Red, O for Orange, Y for Yellow, and P for Pink)
  int i = 0; //for generating computer choices 
  int randomNumber; //number randomly generated for each character of the computer choices
  bool winner; //if the user won or not

  //program introduction
  introduction(objective);

  while (!winner)
  {
    //get user input and see if it's valid
    guess = guessValidation();
  
    //See if they want to exit
    if (guess == "QQQQ")
    {
      break;
    }

    //generate computer choices
    for (i; i<4; i++)
    {
      randomNumber = rand() % 6;
      if (randomNumber  == 0)
      {
        computerChoices += "R";
      }
      else if (randomNumber == 1)
      {
        computerChoices += "G";
      }
      else if (randomNumber == 2)
      {
        computerChoices += "Y";
      }
      else if (randomNumber == 3)
      {
        computerChoices += "O";
      }  
      else if (randomNumber == 4)
      {
        computerChoices += "P";
      }
      else if (randomNumber == 5)
      {
        computerChoices += "B";
      }  
    }//to generate the choices
    //cout << computerChoices << endl; //uncommon out to reveal answer

    //evaluate how many colors are correct and how many positions that are correct
    winner = evaluateAnswer(guess, computerChoices);
  } //while loop to keep the game going until user wins or quits
  
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

//guess validation
string guessValidation()
{
  //Data
  string guess; //4 letter combination of B, G, R, Y, O, and P inputted by user (Any 4 letter combination of B for Blue, G for Green, R for Red, O for Orange, Y for Yellow, and P for Pink)
  int i = 0; //counter value for checking each letter
  bool valid; //whether the guess is valid

  //Evaluate if guess is valid
  do 
  {
    //Get user guess
    cout << "What's your 4 letter guess? (Type QQQQ to quit) (Any 4 letter combination of B for Blue, G for Green, R for Red, O for Orange, Y for Yellow, and P for Pink): " ;
    cin >> guess;
    cin.ignore(1000,10);
    
    //Evaluate if guess is valid
    if (guess == "QQQQ")
    {
      valid = true;
    }
    else if (guess.length() != 4)
    {
      cout << "Invalid length of guess. Please type a 4 letter combination." << endl;
      valid = false;
    }
    else 
    {
      for(i; i < 4; i++)
      {
        if (toupper(guess[i])!='B'&& toupper(guess[i])!='G' && toupper(guess[i])!='R' && toupper(guess[i])!='Y' && toupper(guess[i])!='O' && toupper(guess[i])!='P')
        {
          cout << "Invalid character in guess. Please use B, G, R, Y, O, or P in your guess." << endl;
          valid = false;
          break;
        } 
        else 
        {
          valid = true;
        }
      } //for loop for inspecting each char 
    } // if else for evaluation
  } while (!valid);
  
  return guess;
}

//guess validation
bool evaluateAnswer(string userGuess, string answer)
{
  //Data
  string guess = userGuess; //4 letter combination of B, G, R, Y, O, and P inputted by user (Any 4 letter combination of B for Blue, G for Green, R for Red, O for Orange, Y for Yellow, and P for Pink)
  string computerChoices = answer; //4 letter combination of B, G, R, Y, O, and P randomly generated by computer (text) (Any 4 letter combination of B for Blue, G for Green, R for Red, O for Orange, Y for Yellow, and P for Pink)
  int correctColors = 0; //Number of correct colors (whole number) (0-4)
  int correctPositions = 0; //Number of correct positions (whole number) (0-4)
  int counter = 0; //counter value for checking each letter

  while (counter < 4)
  {
    if (toupper(guess[counter]) == computerChoices[counter])
    {
      correctPositions = correctPositions + 1;
    }
    if (toupper(guess[counter]) == computerChoices[0] || toupper(guess[counter]) == computerChoices[1] || toupper(guess[counter]) == computerChoices[2] || toupper(guess[counter]) == computerChoices[3])
    {
      correctColors = correctColors + 1;
    }
    counter++;
  } //while loop to check how many colors are correct and how many poisitions are correrct.
  
  cout << "The number of correct colors is: " << correctColors << endl;
  cout << "The number of correct positions is: " << correctPositions << endl;

  //see if user won or not
  if (correctColors == 4 && correctPositions == 4)
  {
    cout << "You Won! Congrats!" << endl;
    return true;
  } 
  else 
  {
    return false;
  }//if else
}
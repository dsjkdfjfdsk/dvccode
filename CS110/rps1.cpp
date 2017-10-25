//Objective: Play a rock, paper, scissors game
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <cstdlib> //for generating random number
#include <ctime> //for initializing random output
#include <iostream> //for output
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
  cout << "Objective: Play a rock, paper, scissors game\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  char userPlay; //user's choice of move (R or r for rock, P or p for paper, S or s for scissors, or Q or q to quit)
  srand(time(0));  
  rand(); 
  int computerPlay; //computer's choice of move (0-2) (0 for rock, 1 for paper, 2 for scissors)
  char computerPlayC; //computer's choice of move expressed in a character (character) (R for rock, P for paper, S for scissors)
  int computerScore = 0; //current score of the computer (int) (all whole numbers that are 0 or positive)
  int userScore = 0; //current score of the user (int) (all whole numbers that are 0 or positive) 
  int gameFinished = 0; //whether the user decides to finish game

  //Instructions
  cout << "Welcome to the game of Rock, Paper, Scissors." << endl; 
  cout << "You will be asked to choose either R=rock or P=paper or S=scissors, and the computer will do the same." << endl;  
  cout << "The winner is determined by Rock wins against Scissors, or Scissors wins against Paper, or Paper wins against Rock." << endl; 
  cout << "The game winner is the player with the most scores. The best player is the player with the highest overall score." << endl; 

  //Determine winner
  do
  {
    //Generate computerPlay
    computerPlay = rand() % 3;
    if (computerPlay == 0)
    {
      computerPlayC = 'R';
    }
    else if (computerPlay == 1)
    {
      computerPlayC = 'P';
    }
    else if (computerPlay == 2)
    {
      computerPlayC = 'S';
    }
    //Get userPlay
    cout << "What's your choice? (R or r for rock, P or p for paper, S or s for scissors, or Q or q to quit): ";
    cin >> userPlay; 
    cin.ignore(1000,10);
    //Check to see if userPlay is valid. If so, evaluate who won
    if (toupper(userPlay) == 'R')
    {
      if (computerPlay == 1)
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You lost." << endl;
        computerScore += 1;
      }
      else if (computerPlay == 0)
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You tied." << endl;
        userScore +=1;
        computerScore +=1;
      }
      else 
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You won!" << endl;
        computerScore +=1;
      }
      cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
    } 
    else if (toupper(userPlay) == 'P')
    {
      if (computerPlay == 2)
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You lost." << endl;
        computerScore += 1;
      }
      else if (computerPlay == 1)
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You tied." << endl;
        userScore +=1;
        computerScore +=1;
      }
      else 
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You won!" << endl;
        computerScore +=1;
      }
      cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
    }
    else if (toupper(userPlay) == 'S')
    {
      if (computerPlay == 0)
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You lost." << endl;
        computerScore += 1;
      }
      else if (computerPlay == 2)
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You tied." << endl;
        userScore +=1;
        computerScore +=1;
      }
      else 
      {
        cout << "Your choice: " << userPlay << ", Computer's choice: " << computerPlayC << ", You won!" << endl;
        computerScore +=1;
      }
      cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
    }
    else if (toupper(userPlay) == 'Q')
    {
      cout << "Thanks for playing!" << endl;
      gameFinished = 1;
    }
    else
    {
      cout << "Invalid choice. Please try again." << endl;
      cout << "What's your choice? (R or r for rock, P or p for paper, S or s for scissors, or Q or q to quit): ";
      cin >> userPlay; 
      cin.ignore(1000,10);
    }
  } while (gameFinished != 1);

}//main
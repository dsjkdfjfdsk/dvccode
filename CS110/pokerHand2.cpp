//Objective: Deal a poker hand
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
  // "seed" the random number generator
  srand(time(0)); 
  rand();  

  // introduction
  cout << "Objective: This program will deal a poker hand\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  int n = 5; // deal this many cards   
  //card value
  int value = 1 + rand() % 13; 
  //random suit
  int suit = rand() % 4; 

  //loop index
  for (int i = 0; i < n; i++) 
  { 
    value = 1 + rand() % 13;
    suit = rand() % 4;  
    switch (value) 
    { 
      case 1: 
        cout << "Ace"; 
        break; 
      case 11: 
        cout << "Jack"; 
        break; 
      case 12: 
        cout << "Queen"; 
        break; 
      case 13: 
        cout << "King"; 
        break; 
      default: 
        cout << value; 
    } // switch 
    switch (suit) 
    { 
      case 0: 
        cout << " of Spades" << endl; 
        break; 
      case 1: 
        cout << " of Hearts" << endl; 
        break; 
      case 2: 
        cout << " of Diamonds" << endl; 
        break; 
      case 3: 
        cout << " of Clubs" << endl; 
    } // switch 
  } // for 

}//main
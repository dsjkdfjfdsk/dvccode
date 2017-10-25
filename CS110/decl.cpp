//Objective: Output user's lucky number, favorite movie, age, and first letter of his or her name. 
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
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
  cout << "Objective: This program outputs your lucky number, favorite movie, age, and first letter of his or her name. \n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //DATA
  int lucky; //user's lucky number
  string movie; //user's favorite movie
  double age; //user's age
  char letter; //user's first letter of his or her name

  //Get user's lucky number, favorite movie, age, and first letter of his or her name
  cout << "What is your lucky number (positive or negative whole number or 0)? ";
  cin >> lucky;
  cin.ignore(1000, 10);
  cout << "What's your favorite movie (just the title and should be text)? ";
  cin >> movie;
  cin.ignore(1000, 10);
  cout << "What's your age (0-122) (decimal)? ";
  cin >> age;
  cin.ignore(1000, 10);
  cout << "What's your first letter of your name (has to one letter)? ";
  cin >> letter;
  cin.ignore(1000, 10);

  //Output user's lucky number, favorite movie, age, and first letter of his or her name in a sentence
  cout << "Your lucky number is " << lucky <<
  ", favorite movie is " << movie <<
  ", age is " << age << 
  ", and first letter is " << letter << endl;

}
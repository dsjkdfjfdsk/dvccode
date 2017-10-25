//Objective: Converts user input to the next character in ASCII code. 
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //for input and output
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
  string objective = "Converts each of the user input's character to the next character in the ASCII code";
  string userText; //the line entered by the user (text)
  string userASCII = ""; //the user's line of text translated to the next character in the ASCII code (text)
  int userTextLength; //the length of the userText length (whole number)
  int i = 0; //the current index of the userText that is being translated to ASCII (whole number)

  //program introduction
  introduction(objective);

  //get user input that will be encoded
  cout << "Please type in a line of text with spaces and punctuation (if applicable) : ";
  cin >> userText;
  cin.ignore(1000, 10);
 
  //encode the userText by increasing each letter by 1
  userTextLength = userText.length();
  for (i; i < userTextLength; i += 1)
  {
    userASCII = userASCII + (char) (userText[i] + 1);
  } //for loop that encodes each char of the userText and appends it to userASCII

  //output results
  cout << userASCII;

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
//Objective: Decodes the user line of input so that each character is converted to the previous character in the ASCII code. 
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
  string objective = "Decodes the user line of input so that each character is converted to the previous character in the ASCII code.";
  string userText; //the user line of text that is inputted (text)
  string userDecoded =""; //the user line of text decoded so that each char is converted to the previous char (text)
  int userTextLength; //the length of the userText length (whole number)
  int i = 0; //the current index of the userText that is being translated to ASCII (whole number)

  //program introduction
  introduction(objective);

  //get user input that will be encoded
  cout << "Please type in an encoded line of text with spaces and punctuation (if applicable): ";
  cin >> userText;
  cin.ignore(1000, 10);
 
  //encode the userText by increasing each letter by 1
  userTextLength = userText.length();
  for (i; i < userTextLength; i += 1)
  {
    userDecoded = userDecoded + (char) (userText[i] - 1);
  } //for loop that encodes each char of the userText and appends it to userASCII

  //output results
  cout << userDecoded;

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
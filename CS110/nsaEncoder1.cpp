//Objective: Converts each line of the user input's (from a file) with a specific encryption pattern
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //for file input and output
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
string encodeText(string textRaw); //for encoding a line of text and returning it

//main program
int main()
{
  //Data
  string objective = "Converts each line of the user input's (from a file) so that each character is now the next character in the ASCII code.";
  string filename; //the file name that the userTexts are located (text) 
  string lineFromFile; //current line of the input file (text) 
  string textEncoded; //line of text encoded
  ifstream fin; //file input
  ofstream fout; //file output

  //program introduction
  introduction(objective);

  //get user input for file name and open that and the output file
  cout << "Please type in a name of the file (with the .txt extension) : ";
  cin >> filename;
  cin.ignore(1000, 10);
  fin.open(filename.c_str());
  if (!fin.good()) throw "I/O error"; 
  fout.open("secret.txt");
  if (!fout.good()) throw "I/O error"; 
  
  //encodes every line in the input file and outputs the result to secret.txt
  while (fin.good() && fout.good()) 
  { 
    getline(fin, lineFromFile); 
    textEncoded = encodeText(lineFromFile);
    fout << textEncoded << endl;
    cout << textEncoded << endl;
  } // while 
  fin.close();
  fout.close();

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

string encodeText(string textRaw)
{
  //Data
  string userText = textRaw; //the line entered by the user (text)
  string userASCII = ""; //the user's line of text translated to the next character in the ASCII code (text)
  int userTextLength; //the length of the userText length (whole number)
  int i = 0; //the current index of the userText that is being translated to ASCII (whole number)
 
  //encode the userText by increasing each letter by 1
  userTextLength = userText.length();
  for (i; i < userTextLength; i += 1)
  {
    userASCII = userASCII + (char) (userText[i] + 1);
  } //for loop that encodes each char of the userText and appends it to userASCII

  //return encoded text
  return userASCII;
}
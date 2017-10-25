//Objective: Decodes each line of the user input's (from a file) with a specific encryption pattern
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //for file input
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
string decodeText(string textRaw, int* encryption, int nEncryption); //for decoding a line of text and returning it

//main program
int main()
{
  //Data
  string objective = "Decodes each line of the user input's (from a file) so that each character is now the previous character in the ASCII code.";
  string filename; //the file name that the userTexts are located (text) 
  string lineFromFile; //current line of the input file (text) 
  string textDecoded; //line of text decoded 
  ifstream fin; //file input
  int nEncryption = -1; //number of encryption numbers
  int* encryption; //encryption pattern
  int i = 0; //index for while loop for encryption
  string dummy;//for counting size of the array

  //program introduction
  introduction(objective);

  //get size of the array
  fin.open("offset.txt");
  if (!fin.good()) throw "I/O error"; 
  while (fin.good()) 
  {
    getline(fin, dummy); 
    nEncryption++;
  } // while
  fin.close();

  //get nEncryption and encryption array from offset.txt
  encryption = new int[nEncryption];
  fin.open("offset.txt");
  if (!fin.good()) throw "I/O error"; 
  while (fin.good()) 
  { 
    fin >> encryption[i];
    fin.ignore(1000,10);
    i++;
  } // while 
  fin.close();
  
  //open secret.txt
  fin.open("secret.txt");
  if (!fin.good()) throw "I/O error"; 
  
  //decodes every line in the input file and outputs the result to console
  while (fin.good()) 
  { 
    getline(fin, lineFromFile); 
    textDecoded = decodeText(lineFromFile, encryption, nEncryption);
    cout << textDecoded << endl;
  } // while 
  fin.close();

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

string decodeText(string textRaw, int* encryption, int nEncryption)
{
  //Data
  // int* encryption = encyrption offset array
  // int nEncryption = encryption array size
  string userText = textRaw; //the line entered by the user (text)
  string userASCII = ""; //the user's line of text translated to the next character in the ASCII code (text)
  int userTextLength; //the length of the userText length (whole number)
  int i = 0; //the current index of the userText that is being translated to ASCII (whole number)
  int b = 0; //index of encryption
 
  //decodes the userText by increasing each letter by 1
  userTextLength = userText.length();
  for (i; i < userTextLength; i += 1)
  {
    userASCII = userASCII + (char) (userText[i] - encryption[b]);
    b++;

    if (b >= nEncryption)
    {
      b = 0;
    }
  } //for loop that decodes each char of the userText and appends it to userASCII

  //return decoded text
  return userASCII;
}
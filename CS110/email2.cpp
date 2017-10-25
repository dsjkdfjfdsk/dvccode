//Objective: Uses given input and output files from user to output each line of the input file with an @ character

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

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //program introductions
void outputAtSigns(string inputFile);//output lines with @ character

//main program
int main()
{
  //Data
  string objective = "uses given input and output files from user to output each line of the input file with an @ character";
  string inputFile; //the user's choice for his or her input file 
  string outputFile; //the user's choice for his or her output file
  string continueYN; //if the user wants to continue or not

  //program introduction
  introduction(objective);

  //get user input and validates it
  cout << "Enter input filename [default: fileContainingEmails.txt]: ";
  getline(cin, inputFile);
  if (inputFile.length() == 0)
  {
    inputFile = "fileContainingEmails.txt";
    outputFile = "copyPasteMyEmails.txt";
  }
  else
  {
    outputFile = inputFile;
  }
  cout << "Enter output filename [default: " << outputFile << "]:";
  getline(cin, outputFile);
  if (outputFile.length() == 0 && inputFile == "fileContainingEmails.txt")
  {
    outputFile = "copyPasteMyEmails.txt";
  } 
  else if (outputFile.length() == 0)
  {
    outputFile = inputFile;
  } //if else

  //output file names
  cout << "Input file: " << inputFile << endl;
  cout << "Output file: " << outputFile << endl;

  //check if the user wants to continue to find @ lines
  cout << "press ENTER key to continue or ANY key to exit: ";
  getline(cin, continueYN);
  if (continueYN.length() == 0)
  {
    outputAtSigns(inputFile);
  } //if

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

//find lines with @ signs
void outputAtSigns(string inputFile)
{
  //Data
  string filename = inputFile; //the user's inputFile name
  ifstream fin; //file input
  string currentLine; //current line of file
  int lineLength; //length of current line
  int i = 0; //index for for loop

  //open file and output lines with @
  fin.open(filename.c_str());
  if (!fin.good()) throw "I/O error"; 
  while (fin.good())
  {
    getline(fin, currentLine);
    lineLength = currentLine.length();
    for (i; i < lineLength; i += 1)
    {
      if (currentLine[i] == '@')
      {
        cout << currentLine << endl;
      }
    } //for loop that finds @ char
    i = 0;
  } //while
} //output at signs
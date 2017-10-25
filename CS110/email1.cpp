//Objective: Determines what the user wants for input and output files
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
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

//main program
int main()
{
  //Data
  string objective = "determines what the user wants for input and output files";
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

  //check if the user wants to continue and outputs correspondingly 
  cout << "press ENTER key to continue or ANY key to exit: ";
  getline(cin, continueYN);
  if (continueYN.length() == 0)
  {
    cout << "Input file: " << inputFile << endl;
    cout << "Output file: " << outputFile << endl;
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
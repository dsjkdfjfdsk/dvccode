//Objective: Uses given input and output files from user to output every valid email address to console, skipping case-independent duplicates. 
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <deque> //for collections
#include <fstream> //for file input
#include <iostream> //for input and output
#include <string>  //for using string built in functions
using namespace std;

//Programmer defined data types
struct Email
{
  string address;
}; //Email

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
string changeToUpper(string original);//change lowercase string to uppercase string
void introduction(string obj); //program introductions
bool isValidEmailChar(char emailChar);//if email character is valid

//main program
int main()
{
  //Data
  string objective = "uses given input and output files from user to output every valid email address to console, skipping case-independent duplicates.";
  string inputPrompt = "Enter input filename [default: fileContainingEmails.txt]: "; //default input prompt
  string outputPrompt = "Enter output filename [default: "; //default output prompt
  string dFileName = "fileContainingEmails.txt"; //default file name of the input file
  string oFileName = "copyPasteMyEmails.txt"; //default file name of the outputfile
  string iFileName; //the user's choice for his or her input file 
  string outputFile = oFileName; //the user's choice for his or her output file
  string continueYN; //if the user wants to continue or not
  ifstream fin; //for file input
  string currentLine; //currentLine of the file
  int i = 0; //for the outer loop for email validation
  int s = 0; //for s loop (which is before the @ sign) for email validation
  int e = 0; //for e loop (which is after the @ sign) for email validation
  bool hasDot; //if there is a dot or not
  int dotPos; //position of the dot 
  int countEmails = 0; //amount of email addresses
  deque<Email> emailList; //collection of non duplicate emails
  int b = 0; //iterator for for loop checking for duplicates
  bool foundEmail = false; //whether the email is in the list
  Email currentEmail; //current email 

  //program introduction
  introduction(objective);

  //get user input and validates it and output file names
  cout << inputPrompt;
  getline(cin, iFileName);
  if (iFileName.length() == 0)
  {
    iFileName = dFileName;
  }
  else
  {
    outputFile = iFileName;
  }
  cout << outputPrompt << outputFile << "]:";
  getline(cin, outputFile);
  if (outputFile.length() == 0 && iFileName == dFileName)
  {
    outputFile = oFileName;
  } 
  else if (outputFile.length() == 0)
  {
    outputFile = iFileName;
  } //if else
  cout << endl;
  cout << "Input file: " << iFileName << endl;
  cout << "Output file: " << outputFile << endl << endl;

  //check if the user wants to continue to find valid emails
  cout << "Press ENTER key to continue or ANY key to exit: ";
  getline(cin, continueYN);
  cout << endl;
  if (continueYN.length() == 0)
  {
    //Open file for line input for processing 
    fin.open(iFileName.c_str());
    if (!fin.good()) throw "I/O error"; 

    //Validate email main loop. First check if there is an '@' sign, and check via the s loop chars before and via e loop if the chars after
    while(fin.good())
    {
      getline(fin, currentLine);
      for(i = 0; i < currentLine.length(); i++)
      {
        if(currentLine[i] == '@')
        {
          for(s = i-1; s >= 0; s--)
          {
            if(!isValidEmailChar(currentLine[s]))
            {
              break;
            } //if
          } //for 
          s = s + 1;
          hasDot = false;
          for(e = i+1; e < currentLine.length(); e++)
          {
            if(currentLine[e] == '.')
            {
              hasDot = true;
              dotPos = e;
            } 
            else if(!isValidEmailChar(currentLine[e]))
            {
              break;
            } //if else if
          } //for
          if (s < i && e > i && hasDot && dotPos >= (i+1))
          {
            //Checks if email is a duplicate
            currentEmail.address = currentLine.substr(s, e-s);
            for(b; b < emailList.size(); b++)
            {
              if(changeToUpper(currentEmail.address) == changeToUpper(emailList[b].address))
              {
                foundEmail = true;
                break;
              }
            }//for loop
            if(!foundEmail)
            {
              cout << currentLine.substr(s, e-s) << endl;
              countEmails++;
              emailList.push_back(currentEmail);
            }//if
            foundEmail = false;
          } //if
        } //if
      } //for
    } //while

    //output number of valid emails
    cout << "Number of valid email addresses is " << countEmails << endl;
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

//Check to see if the email character is valid
bool isValidEmailChar(char emailChar)
{
  //Data
  //emailChar = the char of the email that is currently being checked
  bool valid = false; //if valid or not

  //Checks to see if character is valid and returns validity
  if((emailChar >= 'a' && emailChar <= 'z') || (emailChar >= 'A' && emailChar <= 'Z') || (emailChar >= '0' && emailChar <= '9') || emailChar == '_' || emailChar == '+' || emailChar == '-')
  {
    valid = true;
  }
  return valid;
}

//Change string to all uppercase
string changeToUpper(string original)
{
  //Data
  //original = original string
  string uppercaseString; //uppercase version of the string
  int i = 0; //iterator for for loop 

  //convert lower case to upper case char by char and returns it
  for(i; i < original.length(); i++)
  {
    uppercaseString += toupper(original[i]);
  }//for
  return uppercaseString;
}
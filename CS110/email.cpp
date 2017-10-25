//Objective: Uses given input and output files from user to output every valid email address to console and a file, skipping case-independent duplicates. 
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
bool checkDuplicates(string email, deque<Email>& emailList);//check duplicates
void introduction(string obj); //program introductions
bool isValidEmailChar(char emailChar);//if email character is valid
void sortEmailsAlphabetically(deque<Email>& emailList); //sort emails alphabetically

//main program
int main()
{
  //Data
  string objective = "uses given input and output files from user to output every valid email address to console, skipping case-independent duplicates.";
  string dFileName = "fileContainingEmails.txt"; //default file name
  string oFileName = "copyPasteMyEmails.txt"; //the user's choice for his or her output file
  string iFileName; //the user's choice for his or her input file 
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
  ofstream fout; //for file output
  int o = 0; //output iterator for outputting to file

  //program introduction & instructions
  introduction(objective);
  cout << "Press ENTER if you want to just use the default file names, or enter your custom file names" << endl;

  //get user input and validates it and output file names
  cout << "Enter input filename [default: fileContainingEmails.txt]: ";
  getline(cin, iFileName);
  if (iFileName.length() == 0)
  {
    iFileName = dFileName;
    dFileName = "copyPasteMyEmails.txt";
  }
  else
  {
    dFileName = iFileName;
  } //if else
  cout << "Enter output filename [default: " << dFileName << "]:";
  getline(cin, oFileName);
  if (oFileName.length() == 0)
  {
    oFileName = dFileName;
  } //if 
  cout << endl;
  cout << "Input file: " << iFileName << endl;
  cout << "Output file: " << oFileName << endl << endl;

  //check if the user wants to continue to find valid emails and opens file if so
  cout << "Press ENTER key to continue or ANY key to exit: ";
  getline(cin, continueYN);
  cout << endl;
  if (continueYN.length() == 0)
  {
    fin.open(iFileName.c_str());
    if (!fin.good()) throw "I/O error"; 

    //Validate email main loop. First check if there is an '@' sign, and check via the s loop chars before and via e loop if the chars after are valid
    while(fin.good())
    {
      getline(fin, currentLine);
      for(i = 0; i < currentLine.length(); i++)
      {
        if(currentLine[i] == '@')
        {
          s = i-1;
          while(isValidEmailChar(currentLine[s]) && s >= 0)
          {
            s--;
          } // while
          s = s + 1;
          hasDot = false;
          e = i+1;
          //cout << currentLine;
          while(isValidEmailChar(currentLine[e]) && e < currentLine.length())
          {
            if(currentLine[e] == '.' && hasDot==false)
            {
              hasDot = true;
              dotPos = e;
            } //if
            e++;
          } //while
          if (s < i && e > i && hasDot && dotPos > (i+1))
          {
            if (!checkDuplicates(currentLine.substr(s, e-s), emailList))
            {
              countEmails++;
            }//if
          } //if
        } //if
      } //for
    } //while
    fin.close();

    //Sort email list alphabetically
    sortEmailsAlphabetically(emailList);

    //Output emails to the file output and console and output number of valid emails
    if (countEmails > 0)
    {
      cout << endl;
      cout << "Copy/paste this content (which is also pasted in " << oFileName << ") into the to, cc, or bcc field of any email message: " << endl;
      fout.open(oFileName.c_str());
      if(!fout.good()) throw "I/O error";
      for(o; o <emailList.size(); o++)
      {
        if(o == emailList.size() - 1)
        {
          fout << emailList[o].address;
          cout << emailList[o].address;
        }
        else 
        {
          fout << emailList[o].address << "; ";
          cout << emailList[o].address << "; ";
        }
      } //for
      cout << endl << endl;
      fout.close();
    }//if
    if(countEmails == 0)
    {
      cout << "Sorry, no email addresses were found in the file " << iFileName << endl;
    }
    else
    {
      cout << "Number of valid email addresses is " << countEmails << ". These emails have been copied in alphabetical order to " << oFileName <<endl;
    } //if else
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
  if((emailChar >= 'a' && emailChar <= 'z') || (emailChar >= 'A' && emailChar <= 'Z') || (emailChar >= '0' && emailChar <= '9') || emailChar == '_' || emailChar == '+' || emailChar == '-' || emailChar == '.')
  {
    valid = true;
  } //if
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

//Check duplicates
bool checkDuplicates(string email, deque<Email>& emailList)
{
  //Data
  //deque<Email> emailList = list of emails to be checked to see if email is in
  int b = 0; //iterator for for loop checking for duplicates
  Email currentEmail; //current email 
  
  //Checks if email is a duplicate and returns if it found duplicates or not
  currentEmail.address = email;
  for(b; b < emailList.size(); b++)
  {
    if(changeToUpper(currentEmail.address) == changeToUpper(emailList[b].address))
    {
      return true;
    }//if
  }//for loop
  cout << email << endl;
  emailList.push_back(currentEmail);
  return false;
}

//Sort email lists alphabetically
void sortEmailsAlphabetically(deque<Email>& emailList)
{
  //Data
  //deque<Email> emailList = list of emails to be sorted alphabetically
  string tempAddress; //temp email
  int i = 0; //index for outer for loop sorting
  int j = 0; //index for inner for loop sorting

  //Sort emailList alphabetically
  for (i; i < emailList.size(); i++)
  {
    for (j = i + 1; j < emailList.size(); j++)
    {
      if(changeToUpper(emailList[i].address) > changeToUpper(emailList[j].address))
      {
        tempAddress = emailList[i].address;
        emailList[i].address = emailList[j].address;
        emailList[j].address = tempAddress;
      }//if
    }//for
  }//for
}
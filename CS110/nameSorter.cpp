//Objective: read names in a text file, sort them alphabetically, and output them to the screen
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //for file input
#include <iostream> //for output
#include <string>  //for using string built in functions
using namespace std;

//Programmer defined data types

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //program introductions
void outputArray(string* names, int namesSize); //output Array
void storeArray(string* names, int namesSize, string filename); //stores 5 lines of the file into the array if it is not a blank line or a duplicate
void sortArray(string* names, int namesSize); //sorts array


//main program
int main()
{
  //Data
  string objective = "read names in a text file, sort them alphabetically, and output them to the screen";
  string filename; //file name that the user chooses
  int namesSize = 5; //size of names array
  string* names = new string[namesSize]; //names array

  //program introduction
  introduction(objective);

  //get user's file name
  cout << "Please enter a file name: " << endl;
  getline(cin, filename);

  //Process file
  storeArray(names, namesSize, filename);

  //Sort names
  sortArray(names, namesSize);

  //Output names
  outputArray(names, namesSize);

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

//store array
void storeArray(string* names, int namesSizes, string filename)
{
  //Data
  //names = the array in which we will store the file input into
  //namesSizes = names array size
  int i = 0; //index of for loop
  int b = 0; //index for inner for loop
  bool valid = true; //valid or not for line
  ifstream fin; //file input
  string currentLine; //current line of the file

  fin.open(filename.c_str());
  if (!fin.good()) throw "I/O error"; 

  while(fin.good() && b < namesSizes)
  {
    getline(fin, currentLine);
    if(!currentLine.empty())
    {
      valid = true;
      i = 0;
      for(i; i < b; i++)
      {
        if(currentLine == names[i])
        {
          valid = false;
        }
      }
      if(valid)
      {
        names[b] = currentLine;
        b++;
      }
    }
  }
  fin.close();
  
}

void sortArray(string* names, int namesSize)
{
  //Data
  //names = names array
  //namesSize = names Size
  int i = 0; //index for for loop
  int j = 1; //index for inner for loop
  string temp; //temp variable

  for(i; i < namesSize; i++)
  {
    for(j = i + 1; j <namesSize; j++)
    { 
      if(toupper(names[i][0]) > toupper(names[j][0]))
      {
        temp = names[i];
        names[i] = names[j];
        names[j] = temp;
      } //if
    } //for
  } //for
}

void outputArray(string* names, int namesSize)
{
  //Data
  //names = names array
  //namesSize = names Size
  int i =0; //index

  for(i; i < namesSize; i++)
  {
    cout << names[i] << endl;
  }
}
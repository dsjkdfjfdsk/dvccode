//Objective: read an input file of scores and find average score and number of scores greater than average
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
  string objective = "read an input file of scores and find average score and number of scores greater than average";
  const int MAX_SCORES = 100; // list capacity 
  int nScores = 0; // initially empty 
  int score[MAX_SCORES]; //list of values
  ifstream fin; //represents input file
  int aScore; // temporary storage for new score
  int i; // loop counter 
  int scoreTotal = 0; // sums of both scores
  int nGreater = 0; 
  double average;//average of both scores

  //program introduction
  introduction(objective);

  fin.open("scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  
  // read and save the scores 
  while (fin.good()) 
  { 
    // read a score from the file 
    fin >> aScore; 
    fin.ignore(1000, 10); 
  
    // add new score to list, if list is not full 
    if (nScores < MAX_SCORES) 
      score[nScores++] = aScore; 
  } // while 

  // find the average 
  for (i = 0; i < nScores; i++) 
    scoreTotal += score[i]; 
  average = (double)scoreTotal / nScores; 
  cout << "The average of " << nScores 
    << " numbers is " << average << endl; 
  
  // count number of scores > average 
  for (i = 0; i < nScores; i++) 
    if (score[i] > average) nGreater++; 
  cout << nGreater  << " scores are greater than the average." << endl; 

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
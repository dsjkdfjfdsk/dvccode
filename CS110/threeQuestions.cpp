//Objective: Asks three questions and reports if the answer is correct or not as well as the total score
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
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
bool askQuestion(string, int); //see if input is equal to the user input

//main program
int main()
{
  //Data
  string objective = "template for C++ programs and to test code";
  int score = 0; //total count of correct answers

  //program introduction
  introduction(objective);

  //Asks three questions
  if (askQuestion("How many bits in a byte? ", 8))
  {
    score ++;
    cout << "Correct" << endl;
  }
  else 
  {
    cout << "Incorrect, but a better answer would be " << 8 << endl;
  } //if statement to check if answer is correct or not
  if (askQuestion("How many bytes in a int? ", 4))
  {
    score ++;
    cout << "Correct" << endl;
  }
  else 
  {
    cout << "Incorrect, but a better answer would be " << 4 << endl;
  } //if statement to check if answer is correct or not
  if (askQuestion("How many bytes in a long long? ", 8))
  {
    score ++;
    cout << "Correct" << endl;
  }
  else 
  {
    cout << "Incorrect, but a better answer would be " << 8 << endl;
  } //if statement to check if answer is correct or not
  //outputs total score
  cout << "That's " << score << " correct out of 3 questions asked" << endl;

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

//asks question and checks if answer is correct
bool askQuestion(string question, int answer)
{
  //Data
  //question = question to be asked to the user
  //answer = the correct answer to the question
  int submission; //user input for each question
  
  //output question and get user input
  cout << question;
  cin >> submission;
  cin.ignore(1000,10);

  //check if the user input is correct
  if (submission == answer)
  {
    return true;
  }
  else
  {
    return false;
  }
}
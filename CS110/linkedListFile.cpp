//Objective: calculate the average, highest, lowest scores and number of scores greater than the average, using a linked list
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //for file input
#include <iostream> //for console output
using namespace std;

//Programmer defined data types
//for score linked list
struct Score
{
  int value;
  Score* next; // the link
};

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
  string objective = "calculate the average, highest, lowest scores and number of scores greater than the average, using a linked list";
  Score* start = 0; //starting node for linkedlist
  Score* aScore; //temp node
  Score* p; //for traversing to get average
  int count = 0; // to count the number of nodes in the list
  int sum = 0; // to accumulate the total of all scores
  double average; // the average of all the numbers (decimal)
  int nGreater; //the number of scores greater than average (whole number)
  int highest; //the highest score (whole number)
  int lowest; //the lowest score (whole number)
  ifstream fin; //file input variable
  Score* nextNode; //points to the next node on the list

  //program introduction
  introduction(objective);

  //Linked list read and save records
  fin.open("scores.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good())
  {
    //create node
    aScore = new Score;

    //read its int value from file
    fin >> aScore->value;
    fin.ignore(1000, 10);

    //add node to list
    aScore->next = start;
    start = aScore;
  } //while

  //traverse and calculate average
  for (p = start; p; p = p->next)
  {
    sum += p->value;
    count++;
  } //for 
  average = sum / (double) count;

  //calculate nGreater, highest, lowest by traversing linked list p.
  lowest = aScore->value;
  highest = aScore->value;
  for (p = start; p; p = p->next)
  {
    if (p->value > average)
    {
      nGreater++;
    } //if
    if (p->value < lowest)
    {
      lowest = p->value;
    } 
    else if (p->value > highest)
    {
      highest = p->value;
    } // if else if
  } // for 

  //output results 
  if (count > 0)
  {
    cout << "The average of " << count << " scores is " << average << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
    cout << "Number of scores greater than average: " << nGreater << endl;
  }
  else
  {
    cout << "No values were entered." <<endl;
  } //if else

  //Relieve borrowed memory
  while(start)
  {
     nextNode = start->next; 
     delete start;
     start = nextNode;
  } // while

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
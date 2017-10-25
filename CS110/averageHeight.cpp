//Objective: Calculate the average height of everyone in the classroom.
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //for output
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  // introduction
  cout << "Objective: This program calculates the average height of everyone in the classroom.\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  double height; // height of each person in the room in centimeters (number) (more than 0 cm, less than 247 cm)
  int count = 0; // number of people in the room (whole number)
  double sum = 0; // total of all heights of all the people in the room (whole number)
  double average = 0; // the average age of all the people in the room (decimal)
  
  //Get height input and calculating the average 
  do 
  {
    //Get height input
    cout << "What is your height? (0.0 to 8.0 ft, decimal) [TYPE -1 to EXIT or finish] ";
    cin >> height;
    cin.ignore(1000, 10);
    if (height == -1)
    {
      cout << "Finished gathering heights." << endl;
    }
    else if (height < 0.0 || height > 8.0)
    {
      cout << "Invalid height. Please try again: " << endl;
    }
    else 
    {
      //Add the heights all together while keeping count
      sum = sum + height;
      count = count +1;
    } // if else for evaluating if height is valid and calculating the average
  } while(height!=-1); // while
  average = sum / count;
  
  //Output the average height
  cout << "The average height of everyone in the classroom is " << average << " feet" << endl;

}//main
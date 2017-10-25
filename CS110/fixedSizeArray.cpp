//Objective: Prompt the user to input 4 numbers between 0 and 100, and calculate the average of those 4 numbers, and how many of those 4 numbers are above the average.
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
void getArray(int numbers[]); //Get array of 4 numbers from user
void introduction(string obj); //program introductions
int moreThanAverage(int average, int numbers[]); //figures out how many numbers are bigger than average
int sumArray(int numbers[]); //sum array

//main program
int main()
{
  //Data
  string objective = "prompts the user to input 4 numbers between 0 and 100, and calculate the average of those 4 numbers, and how many of those 4 numbers are above the average.";
  int numbers[4]; //array of the 4 numbers
  int sum = 0; // sum of the 4 numbers
  double average; //average of the 4 numbers
  int greaterAverage; // count of numbers greater than the average

  //program introduction
  introduction(objective);

  //Get array of 4 numbers from user
  getArray(numbers);

  //Get sum of the numbers
  sum = sumArray(numbers);

  //Calculate the average
  average = sum / 4.0;

  //Get the number greater than the average
  greaterAverage = moreThanAverage(average, numbers);

  //Output all labels
  cout << "The average of those " << 4 << " numbers is " << average;
  cout << ". There are " << greaterAverage << " numbers greater than the average" << endl;

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

//Get array of 4 numbers from user
void getArray(int numbers[])
{
  //Data
  //numbers[] = scores
  int i = 0; //index of the for loop

  //Loop to get numbers and return them in an array
  do
  {
    cout << "Please enter a number [0-100]: ";
    cin >> numbers[i];
    cin.ignore(1000,10);
    
    if (numbers[i] < 0 || numbers[i] > 100)
    {
      cout << "Invalid number. Please type a number between 0 and 100." << endl;
    }
    else
    {
      i++;
    }
  } while (numbers[i] >= 0 && numbers[i] <= 100 || i < 4);
}

//Sum array 
int sumArray(int numbers[])
{
  //Data
  //numbers = user's 4 numbers in an array
  int sum = 0; //the sum of the 4 numbers
  int i = 0; //iterator for for loop

  //Sum it all up and return the sum
  for (i; i < 4; i++)
  {
    sum += numbers[i];
  }
  return sum;
} 

//Figures out how many numbers are bigger than average
int moreThanAverage(int average, int numbers[])
{
  //Data
  //average = average of user's 4 numbers
  int count = 0; //count of numbers bigger than average
  int i = 0; //iterator for for loop

  //Traverses numbers array and checks each number if it's bigger than the average and returns the total count of those numbers.
  for (i; i < 4; i++)
  {
    if (numbers[i] > average)
    {
      count++;
    }
  }
  return count;
} 

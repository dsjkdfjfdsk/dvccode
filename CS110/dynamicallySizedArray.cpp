//Objective: input number of scores to be input, then input that many scores, calculate the maximum score, average score, minimum score, and how many A grade scores.
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
void getArray(int numbers[], int size); //Get array of 4 numbers from user
void introduction(string obj); //program introductions
int numberAGrades(int numbers[], int size); //figures out how many numbers are A grades
int sumArray(int numbers[], int size); //sum array

//main program
int main()
{
  //Data
  string objective = "input number of scores to be input, then input that many scores, calculate the maximum score, average score, minimum score, and how many A grade scores.";
  int size;
  int* numbers= new int[size]; //array of the 4 numbers
  int sum = 0; // sum of the 4 numbers
  double average; //average of the 4 numbers
  int greaterA; // count of numbers greater than the average
  int max = numbers[0];
  int min = numbers[size-1];

  //program introduction
  introduction(objective);

  //Get size of the array
  cout << "How many scores? ";
  cin >> size;
  cin.ignore(1000,10);

  //Get array of numbers from user and does calucations 
  getArray(numbers, size);

  //Get maximum and minimum
  max = numbers[0];
  min = numbers[size-1];

  //Get sum of the numbers
  sum = sumArray(numbers, size);

  //Calculate the average
  average = (double) sum / (double) size;

  //Get the number greater than the average
  greaterA = numberAGrades(numbers, size);

  //Output all labels
  cout << "Sorted " << numbers;
  for (int i = 0; i<size;i++)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;
  cout << " Minimum " << min << endl;
  cout << " Maximum " << max << endl;
  cout << " Average " << average << endl;
  cout << greaterA <<  " A grade(s) entered" << endl;

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
void getArray(int numbers[], int size)
{
  //Data
  //numbers[] = scores
  //int size = size of the array
  int i = 0; //index of the for loop
  int j = 0;
  int g = 0;
  int temp;

  //Set array
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
  } while (numbers[i] >= 0 && numbers[i] <= 100 || i < size);
  
  //Sort Array
  for(g; g<size; g++) 
  {
    for(j; j<size; j++)
    {
      if(numbers[g] > numbers[j])
      {
        temp = numbers[g];
        numbers[g] = numbers[j];
        numbers[j] = temp;
      }
    }
  }

}

//Sum array 
int sumArray(int numbers[], int size)
{
  //Data
  //numbers = user's 4 numbers in an array
  int sum = 0; //the sum of the 4 numbers
  int i = 0; //iterator for for loop

  //Sum it all up and return the sum
  for (i; i < size; i++)
  {
    sum += numbers[i];
  }
  return sum;
} 

//Figures out how many numbers are bigger than average
int numberAGrades(int numbers[], int size)
{
  //Data
  //average = average of user's 4 numbers
  int count = 0; //count of numbers bigger than A letter grade
  int i = 0; //iterator for for loop

  //Traverses numbers array and checks each number if it's bigger than the average and returns the total count of those numbers.
  for (i; i < size; i++)
  {
    if (numbers[i] >= 90)
    {
      count++;
    }
  }
  return count;
} 

//Objective: Creates a 4 function calculator
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
  cout << "Objective: This program creates a 4 function calculator\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  double first; //the first number (decimal) (all numbers)
  double second; //the second number (decimal) (all numbers)
  int symbol = 0; //the operator (whole number) (1= addition  2= subtraction  3= multiplication  4= division)
  double result; //the result of using the operator with the first and second number (decimal) (all numbers)
  char nextCalc; //the result of whether the user wants to do another operation (character) (either Y or N)
  
  //Get numbers and operator from user, calculate, and output
  do
  {
    //Get first and second number and operator
    cout << "Please enter first number: ";
    cin >> first;
    cin.ignore(1000,10);
    cout << "Please enter second number: ";
    cin >> second;
    cin.ignore(1000,10);
    cout << "Please enter operator [1= addition  2= subtraction  3= multiplcation  4= division]: ";
    cin >> symbol;
    cin.ignore(1000,10);
    while (symbol > 4 || symbol < 1)
    {
      cout << "Invalid operator. Please type 1 for addition, 2 for subtraction, 3 for multiplication, or 4 for division";
      cout << "Please enter operator [1= addition  2= subtraction  3= multiplcation  4= division]: ";
      cin >> symbol;
    }
     
    //Conduct operations based on operator
    if (symbol == 1)
    {
      result = first + second;
      cout << first << " + " << second << " = " << result << endl;
    }
    else if (symbol == 2)
    {
      result = first - second;
      cout << first << " - " << second << " = " << result << endl;
    }
    else if (symbol == 3)
    {
      result = first * second;
      cout << first << " * " << second << " = " << result << endl;
    }
    else if (symbol == 4)
    {
      result = first / second;
      cout << first << " / " << second << " = " << result << endl;
    }
    
    //Check to see if user wants to do another calculation
    cout << "Another calculation [Y=yes or N=no]: ";
    cin >> nextCalc;
    cin.ignore(1000,10);
    while (nextCalc != 'Y' && nextCalc != 'y' && nextCalc != 'N' && nextCalc != 'n')
    {
      cout << "Couldn't understand you! Please type Y for yes or N for no if you want to do another calculation: ";
      cin >> nextCalc;
      cin.ignore(1000,10);
    }
  } while (nextCalc == 'Y' || nextCalc == 'y'); // do while for getting input, computing the numbers and ouputting them

}//main
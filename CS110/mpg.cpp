//Objective: Get keyboard input from the user to calculate the miles/gallon
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
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
  cout << "Objective: Gets keyboard input from the user to calculate the miles/gallon\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  int gallons = -1; //number of gallons used on trip (0 or positive)
  int tank = -1; //capacity of the fuel tank in gallons (positive)
  int miles = -1; //miles traveled on trip in miles (0 or positive)
  double range; //range possible with the remaining fuel in miles (0 or positive)
  double mpg; //miles per gallon (0 or positive)
  int leftInTank; //how many gallons left in the tank (0 or positive)
  
  //Get user input for the guess
  while (tank <= 0 && (gallons < 0 || gallons > tank) && miles < 0)
  {
    while (tank <= 0)
    {
      cout << "What's the capacity of your fuel tank (whole number greater or equal to 0) (-9999 to END)? ";
      cin >> tank;
      cin.ignore(1000,10);
      if (tank == -9999)
      {
        break;
      }
      if (tank < 0)
      {
        cout << "Invalid tank. Please type a positive whole number greater than 0: ";
        cin >> tank;
        cin.ignore(1000,10);
      }
    } //while loop to get tank
    while (gallons < 0 || gallons > tank)
    {
      cout << "How many gallons have you used (whole number greater or equal to 0) (-9999 to END)? ";
      cin >> gallons;
      cin.ignore(1000,10);
      if (gallons == -9999)
      {
        break;
      }
      else if (gallons < 0)
      {
        cout << "Invalid gallons. Please type a positive whole number greater or equal to 0: ";
        cin >> gallons;
        cin.ignore(1000,10);    
      }
      else if (gallons > tank) 
      {
        cout << "Gallons you used must be less than or equal to the tank capacity" << endl;
      }
    } // while loop to get gallons
    while (miles < 0)
    {
      cout << "How many miles have you travelled (whole number or equal to 0) (-9999 to END)? ";
      cin >> miles;
      cin.ignore(1000,10);
      if (miles == -9999)
      {
        break;
      }
      if (miles < 0)
      {
        cout << "Invalid miles. Please type a positive whole number greater or equal to 0: ";
        cin >> miles;
        cin.ignore(1000,10);
      }
    } //while loop to get miles input
  } //while loop to ensure that input is all valid
  
  //calculate range possible with the remaining fuel and outputs it
  if (tank != -9999 && miles != -9999 && gallons != -9999)
  {
    
    //calculate range possible
    mpg = miles / gallons;
    leftInTank = tank - gallons;
    range = leftInTank * mpg;
  
    //Output range
    cout << "You can travel " << range << " miles with the fuel you have left" << endl;
  } //if statement to check if the user hasn't exited

}//main
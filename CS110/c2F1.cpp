//Objective: Converting Fahrenheit To Celsius
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

//Programmer defined function
//NONE

//main program
int main()
{
  // introduction
  cout << "Objective: Converting Fahrenheit To Celsius\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  double c=0.0; // degrees Celsius
  double f; // degrees Fahrenheit
  ifstream fin; //file input

  //Read temperature in Celsius and converts it to Farenheit
  fin.open("temps.txt");
  if (!fin.good()) throw "I/O error"; 
  do
  { 
    if (!fin.good()) break; 
    fin >> c;
    fin.ignore(1000,10);
    
    //input validation
    if (c == -999)
    {
      break;
    }
    else if (c > 58 || c < -273){
      cout << "Fix the temperature " << c << " to a valid Celsius temperature in the file (-273.15 to 58.0)." << endl;
    } 
    else
    {
      //Converting Fahrenheit input to Celsius
      f = 9 / 5 * c + 32;
      //output results
      cout << c << " Celcius equals " << f << " Farenheit" << endl;
    }
  } while (c != -999); // do while 
  //Close file.  
  fin.close(); 

}//main
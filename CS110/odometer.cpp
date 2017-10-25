//Objective: simulates a car odometer
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip> //for formatting
#include <iostream> //for output
using namespace std;
 
#ifdef _WIN32 
#include <windows.h> //for windows systems
#else 
#include <unistd.h> //for unix systems
#endif 

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
  cout << "Objective: This program simulates a car odometer\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Data
  int miles = 0; //represent miles (2 digits width)
  int thousands = 0; //represent thousanth miles (2 digits width)
  int tenths = 0; //represent tenth miles (2 digits width)

  //output car odometer (Thousands|Tenths|Miles)
  cout << "Type CRTL-C to exit" << endl;
  cout << "Th|Te|M" << endl; 
  cout.fill('0'); //format the initial car odometer to 000000
  for (thousands = 0; thousands < 100; thousands++) 
  { 
    for (tenths = 0; tenths < 100; tenths++) 
    { 
      for (miles = 0; miles < 100; miles++) 
      { 
        cout << setw(2) << thousands << "|";
        cout << setw(2) << tenths << "|";
        cout << setw(2) << miles;
        cout.flush(); 
  
        #ifdef _WIN32 
        Sleep(1000); // one thousand milliseconds
        #else 
        sleep(1); // one second 
        #endif 
  
        cout << '\r'; // CR 
      } 
    } 
  } // for loop miles

}//main
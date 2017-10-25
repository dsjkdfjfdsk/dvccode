//Objective:  calculate change due in a transaction using these U.S. bills – no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.
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
  cout << "Objective: This program calculates change due in a transaction using these U.S. bills – no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.\n"; 
  cout << "Programmer: Ethan Chiu\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //DATA
  //change due
  int changeDue = 0;
  //amount owed
  int amountOwed = 146;
  //amount paid
  int cashPaid = 200;
  //total change due
  int totalChangeDue = cashPaid - amountOwed; 
  //number of $100000 bills
  int thousand100 = 0; 
  //number of $10000 bills
  int thousand10 = 0; 
  //number of $5000 bills
  int thousand5 = 0; 
  //number of $1000 bills
  int thousand = 0;  
  //number of $500 bills
  int hundred5 = 0; 
  //number of $100 bills
  int hundred = 0;  
  //number of $50 bills
  int fifty = 0;
  //number of $20 bills 
  int twenty = 0; 
  //number of $10 bills
  int ten = 0; 
  //number of $5 bills 
  int five = 0;  
  //number of $2 bills
  int two = 0; 
  //number of $1 bills
  int one = 0;  

  //calculate change due
  changeDue = totalChangeDue;
  thousand100 = changeDue / 100000;  
  changeDue = changeDue % 100000;  
  thousand10 = changeDue / 10000;
  changeDue = changeDue % 10000;
  thousand5 = changeDue / 5000;
  changeDue = changeDue % 5000;
  thousand = changeDue / 1000;
  changeDue = changeDue % 1000;
  hundred5 = changeDue / 500;
  changeDue = changeDue % 500;
  hundred = changeDue / 100;
  changeDue = changeDue % 100;
  fifty = changeDue / 50;
  changeDue = changeDue % 50;
  twenty = changeDue / 20;
  changeDue = changeDue % 20;
  ten = changeDue / 10;
  changeDue = changeDue % 10;
  five = changeDue / 5;
  changeDue = changeDue % 5;
  two = changeDue / 2; 
  changeDue = changeDue % 2; 
  one = changeDue / 1; 

  //output calculated change due for each kind of monetary demonination
  cout << "Amount owed: " << amountOwed << endl;
  cout << "Cash paid: " << cashPaid << endl;
  cout << "Total change due: " << totalChangeDue << endl;
  cout << " this many hundred thousand dollar bills: " << thousand100 << endl;
  cout << " this many ten thousand dollar bills: " << thousand10 << endl;
  cout << " this many five thousand dollar bills: " << thousand5 << endl;
  cout << " this many thousand dollar bills: " << thousand << endl;
  cout << " this five hundred dollar bills: " << hundred5 << endl;
  cout << " this many hundred dollar bills: " << hundred << endl;
  cout << " this many fifty dollar bills: " << fifty << endl;
  cout << " this many twenty dollar bills: " << twenty << endl;
  cout << " this many ten dollar bills: " << ten << endl;
  cout << " this many five dollar bills: " << five << endl;
  cout << " this many two dollar bills: " << two << endl;
  cout << " this many one dollar bills: " << one << endl;

}
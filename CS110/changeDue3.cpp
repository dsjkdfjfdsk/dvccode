//Objective: TEMPLATE
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

//Programmer defined functions
void introduction(string obj); //program introductions

//main program
int main()
{
  //Data
  string objective = "calculates change due in a transaction using these U.S. bills – no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.";
  int changeDue = 0; //change due
  int amountOwed; //amount owed
  int cashPaid; //amount paid
  int totalChangeDue; //total change due
  int thousand100 = 0; //number of $100000 bills
  int thousand10 = 0; //number of $10000 bills
  int thousand5 = 0; //number of $5000 bills
  int thousand = 0;  //number of $1000 bills
  int hundred5 = 0; //number of $500 bills
  int hundred = 0;  //number of $100 bills
  int fifty = 0; //number of $50 bills
  int twenty = 0; //number of $20 bills 
  int ten = 0; //number of $10 bills
  int five = 0;  //number of $5 bills 
  int two = 0; //number of $2 bills
  int one = 0;  //number of $1 bills
  ifstream fin; //to reserve identifier fin for reading a text file

  //program introduction
  introduction(objective);
  cout << "I will pause until you hit the enter key to check that the file change.txt has amount owed on line 1 and cash paid on line 2." << endl;
  
  //open up file and get amountOwed from first line and cashPaid from second line;
  do
  {
    fin.open("change.txt");
    if (!fin.good()) throw "I/O error"; 
  
    while (true) 
    { 
    if (!fin.good()) break; 
    string lineFromFile; 
    getline(fin, lineFromFile); 
    cout << lineFromFile << endl; 
  } // while 
  fin.close(); 


    //input validation
    if (amountOwed > cashPaid)
    {
      cout << "Amount owed is invalid. Please fix file input for line 1 (must be less than cashPaid)." << endl;
      cout << "Please press enter or any key to continue after fixing your file" << endl;  
      cin.ignore(1000,10); 
    }
    if (amountOwed < 0)
    {
      cout << "Amount owed is invalid. Please fix file input for line 1 (must be bigger than or equal to 0)." << endl;     
      cout << "Please press enter or any key to continue after fixing your file" << endl;  
      cin.ignore(1000,10); 
    }
    if (cashPaid < 0)
    {
      cout << "Cash paid is invalid. Please fix file input for line 2 (must be bigger than or equal to 0)." << endl;   
      cout << "Please press enter or any key to continue after fixing your file" << endl;  
      cin.ignore(1000,10);   
    }
  } while (cashPaid < 0 || amountOwed < 0 || amountOwed > cashPaid);

  //calculate change due
  totalChangeDue = cashPaid - amountOwed;
  changeDue =  totalChangeDue;
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
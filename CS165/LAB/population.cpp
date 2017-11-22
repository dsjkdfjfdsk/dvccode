//Objective: Read population from population text file
//Name: Ethan Chiu

//libraries
#include <fstream> //for file input
#include <iostream> //for input and output
#include <string>  //for using string built in functions
using namespace std;

int main()
{
  //Data
  int year = 1910;
  int population;
  ifstream fin;

  fin.open("Population.txt");
  if (!fin.good()) throw "I/O error"; 

  //reads and output population
  cout << "Hoboken Population Growth" << endl;
  while (fin >> population)
  { 
    cout << year << " ";
    while(population > 0)
    {
      population -= 1000;
      cout << "*";
    }
    cout << endl;
    year += 20;
  } // while 
  fin.close();

}



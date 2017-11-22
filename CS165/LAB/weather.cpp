//Objective: Read weather data
//Name: Ethan Chiu

//libraries
#include <fstream> //for file input
#include <iostream> //for input and output
#include <string>  //for using string built in functions
using namespace std;

int main()
{
  //Data
  const int SIZE = 12;
  string name[SIZE];
  int high[SIZE];
  int low[SIZE];
  int i = 0;
  ifstream fin;
  double average;

  fin.open("weather.txt");
  if (!fin.good()) throw "I/O error"; 

  //reads and output population
  cout << "Average temperatures" << endl;
  while (fin.good())
  { 
    if(i > 12)
    {
      cout << "Too many lines of input. Please keep it to 12 months" << endl;
      break;
    }
    fin >> name[i];
    fin >> high[i];
    fin >> low[i];
    i++;
  } // while 
  fin.close();

  //Calculate average
  for (int b = 0; b < 12; b++)
  {
    average = high[b] + low[b] / 2.0;
    cout << "Average temperature for " << name[b] << " is " << average << endl;
  }

}



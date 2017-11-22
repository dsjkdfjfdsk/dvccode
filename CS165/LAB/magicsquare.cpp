//Objective: Create Magic Square
//Name: Ethan Chiu

//libraries
#include <fstream> //for file input
#include <iostream> //for input and output
#include <string>  //for using string built in functions
using namespace std;

int main()
{
  //Data
  const int WIDTH = 3;
  const int HEIGHT = 3;
  int magicSquare [3][3];
  int sumColumn = 0;
  int sumRow = 0;
  int diagonal = 0;
  
  //Enter data for magic square
  cout << "Enter numbers of magic square (left to right, top to bottom): " << endl;

  //Add to array
  for(int i = 0; i < HEIGHT; i++)
  {
    for(int b = 0; b < WIDTH ; b++)
    {
      cout << "Row " << i << ", Column " << b << ": ";
      cin >> magicSquare[i][b];
      cin.ignore(1000,10);
    }
  }

  //Check if it's a magic square (columns, rows)
  for(int i = 0; i < HEIGHT; i++)
  {
    sumRow = 0;
    sumColumn = 0;
    for(int b = 0; b < WIDTH ; b++)
    {
      sumColumn += magicSquare[i][b];
      sumRow += magicSquare[b][i];
    }
    if(sumRow != sumColumn)
    {
      cout << "This is NOT a magic square";
      break;
    }
  }
  //Check if diagonal is the same
  diagonal = magicSquare[0][0] + magicSquare[1][1] + magicSquare[2][2];

  //Last check
  if(sumRow == diagonal)
  {
    cout << "This is a magic square";
  }
  else if (sumColumn == sumRow)
  {
    cout << "This is NOT a magic square";
  }
}




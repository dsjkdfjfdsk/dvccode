// HW 1 Maze
// Ethan Chiu

#include <fstream> //for file input
#include <iostream> //for input and output
#include <string>  //for using string built in functions
using namespace std;

int main()
{
  //Data
  const int length = 10;
  const int width = 10;
  char maze[length][width];
  string temp;
  ifstream fin;
  int z = 0;
  int row = 0;
  int column = 0;

  //open file
  fin.open("maze.txt");
  if (!fin.good()) throw "I/O error"; 

  //input maze from file
  while(!fin.eof())
  {
    getline(fin, temp);
    for (int a = 0; a < temp.length(); a++)
    {
      maze[z][a] = temp[a];
    }

    for (int k = temp.length(); k < length; k++)
    {
      maze[z][k] = ' ';
    }

    z++;
  }

  //output maze
  for(int i = 0; i < length; i++)
  {
    for(int b = 0; b < width; b++)
    {
      cout << maze[i][b];
    }
    cout << endl;
  }

  fin.close();
}
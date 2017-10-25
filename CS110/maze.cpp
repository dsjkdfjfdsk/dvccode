// HW 1 Maze
// Ethan Chiu

#include <fstream> //for file input
#include <iostream> //for input and output
#include <string>  //for using string built in functions
using namespace std;

int main()
{
  //Data
  char maze[][];
  ifstream fin;
  int row = 0;
  int length = 0;

  fin.open("maze.txt");
  if (!fin.good()) throw "I/O error"; 

  cout << "Maze" << endl;
  while(fin.getline(maze[row], length+1))
  {
    row++;
  }
}
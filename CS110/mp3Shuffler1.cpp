//Objective: reads all song titles from a text file, and randomly select and output titles in a loop until the user wishes to stop
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <cstdlib> //for rng
#include <ctime> //for rng
#include <fstream> //for file input
#include <iostream> //for output
#include <string>  //for using string built in functions
using namespace std;

//Programmer defined data types

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //program introductions

//main program
int main()
{
  //seed random initializer
  srand(time(0));

  //Data
  string objective = "reads all song titles from a text file, and randomly select and output titles in a loop until the user wishes to stop";
  string filename = "songs.txt"; //input file name
  const int MAXSONGS = 200; //max amount of songs
  bool continueYN; //to continue getting songs or not
  string song[MAXSONGS]; //songs array
  string currentLine; //current line of the song
  int nSongs = 0; //iterator for if loop
  char userAnswer; //Yes or no for the song
  ifstream fin; //for file input
  string showSong; //song to be showed
  int randomNumber; //random index for song chosen

  //program introduction
  introduction(objective);
  
  //Add songs to file
  fin.open(filename.c_str());
  while(fin.good())
  {
    getline(fin, currentLine);
    if(nSongs < MAXSONGS)
    {
      song[nSongs++] = currentLine;
    } //if
  } // while
  fin.close();

  //Select song randomly to show user. Asks if the user wants to continue or not
  do
  {
    //Ask yes or no to play song
    cout << "play a song [Y/N]?: ";
    cin >> userAnswer;
    cin.ignore(1000,10);

    //Checks to see what user inputted and outputs random song if yes
    if(toupper(userAnswer) == 'Y')
    {
      continueYN = true;
      randomNumber = rand() % nSongs;
      showSong = song[randomNumber];
      cout << showSong << endl;
    }
    else if(toupper(userAnswer) == 'N')
    {
      continueYN = false;
    }
    else 
    {
      cout << "" << endl;
      continueYN = true;
    } // if else
  } while (continueYN); //do while
  
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
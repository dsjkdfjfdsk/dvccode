//Objective: reads all song titles from a text file, and randomly select and output titles in a loop until the user wishes to stop. Doesn't playing any song in the last 5 songs
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <cstdlib> //for rng
#include <ctime> //for rng
#include <deque> //for collections
#include <fstream> //for file input
#include <iostream> //for output
#include <string>  //for using string built in functions
using namespace std;

//Programmer defined data types
struct Song
{
  string name;
}; //Song

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
  int nSongs = 0; //iterator for if loop
  char userAnswer; //Yes or no for the song
  ifstream fin; //for file input
  string showSong; //song to be showed
  int randomNumber; //random index for song chosen
  deque<Song> song; //songs collection
  deque<Song> lastFiveSongs; //last five songs collection
  bool playedFive; //if played in last five songs
  Song aSong; //temp song object
  int b = 0; //iterator
  
  //program introduction
  introduction(objective);
  
  //Add songs to collection from file
  fin.open(filename.c_str());
  while(fin.good())
  {
    getline(fin, aSong.name);
    if(nSongs < MAXSONGS)
    {
      song.push_back(aSong);
      nSongs++;
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

      //Checks to see if song was in the past 5 songs
      do
      {
        randomNumber = rand() % nSongs;
        aSong = song[randomNumber];
        playedFive = false;
        for(b; b < lastFiveSongs.size(); b++)
        {
          if(aSong.name == lastFiveSongs[b].name)
          {
            playedFive = true;
          }
          else if((b == lastFiveSongs.size() - 1) && playedFive != true)
          {
            playedFive = false;
          }
        } //for loop
        b = 0;
      } while (playedFive); //do while

      //Add song
      showSong = aSong.name;
      lastFiveSongs.push_back(aSong);
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

    //Clear out 6th song in last five songs if applicable
    if (lastFiveSongs.size() > 5)
    {
      lastFiveSongs.pop_front();
    }
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
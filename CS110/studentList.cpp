//Objective: TEMPLATE
//Name: Ethan Chiu
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//Programmer defined data types
struct Student
{
  string name;
  int id;
  float gpa;
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //program introductions
void outputStudents(Student* student, int nStudents); //output students

//main program
int main()
{
  //Data
  string objective = "template for C++ programs and to test code";
  const int MAX_STUDENTS = 100; // list capacity
  int nStudents = 0; // initially empty
  Student student[MAX_STUDENTS];    // create an empty list

  //program introduction
  introduction(objective);

  // open a file for input
  ifstream fin;
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
 
  // read and save the records
  while (fin.good())
  {
    // create a record and read it from file
    Student aStudent;
    getline(fin, aStudent.name);

    fin >> aStudent.id;
    fin.ignore(1000, 10);
 
    fin >> aStudent.gpa;
    fin.ignore(1000, 10);
 
    fin.ignore(1000, 10); // skip the ---------- separator

    // add record to list, if it's not full
    if (nStudents < MAX_STUDENTS)
      student[nStudents++] = aStudent;
  }
  fin.close();
 
  // sort the students by name
  for (int i = 0; i < nStudents; i++)
  {
    for (int j = i + 1; j < nStudents; j++)
    {
      if (student[i].name > student[j].name)
      {
        Student temp = student[i];
        student[i] = student[j];
        student[j] = temp;
      }
    }
  }

  outputStudents(student, nStudents);

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

void outputStudents(Student* s, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    cout << "Name = " << left << setw(30) << s[i].name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7)
      << s[i].id << ", gpa = "
      << s[i].gpa << endl;
    cout.fill(' '); 
  }
}
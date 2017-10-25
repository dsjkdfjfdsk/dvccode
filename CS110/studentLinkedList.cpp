#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Student
{
  string name;
  int id;
  float gpa;
  Student* next; // the next-link
}; // Student
 
int main()
{
  // open a file for input
  ifstream fin;
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
 
  // create an empty linked list
  Student* start = 0;
 
  // read and save the records
  while (fin.good())
  {
    // Step 1, create a node
    Student* aStudent = new Student;

    // Step 2, read its data fields
    getline (fin, aStudent->name);

    fin >> aStudent->id;
    fin.ignore(1000, 10);
 
    fin >> aStudent->gpa;
    fin.ignore(1000, 10);
 
    fin.ignore(1000, 10); // skip the separator line

    // Step 3, add new node to the list
    aStudent->next = start;
    start = aStudent;
  }
  fin.close();
 
  // traverse the list and output
  Student* p;
  for (p = start; p; p = p->next)
  {
    cout << "Name = " << left << setw(30) << p->name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7) << p->id
      << ", gpa = " << p->gpa << endl;
    cout.fill(' '); 
  }
}
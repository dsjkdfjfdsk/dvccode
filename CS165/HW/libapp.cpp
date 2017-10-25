// Ethan Chiu
// Library Application HW
#include "Person.h"
#include "Book.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Person people[4];
    //bob, mary, george, greg;
    
    people[0] = Person(123, "Bob Fud", "bob@gmail.com");
    people[1] = Person(13,"Mary Drive","mary@ddd.com");
    people[2] = Person(2, "George Bre", "george@ddd.com");
    people[3] = Person(1, "Greg Fry", "greg@yoyoyo.com");
    
    people[3].setName("Nathan Fried");
    
    for (int i = 0; i < 4; i++)
    {
      cout << left << setw(5) << "Name: " << right << setw(20) << people[i].getName();
      cout << left << setw(5) << " ID: " << right << setw(20)  << people[i].getID();
      cout << left << setw(5) <<  " Email address: " << right << setw(20) << people[i].getEmail();
      cout << endl;
    }

    Book book[6];
    book[0] = Book("Art of War", "Sun Tze", false);
    book[1] = Book("Winnie", "George Car", false);
    book[2] = Book("Driven Car", "Dan Gaily", false);
    book[3] = Book("Stolen dred", "Fred Arm", false);
    book[4] = Book("Franzie Derli", "Relindkes", false);
    book[5] = Book("Boyish Nred", "Rkdlr", false);

    book[0].checkOut(&people[0]);
    book[0].checkIn();
    

    book[1].checkOut(&people[3]);
    book[2].checkOut(&people[3]);
    book[3].checkOut(&people[3]);
    book[4].checkOut(&people[2]);

    for (int i = 0; i < 6; i++)
    {
      cout << left << setw(10) <<"Book Title: " << setw(20) << book[i].getTitle();
      //cout << left << setw(10) << "Author: " << book[i].getAuthor();
      //cout << left << setw(10) <<"Status: " << setw(20) << book[i].getStatus();
      Person *currentPerson = book[i].getPointer();
      cout << left << setw(10) <<"Pointer: " << setw(20) << book[i].getPointer();  
      if(book[i].getPointer() != NULL)
      {
        cout << "Borrowed by: " << currentPerson->getName();
      }
      else
      {
        cout << "Borrowed by: NONE";
      }

      cout << endl;
    }
    
}
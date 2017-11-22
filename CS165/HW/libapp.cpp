#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        string name;
        int id;
        string email;
    public:
        Person ()
        {}
        Person(int userID, string userName, string userEmail)
        {
            name = userName;
            id = userID;
            email = userEmail;
        }

        void setName(string userName)
        {
            name = userName;
        }
        void setID(int userID)
        {
            id = userID;
        }
        void setEmail(string userEmail)
        {
            email = userEmail;
        }
        int getID()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        string getEmail()
        {
            return email;
        }
};

class Book
{
    private:
        string title;
        string author;
        bool status;
        Person *borrower;
    public:
        Book ()
        {}
        Book (string bookTitle, string bookAuthor, bool bookStatus)
        {
            title = bookTitle;
            author = bookAuthor;
            status = bookStatus;
            borrower = NULL;
        }
        void setTitle(string bookTitle)
        {
            title = bookTitle;
        }
        void setAuthor(string bookAuthor)
        {
            author = bookAuthor;
        }
        void setStatus(bool bookStatus)
        {
            status = bookStatus;
        }
        void setPointer(Person *bookPointer)
        {
            borrower = bookPointer;
        }
        string getTitle()
        {
            return title;
        }
        string  getAuthor()
        {
            return author;
        }
        bool getStatus()
        {
            return status;
        }
        Person *getPointer()
        {
            return borrower;
        }
        void checkOut(Person *user)
        {
            if(status != true) 
            {
                status = true;
                borrower = user;
                //return true;
            }
            else
            {
                //return false;
            }
        }
        void checkIn()
        {
            status = false;
            borrower = NULL;
        }
};



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



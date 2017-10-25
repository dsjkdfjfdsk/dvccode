#ifndef BOOK_H
#define BOOK_H
#include <string> 
using namespace std;

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

#endif
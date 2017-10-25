#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <string> 
using namespace std;

//Class that creates a Publication object with title, author, status, borrower. Can check out and check in publication objects.

class Publication
{
    private:
        string title;
        string author;
        bool status;
        Person *borrower;
    public:
        Publication ()
        {}
        Publication (string publicationTitle, string publicationAuthor, bool publicationStatus)
        {
            title = publicationTitle;
            author = publicationAuthor;
            status = publicationStatus;
            borrower = NULL;
        }
        void setTitle(string publicationTitle)
        {
            title = publicationTitle;
        }
        void setAuthor(string publicationAuthor)
        {
            author = publicationAuthor;
        }
        void setStatus(bool publicationStatus)
        {
            status = publicationStatus;
        }
        void setPointer(Person *publicationPointer)
        {
            borrower = publicationPointer;
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
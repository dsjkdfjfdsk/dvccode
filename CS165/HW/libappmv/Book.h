#ifndef BOOK_H
#define BOOK_H
#include <string> 
using namespace std;

//Book class with duration and format members. Derived from Publication class
class Book : public Publication
{
    private:
        int pages;
        string format;
    public:
        Book ()
        {}
        Book (int bookPages, string bookFormat)
        {
            pages = bookPages;
            format = bookFormat;
        }
        void setPages(int bookPages)
        {
            pages = bookPages;
        }
        void setFormat(string bookFormat)
        {
            format = bookFormat;
        }
        string getFormat()
        {
            return format;
        }
        int  getPages()
        {
            return pages;
        }
};

#endif
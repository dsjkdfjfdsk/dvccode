// Example program
#include <iostream>
#include <string>

using namespace std;

enum format {mp3, wav};
class Publication
{
    protected:
        string title;
    public:
        void setTitle(string a)
        { 
            title=a;
        };
        virtual void showData()
        {
            cout<<"";
        };
        
};

class Book: public Publication
{
    public:
        int pages;
        void showData()
        {
            cout << title;
            cout << "    ";
            cout << pages;
        };
};

class Video: public Publication
{
    public:
        int resolution;
        void showData()
        {
            cout << title;
            cout << "    ";
            cout << resolution;
        };
};

class Music: public Publication
{
    public:
        format musicFormat;
        void showData()
        {
            cout << title;
            cout << "    ";
            cout << musicFormat;
        };

};

int main()
{
    //Test Data
    Book a, b;
    Video c, d;
    Music e, f;
    Publication* publicationPtrs[6];
    publicationPtrs[0] = &a; 
    a.pages = 100;
    a.setTitle("fdsdfsdf");
    publicationPtrs[1] = &b; 
    b.pages = 180;
    b.setTitle("fdsddddddfsdf");
    
    publicationPtrs[2] = &c; 
    publicationPtrs[3] = &d; 
    c.resolution = 720;
    c.setTitle("burh");
    d.resolution = 1080;
    d.setTitle("fejksd");
    
    publicationPtrs[4] = &e; 
    publicationPtrs[5] = &f; 
    e.musicFormat = mp3;
    e.setTitle("Sdf");
    f.musicFormat = wav;
    f.setTitle("dsfdf");
    
    //Output Data
    cout << "Type    Title    Other" << endl;
    cout << "---     -----    -----" << endl;
    
    for(int i = 0; i <2; i++)
    {
        cout << "Book    ";
        (*publicationPtrs[i]).showData();
        cout << endl;
    }
    
    for(int i = 2; i <4; i++)
    {
        cout << "Video    ";
        (*publicationPtrs[i]).showData();
        cout << endl;
    }
    
    for(int i = 4; i <6; i++)
    {
        cout << "Music    ";
        (*publicationPtrs[i]).showData();
        cout << endl;
    }
    
    
}




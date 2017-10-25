#ifndef PERSON_H
#define PERSON_H
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

#endif
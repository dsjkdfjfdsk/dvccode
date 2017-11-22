// Dynamic Memory Allocation
#include <iostream>
#include <string>

using namespace std;

class Students
{
    private:
        string name;
        int id;
        
    public:
        Students (string userName, int userID)
        {
            name = userName;
            id = userID;
        }
        void setName(string userName)
        { name = userName; }
        void setID(int userID)
        { id = userID; }
        string getName() 
        { return name; } 
        int getID()
        { return id; }

};

Students* createStudent()
{
    Students *studentPtr = new Students("Ethan", 123);
    return studentPtr;
}

void displayStudent(Students *studentPtr)
{
    cout << "Student's name: " << studentPtr->getName() << endl;
    cout << "Student's id: " <<studentPtr->getID()<< endl;
}

void deleteStudent(Students *studentPtr)
{
    delete studentPtr;
}
int main()
{
    Students *user = createStudent();
    
    //Test displaying user
    displayStudent(user);
    deleteStudent(user);
    
    //See if user is deleted
    displayStudent(user);
}



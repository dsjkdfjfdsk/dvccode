// Car Class Ethan Chiu
#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        int year, speed;
        string make;
        
    public: 
        Car(int yearUser, string makeUser)
        {
            year = yearUser; 
            speed = 0;
            make = makeUser;
        }
        int getYear()
        {
            return year;
        }
        string getMake()
        {
            return make;
        }
        int getSpeed()
                {
            return speed;
        }
        void accelerate()
        {
            speed += 5;
        }
        void brake()
        {
            speed -= 5;
        }
};

int main()
{
    Car car(1980, "Tesla");
    cout << car.getMake() << endl;

    for(int i = 0; i < 5; i++)
    {
        car.accelerate();
        cout << car.getSpeed() << endl;
    }
    for(int i = 0; i < 5; i++)
    {
        car.brake();
        cout << car.getSpeed() << endl;
    }
}




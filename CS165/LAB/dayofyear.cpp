#include "DayOfYear.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    int day = 1000000;
    string date;
    DayOfYear temp; 

    cout << "Input number between 1-365: ";
    cin >> day;
    cin.ignore(1000,10);
    while(day != 0 && day >= 1 && day <= 365)
    {
        date = temp.translate(day);
        temp.print(date);       
        temp = DayOfYear(day);
        
        cout << "Input number between 1-365: ";
        cin >> day;
        cin.ignore(1000,10);
    }
    
}
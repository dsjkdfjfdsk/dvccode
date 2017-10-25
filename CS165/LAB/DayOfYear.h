#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <iomanip>
#include <locale>
#include <sstream>
#include <string> 
#include <iostream>
using namespace std;

class DayOfYear
{
    private:
        int day;

    public:
        static const string monthName[];
        static const int monthDays[];
        static string date;
        DayOfYear(int userDay)
        {
            day = userDay;
        }
        
        DayOfYear()
        {

        }
        static string translate(int userDay)
        {
            int month;
            int dayshere;
            for(int i = 0; i < 12; i++)
            {
                dayshere = userDay - monthDays[i];
                if(dayshere <= 0)
                {
                    month = i;
                    dayshere = userDay;
                    break;
                }
                userDay -= monthDays[i];
            }
            return (monthName[month] + " " + to_string(dayshere));
        }
        void print(string date)
        {
            cout << date << endl;
        }
};

const string DayOfYear::monthName[ ] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int DayOfYear::monthDays[ ] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


#endif
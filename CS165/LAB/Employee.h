#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string> 
using namespace std;

class Employee
{
  private:
    string lastName;
    double hourlyPay;
    int hours;
  public:
    Employee()
    {
    }
    void setName(string name)
    { lastName = name; }
    void setPay(double pay)
    { hourlyPay = pay; }
    void setHours(int hrs)
    { hours = hrs; }
    string getName() 
    { return lastName; } 
    double getPay() 
    { return hourlyPay; }
    int getHours()
    { return hours; }
    double totalPay()
    {
      return hours * hourlyPay;
    }
};

#endif

#include "Employee.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  double pay;
  int hours;
  string name; 
  double totalPay;

  Employee employee[4];

  for (int i = 0; i < 4; i++)
  {
    cout << "Input Last Name: ";
    getline(cin, name);

    cout << "Input pay rate: ";
    cin >> pay;
    cin.ignore(1000,10);

    cout << "Input hours: ";
    cin >> hours;
    cin.ignore(1000, 10);

    employee[i].setName(name);
    employee[i].setPay(pay);
    employee[i].setHours(hours);
    
  }

  cout << setw(10) << left << "Employee ";
  cout << setw(10) << left << "Name ";
  cout << setw(10) << left << "Gross pay ";
  cout << endl;
  cout << setw(10) << left << "========";
  cout << setw(10) << left << "====";
  cout << setw(10) << left << "=========";   
  cout << endl;

  for (int i = 0; i < 4; i++)
  {
    totalPay = employee[i].getPay();
    cout << setw(10) << left << i;
    cout << setw(10) << left << employee[i].getName();
    cout << setw(10) << left << fixed << showpoint << setprecision(2) << totalPay;
    cout << endl;
  }


}


#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#include <math.h>;

int main()
{
	//Data
	double balance;
	double rate;
	int time; //number of times compounded during a year
	double interest; //final interest
	double finalBalance; //final balance

	//Get user input 
	cout << "What's your principal balance? ";
	cin >> balance;
	cin.ignore(1000, 10);
	cout << "What's your interest rate? ";
	cin >> rate;
	cin.ignore(1000, 10);
	cout<< "What's the number of times the interest is compounded? ";
	cin >> time;
	cin.ignore(1000, 10);
	cout << endl;

	//Calculations
	rate = rate / 100;
	finalBalance = balance * pow((1 + rate / time), time);
	interest = finalBalance - balance;

	cout << left << setw(25) <<  "Interest Rate: " << right << setw(8) << rate * 100 << "%" << endl;
	cout << left << setw(25) << "Times Compounded: " << right << setw(8) << time << endl;
	cout << fixed;
	cout << setprecision(2);
	cout << left << setw(25) << "Principal: " << "$" << right << setw(8) <<balance << endl;
	cout << left << setw(25) <<  "Interest: " << "$" << right << setw(8) <<interest << endl;
	cout << left << setw(25) <<  "Final balance: " << "$" << right << setw(8) <<finalBalance << endl;

	return 0;
}




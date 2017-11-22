#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#include <math.h>;

int main()
{
	//Data
	int income;
	int tax;
	int leftAmount;

	//Get user input 
	cout << "What's your total income? ";
	cin >> income;

	//Calculations
	tax = 0;
	leftAmount = income;
	if (income <= 25000)
	{
	    tax = 0;
	}
	else if (income > 25000 && income <= 48000)
	{
	    tax = .15 * (income - 25000);
	}
	else if (income > 48000 && income <= 90000)
	{
	    tax = .15 * (48000 - 25000);
	    tax = tax + .25 * (leftAmount - 48000);
	}
	else if (income > 90000 && income <= 200000)
	{
	    tax = .15 * (48000 - 25000);
	    tax += .25 * (90000 - 48000);
	    tax = tax + .3 * (leftAmount - 90000);
	}
	else
	{
        tax = .15 * (48000 - 25000);
	    tax += .25 * (90000 - 48000);
	    tax += .3 * (200000 - 90000);
	    tax = .25 * (leftAmount - 200000);
	}
	
	cout << left << setw(25) <<  "Taxes total: " << "$" << tax << endl;

	return 0;
}



// ProgrammingChallengeStockLoss.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

int main()
{
	//Data
	int numStocksBought = 750;
	double stockPriceBought = 35;
	double stockPriceSold = 31.15;
	double priceBought = numStocksBought * stockPriceBought;
	double priceSold = numStocksBought * stockPriceSold;

	cout << "Total amount paid for the stock: $" << priceBought << endl;
	cout << "Total amount received from selling the stock: $" << priceSold << endl;
	cout << "Total amount of money lost: $" << priceBought - priceSold << endl;

	return 0;
}



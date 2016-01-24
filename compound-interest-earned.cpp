/*
–-----------------------------------------------------------------------------------------------------------------------------------------
Adam Allard
CISS-241
Week 3
Assignment 1
Compound Interest Earned
–-----------------------------------------------------------------------------------------------------------------------------------------
Assume no additional deposits are made other than the
original investment. The balance in an account after one year may be calculated as:

New Balance = Principal * (1 + rate/T)^T

Principal is the opening balance in the account. Rate is the interest rate, and T is the number
of times the interest is compounded during a year (T is 4 if the interest is compounded
quarterly).  Write a program that prompts the user for the principal, the interest rate, and
the number of times the interest is compounded. The output must be formatted in the
following format.

Interest Rate:            4.25%
Times Compounded:            12
Principal:             $1000.00
Interest:              $  43.34
Amount in Savings:     $1043.34
–----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int    timesCompounded;
	double interestRate,
		   intRateOver100,
		   princicapBal,
		   interestAmount,
		   savingsTotal;

	// prompt user for account info and store in appropriate variables
	cout << "What is the principal balance?\n";
	cin >> princicapBal;
	cout << "What is the interest rate?\n";
	cin >> interestRate;
	cout << "How many times is the interest compounded in a year?\n";
	cin >> timesCompounded;
	cout << endl;

	// calculate unknown values for variables of account
	intRateOver100 = interestRate / 100;
	savingsTotal = princicapBal * pow(1 + (intRateOver100 / timesCompounded), timesCompounded);
	interestAmount = savingsTotal - princicapBal;

	// display account info with correct formatting
	cout << setprecision(2) << fixed << showpoint;
	
	cout << left << setw(25) << "Interest Rate: "           << right << setw(8) << interestRate << "%" << endl;
	cout << left << setw(25) << "Times Compounded: "        << right << setw(9) << timesCompounded << endl;
	cout << left << setw(25) << "Principal: "        << "$" << right << setw(8) << princicapBal << endl;
	cout << left << setw(25) << "Interest: "         << "$" << right << setw(8) << interestAmount << endl;
	cout << left << setw(25) << "Amount in Savings: "<< "$" << right << setw(8) << savingsTotal << endl;

	system("pause");
	return 0;
}

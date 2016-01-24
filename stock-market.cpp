/*
–-----------------------------------------------------------------------------------------------------------------------------------------
Adam Allard
CISS-241
Week 2
Assignment 2
Stock Market 
–-----------------------------------------------------------------------------------------------------------------------------------------
Cathy bought 600 shares of stock at a price of $21.77 per share. She must pay 
the stock broker a 2 percent commission for the transaction. Write 
a program that calculates 
and displays the following:
   1.The amount paid for the stock alone (without the commission)
   2.The amount of the commission
   3.The total amount paid (for the stock plus the commission)
   4.What is the minimal price for the stocks she would need to make a profit if she were to sell the stocks? 
      (Assume she will not pay a commission when she sells the stock.)
–----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int numShares = 600;
	double sharePrice = 21.77,
		     commissionPerTran = .02,
		     stockBasePrice,
	       commissionAddOn,
		     totalStockPrice,
		     sellStockAt;

	// calculate all the unknown value variables
	stockBasePrice = numShares * sharePrice;
	commissionAddOn = stockBasePrice * commissionPerTran;
	totalStockPrice = stockBasePrice + commissionAddOn;
	sellStockAt = (totalStockPrice / numShares) + .01;

	// set the desired output formatting for numbers
	cout << setprecision(2) << fixed << showpoint;

	// display all the values
	cout << "The amount paid for the stock alone is $" << stockBasePrice << endl;
	cout << "The amount of commission for the transaction is $" << commissionAddOn << endl;
	cout << "The total amount paid for the stock plus commission is $" << totalStockPrice << endl;
	cout << "The minimum price to sell the stock at in order to return a profit is $" << sellStockAt << endl;

	system("pause");
	return 0;
}

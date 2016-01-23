/*
–-----------------------------------------------------------------------------------------------------------------------------------------
Adam Allard
CISS-241
Week 2
Assignment 1 
Miles per gallon of Gas 
–-----------------------------------------------------------------------------------------------------------------------------------------
A car with a 16-gallon gas tank averages 345 miles per tankful when driven in town and 460 miles per tankfulwhen driven on the highway. 
Write a program that calculates and displays the miles per gallon for one tank of gas when driven in town and when driven on the highway.
The MPG should have a data type of a double. 
MPG = Total number of Miles / Number of Gallons
–----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
	int fullTank = 16,
	    townMilesAvg = 345,
	    highwayMilesAvg = 460;

	double mpgTown,
	       mpgHighway;

	//calculate miles per gallon in town and on highway
	mpgTown = townMilesAvg / fullTank;
	mpgHighway = highwayMilesAvg / fullTank;

	// display the results
	cout << "The vehicle gets " << mpgTown << " miles per gallon when driven in town, \nand " 
		 << mpgHighway << " miles per gallon when driven on the highway.\n";

	// this statement is needed to avoid the program from closing immediately 
	system("pause");
	return 0;
}

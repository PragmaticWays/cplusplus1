/*
–---------------------------------------------------------------------------------------------------------------------------------------- -
Adam Allard
CISS - 241
Week 7
Assignment 1
Rainfall Statistics
–---------------------------------------------------------------------------------------------------------------------------------------- -
Write a program that lets the user enter the total rainfall for each of 12 months into an array of doubles. 
The program should use two 12 - element arrays. 
One array will hold strings, the names of the 12 months. 
This array will be initialized when the array is created using an initialization list (could also be created as a array of constants).
The second array will hold doubles which will be the total rainfall for each month. 
The program will prompt the user for the rainfall for each month (using both arrays) and store the value entered 
into the array with the rainfall totals; the other is usedto display which month the program is asking for the rainfall total. 

The program should display the following once the data is all entered:
   The total rainfall for the year
   The average monthly rainfall
   The month with the highest amount of rainfall (must display the month as a string)
   The month with the lowest amount of rainfall (must display the month as a string)

The program must have the following functions:
   double getTotal(double [ ], int);
   double getAverage(double [ ], int);
   double getLowest(double [ ],int, int&); //returns the lowest value, provides the index of the lowest value in the last parameter.
   double getHighest(double [ ], int, int&); //returns the highest value, provides the index of the highest value in the last parameter.
–---------------------------------------------------------------------------------------------------------------------------------------- -
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double getTotal(double[], int);
double getAverage(double[], int);
double getLowest(double[], int, int&);
double getHighest(double[], int, int&);

const int MONTHS = 12;
string months[MONTHS] = { "January", "February", "March", "April", "May", "June",
					  "July", "August", "September", "October", "November", "December" };
double rainFall[12];

int main()
{
	// get the rainfall for the 12 months
	cout << "Enter the rainfall for:" << endl << endl;
	for (int index = 0; index < 12; index++)
	{
		cout << left << setw(10);
		cout << months[index] << ": " << setw(5);
		cin >> rainFall[index];
	}

	int lowestMonth, highestMonth;
	double low, high;

	cout << endl;
	cout << "The total rainfall is "	<< getTotal(rainFall, MONTHS) << endl;
	cout << "The average rainfall is "  << getAverage(rainFall, MONTHS) << endl;

	low = getLowest(rainFall, MONTHS, lowestMonth);
	high = getHighest(rainFall, MONTHS, highestMonth);

	cout << months[lowestMonth] << " has the lowest rainfall at " << low << endl;
	cout << months[highestMonth] << " has the highest rainfall at " << high << endl << endl;

	system("pause");
	return 0;
}

double getTotal(double rainfall[], int size)
{
	double total = 0;
	for (int index = 0; index < size; index++) 
	{
		total += rainfall[index];
	}
	return total;
}

double getAverage(double rainfall[], int months)
{
	double average = getTotal(rainfall, MONTHS) / months;
	return average;
}

double getLowest(double rainfall[], int size, int &lowestIndex)
{
	double lowest = rainfall[0];
	for (int index = 0; index < size; index++)
	{
		if (rainfall[index] <= lowest)
		{
			lowest = rainfall[index];
			lowestIndex = index;
		}
	}
	return lowest;
}
double getHighest(double rainfall[], int size, int &highestIndex)
{
	double highest = rainfall[0];
	for (int index = 0; index < size; index++)
	{
		if (rainfall[index] >= highest)
		{
			highest = rainfall[index];
				highestIndex = index;
		} 
	}
	return highest;
}




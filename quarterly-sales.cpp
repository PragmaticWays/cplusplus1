/*
–---------------------------------------------------------------------------------------------------------------------------------------- -
Adam Allard
CISS - 241
Week 7
Assignment 2
Quarterly Sales
–---------------------------------------------------------------------------------------------------------------------------------------- -
Write a program that calculates information about sales during a year. 
This program will have anarray that will hold the sales totals for 4 divisions 
(North, South, East and West, stored in an array as strings for the output) and for 4 quarters. 
This array will also hold the total for each division and for each quarter. 
These totals will be calculated by the program once the values have been inputted by the user. 
So this array will be a 2 - dimensional array with the quarters as the columns and the divisions as the rows. 
The last column will hold the totals for the rows (division totals) and the last row will hold the totals for the columns (quarter totals). 
The program must use/create the following functions:
   double getTotal(int [][COLS]) // gets the total of the complete array except for the totals in the last column and last row.
   double getAverage(int [][COLS]) // return the average of all the values in the array except for the column and row with the totals in them.
   double getRowTotal(int [][COLS], int) // returns the total for row that is specified by the second parameter to the function.
   double getColumnTotal(int [][COLS], int) // returns the total for a column that is specified by the second parameter to the function.
   double getHighest (int [][COLS], int&, int&) //returns the highest value in the array.Last two parameters are 
                     the index values of where the highest value is located in the 2D array; 
					 these can then be used to display which division and quarter.
   double getLowest(int [][COLS], int&, int&) //returns the lowest value in the array. Last two parameters are 
                     the index values of where the highest value is located in the 2D array, 
					 these can then be used to display which division and quarter.

The program should output a table in the same format as below which will then be followed by the division and quarter with the highest 
value and the division and quarter with the lowest value.

                 Quarter 1    Quarter 2    Quarter 3    Quarter 4    Division Total
North
South
East
West
Quarter Total
–---------------------------------------------------------------------------------------------------------------------------------------- -
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int COLS = 5;
const int ROWS = 5;

double total = 0;
double average;
double lowest;
double highest;

double sales[ROWS][COLS];

double getTotal(double[][COLS]);
double getAverage(double[][COLS]);
double getRowTotal(double[][COLS], int);
double getColumnTotal(double[][COLS], int);
double getHighest(double[][COLS], int&, int&);
double getLowest(double[][COLS], int&, int&);

int main()
{
	const int divNum = 5, qtrNum = 5;
	double rowTotal, columnTotal;

	string div[divNum] = { "North", "South", "East", "West", "Quarter Total" };
	string qtr[qtrNum] = { "Quarter 1", "Quarter 2", "Quarter 3", "Quarter 4", "Division Total" };

	// get the sales info
	cout << "Enter the sales info:" << endl << endl;
	for (int strDivIndex = 0; strDivIndex < COLS; strDivIndex++)
	{
		if (strDivIndex == (COLS - 1))
		{
			for (int i = 0; i < COLS; i++)
			{
				rowTotal = getRowTotal(sales, i);
				sales[i][strDivIndex] = rowTotal;
			}
			break;
		}
		for (int strQtrIndex = 0; strQtrIndex < ROWS; strQtrIndex++)
		{
			if (strQtrIndex == (ROWS - 1))
			{
				for (int i = 0; i < COLS; i++)
				{
					columnTotal = getColumnTotal(sales, i);
					sales[strQtrIndex][i] = columnTotal;
				}
				break;
			}
			cout << div[strDivIndex] << " - " << qtr[strQtrIndex] << ": ";
			cin >> sales[strDivIndex][strQtrIndex];
		}
		cout << endl;
	}

	cout << setprecision(2) << fixed << showpoint;

	// display table
	cout << "\t\t";
	for (int i = 0; i < divNum; i++)
	{
		if (i < (divNum - 1))
		{
			cout << setw(12) << qtr[i];
		}
		else
		{
			cout << setw(15) << qtr[i];
		}

	}
	cout << endl;
	for (int row = 0; row < ROWS; row++)
	{
		cout << div[row];
		if (row < (ROWS - 1))
		{
			cout << "\t\t";
		}
		else
		{
			cout << "\t";
		}
		for (int col = 0; col < COLS; col++)
		{
			if (col < (COLS - 1))
			{
				cout << setw(12) << sales[row][col];
			}
			else
			{
				cout << setw(15) << sales[row][col];
			}
		}
		cout << endl;
	}

	// call functions and display total, average, lowest, and highest
	total = getTotal(sales);
	cout << endl << "Company total sales: " << total << endl;

	average = getAverage(sales);
	cout << "Company average sales: " << average << endl;

	int row, col;
	highest = getHighest(sales, row, col);
	cout << div[row] << " Division has the highest sales at " << highest <<
		" in " << qtr[col] << endl;

	lowest = getLowest(sales, row, col);
	cout << div[row] << " Division has the lowest sales at " << lowest <<
		" in " << qtr[col] << endl << endl;

	// end of program
	system("pause");
	return 0;
}



// functions

double getTotal(double numbers[][COLS])
{
	for (int x = 0; x < (ROWS - 1); x++)
	{
		for (int y = 0; y < (COLS - 1); y++)
		{
			total += numbers[x][y];
		}
	}
	return total;
}

double getAverage(double numbers[][COLS])
{
	double index = 0;
	double avgTot = 0;
	for (int x = 0; x < (ROWS - 1); x++)
	{
		for (int y = 0; y < (COLS - 1); y++)
		{
			avgTot += numbers[x][y];
			index++;
		}
	}
	average = avgTot / index;
	return average;
}

double getRowTotal(double numbers[][COLS], int row)
{
	double rowTot = 0;
	for (int col = 0; col < (COLS - 1); col++)
	{
		rowTot += numbers[row][col];
	}
	return rowTot;
}

double getColumnTotal(double numbers[][COLS], int col)
{
	double colTot = 0;
	for (int row = 0; row < (ROWS - 1); row++)
	{
		colTot += numbers[row][col];
	}
	return colTot;
}

double getHighest(double numbers[][COLS], int &row, int &col)
{
	double high = 0;
	for (int x = 0; x < (ROWS - 1); x++)
	{
		for (int y = 0; y < (COLS - 1); y++)
		{
			if ((numbers[x][y]) > high)
			{
				row = x;
				col = y;
				high = numbers[row][col];
			}
		}
	}
	return high;
}

double getLowest(double numbers[][COLS], int &row, int &col)
{
	double low = numbers[0][0];
	for (int x = 0; x < (ROWS - 1); x++)
	{
		for (int y = 0; y < (COLS - 1); y++)
		{
			if ((numbers[x][y]) <= low)
			{
				row = x;
				col = y;
				low = numbers[row][col];
			}
		}
	}
	return low;
}


/*
–---------------------------------------------------------------------------------------------------------------------------------------- -
Adam Allard
CISS - 241
Week 8
Course Project
Airline Reservations
–---------------------------------------------------------------------------------------------------------------------------------------- -
See Content area for course project description. 
–---------------------------------------------------------------------------------------------------------------------------------------- -
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void getPriceInfo();
void fillSeatingChart();
void showSeatingChart();
void showMenu();
void getMenuSelection();
void reserveSeat();
void getSeatRequest();
void checkSeatRequest(int, int);
void seatsSold();
void seatsEmptyInRow();
void seatsEmptyOnPlane();
void totalSalesDisplay();

double seatPrices[3];
char firstClass[5][4];
char coach1[5][6];
char coach2[5][6];

int firstClassSold, coach1Sold, coach2Sold = 0;
int currentFirst, currentC1, currentC2 = 0;

double totalSales = 0;

int main()
{
	getPriceInfo();
	fillSeatingChart();
	showMenu();

	system("pause");
	return 0;
}

void getPriceInfo()
{
	int count = 0;
	ifstream inputFile;
	inputFile.open("C:\\Users\\Adam\\Desktop\\SeatPrices.txt");
	while (count < 3 && inputFile >> seatPrices[count])
	{
		count++;
	}
	inputFile.close();
}

void fillSeatingChart()
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			firstClass[row][col] = '#';
		}
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			coach1[row][col] = '#';
		}
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			coach2[row][col] = '#';
		}
	}
}

void showSeatingChart()
{
	cout << "Seating Chart" << endl;
	cout << "\t" << "1 2 3 4" << endl;
	for (int row = 0; row < 5; row++)
	{
		cout << "Row " << (row + 1) << "\t";
		for (int col = 0; col < 4; col++)
		{
			cout << firstClass[row][col] << " ";
		}
		cout << endl;
	}

	cout << "\t" << "123 456" << endl;
	for (int row = 0; row < 5; row++)
	{
		cout << "Row " << (row + 6) << "\t";
		for (int col = 0; col < 6; col++)
		{
			cout << coach1[row][col];
			if (col == 2)
				cout << " ";
		}
		cout << endl;
	}
	for (int row = 0; row < 5; row++)
	{
		cout << "Row " << (row + 11) << "\t";
		for (int col = 0; col < 6; col++)
		{
			cout << coach2[row][col];
			if (col == 2)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void showMenu()
{
	cout << "Main Menu" << endl << endl;
	cout << "1. Reserve seat(s)" << endl;
	cout << "2. Show me the seating chart." << endl;
	cout << "3. How many seats are sold?" << endl;
	cout << "4. How many seats are empty by row?" << endl;
	cout << "5. How many seats are empty on the plane?" << endl;
	cout << "6. Show me the total sales." << endl;
	cout << "7. Exit." << endl;

	cout << "What would you like to do? (enter 1 - 7): ";
	getMenuSelection();
	cout << endl;
}

void getMenuSelection()
{
	const int
		RESERVE_SEAT = 1,
		SHOW_CHART = 2,
		SEATS_SOLD = 3,
		SEATS_EMPTY_ROW = 4,
		SEATS_EMPTY_PLANE = 5,
		TOTAL_SALES = 6,
		EXIT = 7;
	int choice;

	cin >> choice;
	cout << "-------------------------------------------";
	while (choice < RESERVE_SEAT || choice > EXIT)
	{
		cout << "Please enter a valid menu choice (1 - 7): ";
		cin >> choice;
	}
	cout << endl;

	switch (choice)
	{
	case RESERVE_SEAT:
		reserveSeat();
		break;
	case SHOW_CHART:
		showSeatingChart();
		break;
	case SEATS_SOLD:
		seatsSold();
		break;
	case SEATS_EMPTY_ROW:
		seatsEmptyInRow();
		break;
	case SEATS_EMPTY_PLANE:
		seatsEmptyOnPlane();
		break;
	case TOTAL_SALES:
		totalSalesDisplay();
		break;
	case EXIT:
		exit(0);
	}
	cout << "*******************************************" << endl;
	showMenu();
}

void reserveSeat()
{
	double currentTotal = 0;
	int numTickets;
	cout << "How many tickets would you like to reserve?: ";
	cin >> numTickets;
	cout << endl;
	for (int i = 0; i < numTickets; i++)
	{
		getSeatRequest();
	}

	currentTotal = ((currentFirst * seatPrices[0]) + (currentC1 * seatPrices[1]) + (currentC2 * seatPrices[2]));
	totalSales += currentTotal;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Your total is $" << currentTotal << endl;

	currentTotal = 0;
	firstClassSold += currentFirst;
	coach1Sold += currentC1;
	coach2Sold += currentC2;
	currentFirst = currentC1 = currentC2 = 0;
}

void getSeatRequest()
{
	int row, col;
	cout << "what row do you want your seat? (1 - 15): ";
	cin >> row;
	while (row < 1 || row > 15)
	{
		cout << "Invalid row choice. Please enter a row 1 - 15: ";
		cin >> row;
	}
	cout << "what column do you want your seat? (1 - 6): ";
	cin >> col;
	cout << endl;
	if (row >= 1 && row <= 5)
	{
		while (col < 1 || col > 4)
		{
			cout << "First class seating only has 4 columns." << endl
				<< "Please enter a column 1 - 4: ";
			cin >> col;
			cout << endl;
		}
	}
	else if (row >= 6 && row <= 15)
	{
		while (col < 1 || col > 6)
		{
			cout << "Coach seating only has 6 columns." << endl
				<< "Plese enter a column 1 - 6: ";
			cin >> col;
			cout << endl;
		}
	}
	checkSeatRequest(row, col);
}

void checkSeatRequest(int row, int col)
{
	if (row >= 1 && row <= 5)
	{
		if (firstClass[row - 1][col - 1] == '*')
		{
			cout << "Sorry, that seat is already taken." << endl;
			getSeatRequest();
		}
		if (firstClass[row - 1][col - 1] != '*')
		{
			firstClass[row - 1][col - 1] = '*';
			currentFirst++;
		}
	}
	if (row >= 6 && row <= 10)
	{
		if (coach1[row - 6][col - 1] == '*')
		{
			cout << "Sorry, that seat is already taken." << endl;
			getSeatRequest();
		}
		if (coach1[row - 6][col - 1] != '*')
		{
			coach1[row - 6][col - 1] = '*';
			currentC1++;
		}
	}
	if (row >= 11 && row <= 15)
	{
		if (coach2[row - 11][col - 1] == '*')
		{
			cout << "Sorry, that seat is already taken." << endl;
			getSeatRequest();
		}
		if (coach2[row - 11][col - 1] != '*')
		{
			coach2[row - 11][col - 1] = '*';
			currentC2++;
		}
	}
}

void seatsSold()
{
	int totalSeatsSold = firstClassSold + coach1Sold + coach2Sold;
	cout << "There are " << totalSeatsSold << " seats sold on the plane." << endl << endl
		<< "First Class Total: " << firstClassSold << endl
		<< "Coach Class Total: " << (coach1Sold + coach2Sold) << endl
		<< "    Coach 1: " << coach1Sold << endl
		<< "    Coach 2: " << coach2Sold << endl << endl;
}

void seatsEmptyInRow()
{
	int checkRow;
	int count = 0;
	cout << "What row do you want to check?: ";
	cin >> checkRow;
	cout << endl;
	while (checkRow != 0)
	{
		while (checkRow < 0 || checkRow > 15)
		{
			cout << "There are only 15 rows. Reenter row number: ";
			cin >> checkRow;
		}
		if (checkRow >= 1 && checkRow <= 5)
		{
			for (int col = 0; col < 4; col++)
			{
				if (firstClass[checkRow - 1][col] == '#')
				{
					count++;
				}
			}
		}
		else if (checkRow >= 6 && checkRow <= 10)
		{
			for (int col = 0; col < 6; col++)
			{
				if (coach1[checkRow - 6][col] == '#')
				{
					count++;
				}
			}
		}
		else if (checkRow >= 11 && checkRow <= 15)
		{
			for (int col = 0; col < 6; col++)
			{
				if (coach2[checkRow - 11][col] == '#')
				{
					count++;
				}
			}
		}
		cout << "There are " << count << " seats empty in row " << checkRow << "." << endl << endl;
		count = 0;
		cout << "Enter in another row number or 0 to return to the main menu: ";
		cin >> checkRow;
		cout << endl;
	}
	if (checkRow == 0)
		cout << endl;
}

void seatsEmptyOnPlane()
{
	int emptyTotal, emptyFirst = 0, emptyC1 = 0, emptyC2 = 0;
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (firstClass[row][col] == '#')
			{
				emptyFirst++;
			}
		}
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			if (coach1[row][col] == '#')
			{
				emptyC1++;
			}
		}
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			if (coach2[row][col] == '#')
			{
				emptyC2++;
			}
		}
	}
	emptyTotal = emptyFirst + emptyC1 + emptyC2;
	cout << "There are " << emptyTotal << " empty seats on the plane." << endl << endl
		<< "First Class empty: " << emptyFirst << " seats" << endl
		<< "Coach Class empty: " << emptyC1 + emptyC2 << " seats" << endl
		<< "    Section 1: " << emptyC1 << endl
		<< "    Section 2: " << emptyC2 << endl << endl;
}

void totalSalesDisplay()
{
	double firstSales = firstClassSold * seatPrices[0];
	double coachSales = (coach1Sold * seatPrices[1]) + (coach2Sold * seatPrices[2]);

	seatsSold();

	cout << setprecision(2) << fixed << showpoint;
	cout << "First Class Sales: $" << firstSales << endl
		 << "Coach Class Sales: $" << coachSales << endl << endl;
	cout << "The total sales is $" << totalSales << endl << endl;
}
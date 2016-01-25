/*
–-----------------------------------------------------------------------------------------------------------------------------------------
Adam Allard
CISS-241
Week 4
Assignment 2
Long Distance Calls
–-----------------------------------------------------------------------------------------------------------------------------------------
Write a program that prompts the user for the starting time and the number of minutes of the call and display the charges. 
The charges are based on the start time of the call a nd use the correct rate for the time range it falls into (see table below). 
The start time will be entered as a floating point number (decimal) in the form HH.MM.
For example, 07:00 would be entered as 07.00 and 16:28 will be entered as 16.28.

   Must not accept times that are greater than 23.59 (note that 6.69 is less than 23.59 but is an invalid time).
   Must not accept time whose last two digits are greater than 59.
      HINT – the following expression will give you its fractional part num – 
	  static_cast<int>(num) (where num is the start time entered by the user).

Validate that the number of minutes of the phone call is not negative
	  
Named constants must be used for the values in the following table.
     Start Time of Call   Rate Per Minute
     00:00 – 05:59        0.12
     06:00 – 12:59        0.23
     13:00 – 19:00        0.55
     19:01 – 23.59        0.35
–-----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	const double EARLY_MORNING = 00.00,  // $0.12
				 MORNING       = 06.00,  // $0.23
				 AFTERNOON     = 13.00,  // $0.55
				 EVENING       = 19.01;  // $0.35

	double startingTime,
		charges,
		timeMinutes,
		eveningRate = .35,			// only valuable reason for making
		afternoonRate = .55,		// these as variables is in case the
		morningRate = .23,			// company wants to change the rates 
		earlyMorningRate = .12;		// later, they can do so easily.
	int numberOfMinutes;

	cout << "What is the starting time of the call? (HH.MM): ";
	cin >> startingTime;
	cout << endl;
	// get the minutes value
	timeMinutes = startingTime - static_cast<int>(startingTime); 

	// validate user input
	while (startingTime > 23.59 || timeMinutes > .59) {
		cout << "Invalid entry.\n"
			<< "Starting time cannot go past 23.59.\n"
			<< "Minutes cannot go past 59.\n\n"
			<< "Reenter the starting time. (HH.MM): ";
		cin >> startingTime;
		timeMinutes = startingTime - static_cast<int>(startingTime);
		cout << endl;
	}

	cout << "How many minutes was the call? ";
	cin >> numberOfMinutes;
	cout << endl;
	// validate user input
	while (numberOfMinutes < 0) {
		cout << "It is impossible for a call to be negative minutes long.\n"
			<< "Reenter the number of minutes of the call: ";
		cin >> numberOfMinutes;
		cout << endl;
	}

	// calculate the charges based on the starting time of the call
	cout << fixed << setprecision(2);

	if (startingTime >= EVENING) {
		charges = numberOfMinutes * eveningRate;
	}
	else if (startingTime >= AFTERNOON) {
		charges = numberOfMinutes * afternoonRate;
	}
	else if (startingTime >= MORNING) {
		charges = numberOfMinutes * morningRate;
	}
	else if (startingTime >= EARLY_MORNING) {
		charges = numberOfMinutes * earlyMorningRate;
	}

	cout << "Total charges of call: $" << charges << endl;

	system("pause");
	return 0;
}
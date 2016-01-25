/*
–---------------------------------------------------------------------------------------------------------------------------------------- -
Adam Allard
CISS - 241
Week 5
Assignment 1
Generate Random Number
–---------------------------------------------------------------------------------------------------------------------------------------- -
Write a program that generates a random number between 1 and 100 and asks the user to guess what the number is. 
If the user’s guess is higher than the random number, the program should display “Too high, try again.”
If the user’s guess is lower than the random number, the program should display “Too low, try again.” 
The program must use a loop that repeats until the user correctly guesses the random number or has made 10 guesses. 
The program needs to keep track of the number of guesses the user makes. 
At the end the program will display one of the messages in the table below based on the number of guesses the user took.
The program must validate the user’s guess by making sure the value entered is between 1 and 100. 
If the value is not between 1 and 100, the user should be told to make another guess.
The invalid input should not count as one of the 10 guesses the user is allowed.

Number of Guesses by the User      Output Message
Less than 5 guesses                "Either you know the secret or you got lucky!"
5 - 7 guesses                      "You're pretty good at this!"
8 - 10 guesses                     "You'll do better next time."
If guess 10 is not correct         "Sorry - You have taken too many guesses."
–---------------------------------------------------------------------------------------------------------------------------------------- -
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
int main() {

	int number,
		guess;
	char playAgain;

	unsigned seed = time(0);
	srand(seed);

	do {
		// generate random number between 1 - 100
		number = (rand() % (100)) + 1; 

		cout << "Guess the number (1-100): ";
		for (int i = 0; i < 10; i++) {
			cin >> guess;
			// validate users input
			if ((guess < 1) || (guess > 100)){
				cout << endl << "You must guess a number between 1 - 100. Guess again: ";
				i--;
			}
			// if user has 1-4 guesses
			if ((guess == number) && (i < 4)) {
				cout << endl << "Either you know the secret or you got lucky!" << endl;
				break;
			}
			// if user has 5-7 guesses
			else if ((guess == number) && (i > 3) && (i < 7)) {
				cout << endl << "You're pretty good at this!" << endl;
				break;
			}
			// if user has 7-10 guesses
			else if ((guess == number) && (i > 6) && (i < 10)) {
				cout << endl << "You'll do better next time." << endl;
				break;
			}
			// if user has guesses 10 times and still has not guessed the number
			else if ((guess != number) && (i == 9)) {
				cout << endl << "Sorry - You have taken too many guesses." << endl;
				break;

			}
			else if ((guess < number) && (guess >= 1) && (guess <= 100)) {
				cout << endl << "Too low, try again: ";
			}
			else if ((guess > number) && (guess >= 1) && (guess <= 100)) {
				cout << endl << "Too high, try again: ";
			}
		}

		cout << "Would you like to play again? (Y/N): ";
		cin >> playAgain;
		cout << endl;
	} while ((playAgain == 'Y') || (playAgain == 'y'));

	// if user doesn't hit Y or y, end and close the program
	cout << "Good Bye!";
	Sleep(2000);
	return 0;
}
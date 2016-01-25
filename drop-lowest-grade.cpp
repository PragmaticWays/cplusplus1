/*
–---------------------------------------------------------------------------------------------------------------------------------------- -
Adam Allard
CISS - 241
Week 6
Assignment 1
Drop Lowest Grade
–---------------------------------------------------------------------------------------------------------------------------------------- -
Write a program that calculates the average of a group of test scores, where the lowest score in the group is dropped. 
It must have the following functions:
    - void getScore() should ask the user for a test score, store it in a reference parameter variable, and validate it. 
	  This function must be called by main once for each of the six scores to be entered (so 6 times).
         - Validate the test scores entered are greater than or equal to 0 and less than or equal to 100
    - Void calcAverage() should calculate and display the average of the five highest scores.
      This function must be called just once by main, and must be passed the six scores.
      Result must be displayed with a precision of 2.
    - int findLowest() should find and return the lowest of the lowest scores passed to it. 
	  It must be called by calcAverage, which uses the function to determine which of the six scores to drop.
–---------------------------------------------------------------------------------------------------------------------------------------- -
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getScore(int &);
void calcAverage(int, int, int, int, int, int);
int findLowest(int, int, int, int, int, int);

int main() {
	int testScore1,
		testScore2,
		testScore3,
		testScore4,
		testScore5,
		testScore6;

	// get the score of 6 tests
	for (int i = 0; i < 6; i++){
		if (i == 0) {
			getScore(testScore1);
		}
		else if (i == 1) {
			getScore(testScore2);
		}
		else if (i == 2) {
			getScore(testScore3);
		}
		else if (i == 3) {
			getScore(testScore4);
		}
		else if (i == 4) {
			getScore(testScore5);
		}
		else if (i == 5) {
			getScore(testScore6);
		}
	} // end of for loop

	calcAverage(testScore1, testScore2, testScore3, testScore4, testScore5, testScore6);

	system("pause");
	return 0;
}

void getScore(int &score) {
	int validScore;
	cout << "Enter the score of the test: ";
	cin >> validScore;
	// validate user entry
	while ((validScore < 0) || (validScore > 100)) {
		cout << "Test scores values can only be between 0 and 100." << endl
			<< "Please reenter the test score: ";
		cin >> validScore;
	}
	score = validScore;
}

void calcAverage(int score1, int score2, int score3, int score4, int score5, int score6) {

	int dropScore = findLowest(score1, score2, score3, score4, score5, score6);
	int sum = score1 + score2 + score3 + score4 + score5 + score6 - dropScore;
	double average = sum / 5.0;

	cout << setprecision(2) << fixed << showpoint;
	cout << "The average score of your tests is: " << average << endl;
}

int findLowest(int score1, int score2, int score3, int score4, int score5, int score6) {
	int lowestScore;
	if (score1 <= score2) {
		lowestScore = score1;
	}
	else {
		lowestScore = score2;
	}
	if (score3 < lowestScore) {
		lowestScore = score3;
	}
	if (score4 < lowestScore) {
		lowestScore = score4;
	}
	if (score5 < lowestScore) {
		lowestScore = score5;
	}
	if (score6 < lowestScore) {
		lowestScore = score6;
	}
	return lowestScore;
}
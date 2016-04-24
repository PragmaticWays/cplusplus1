/*
–---------------------------------------------------------------------------------------------------------------------------------------- -
Adam Allard
CISS - 241
Week 5
Assignment 2
Working With Files
–---------------------------------------------------------------------------------------------------------------------------------------- -
You will need the text file Random.txtthat can be found in the Content area of the course under Week 5.  
The file contains a list of random numbers. 
Write a program that opens the file and reads all the numbers from the file, and calculate/determine the following:
   1. Counts how many numbers were read from the file
   2. The sum of all the numbers in the file (a running total)
   3. The average of all the numbers in the file
   4. Determine the lowest and highest values in the file
        The program must validate that the file was opened before reading from the file.
        If file does not exist then display a message telling the user that the file could not be opened and exit the program.
–---------------------------------------------------------------------------------------------------------------------------------------- -
*/

#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;
int main() {

	int readNumber,
		lowestNum,
		highestNum,
		count = 0, 
		total = 0;
	double average;

	ifstream randomNumFile("C:\\Users\\Adam\\Desktop\\CISS_241\\5_2\\Random.txt");
 
	if (randomNumFile) {
		cout << "File opened successfully." << endl;

		randomNumFile >> readNumber;

		while (randomNumFile >> readNumber) {
			
			// if first number, assign highest and lowest numbers
			if (count == 0) {
				highestNum = readNumber;
				lowestNum = readNumber;
			}
			
			if (readNumber < lowestNum) {
				lowestNum = readNumber;
			} else if (readNumber > highestNum) {
				highestNum = readNumber;
			}
			total += readNumber;
			count++;
		} // <-- end of while loop

		// cast total to avoid integer division
		average = static_cast<double>(total) / count;

		randomNumFile.close();
		if (!randomNumFile) {
			cout << "File closed successfully." << endl << endl;
		}

		// format the output for organization
		cout << left << setw(25) << "Numbers read from file: "			<< right << setw(8) << count << endl
			 << left << setw(25) << "Sum of all numbers: "				<< right << setw(8) << total << endl
			 << left << setw(25) << "Average of all numbers: "			<< right << setw(8) << average << endl
			 << left << setw(25) << "Lowest value in file: "			<< right << setw(8) << lowestNum << endl
			 << left << setw(25) << "Highest value in file: "			<< right << setw(8) << highestNum << endl << endl;
	} // <-- end of 'if(randomNumFile)' loop
	else {
		cout << "Error opening the file." << endl;
		Sleep(3000);
		return 0;
	}
	
	return 0;
}

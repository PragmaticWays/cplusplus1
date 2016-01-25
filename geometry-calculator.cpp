/*
–-----------------------------------------------------------------------------------------------------------------------------------------
Adam Allard
CISS-241
Week 4
Assignment 1
Geometry Calculator
–-----------------------------------------------------------------------------------------------------------------------------------------
Write a program that displays the following menu with the following format:
  Geometry Calculator
    1. Calculate the Area of a Circle
    2. Calculate the Area of a Rectangle
    3. Calculate the Area of a Triangle
    4. Calculate the Area of a Trapezoid
    5. Calculate the Area of a Sphere
    6. Exit
  Enter your Choice (1- 6):

Using a Switch statement for the user’s menu choice, calculate the area for the shape selected.
For a circle, the program must prompt the user radius of the circle. 
The program will calculate the area and display the area. 
For the rectangle, the program must prompt the user for the length and width of the rectangle. 
Calculate the area of the rectangle and display it. 
For the triangle, the program must prompt the user for the length of the triangle’s base and its height. 
Calculate the area of the triangle and display it.
If the shape selected is trapezoid, the program must prompt the user for the height and the two base lengths. 
If sphere is selected,the program must prompt the user for the radius.
   Make PI a named constant
   Circle area = PI* r^2
   Rectangle area = length * width
   Triangle area = base * height *0.5
   Trapezoid area = height/2 (b1+ b2)
   Sphere area = 4*PI*r^2
If the user enters an invalid menu option, display a message telling the user what the valid choices are and exit the program. 
Do not allow the user to enter a negative number for any of the values used to calculate the areas.
–-----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <windows.h> // needed for Sleep function

using namespace std;

int main() {
	double	radius,
		length,
		width,
		base1,
		base2,
		height,
		area;
	const int	CIRCLE = 1,
		RECT = 2,
		TRI = 3,
		TRAP = 4,
		SPHERE = 5,
		EXIT = 6;

	const double	PI = 3.14159;
	
	int choice = 0;
	while (choice != 6) {
		// display the menu and get a choice
		cout << "\tGeometry Calculator\n"
			<< "\t\t 1. Calculate the Area of a Circle\n"
			<< "\t\t 2. Calculate the Area of a Rectangle\n"
			<< "\t\t 3. Calculate the Area of a Triangle\n"
			<< "\t\t 4. Calculate the Area of a Trapezoid\n"
			<< "\t\t 5. Calculate the Area of a Sphere\n"
			<< "\t\t 6. Exit\n\n"
			<< "\t Enter your Choice (1-6): ";
		cin >> choice;
		cout << endl;

		// respond to user's menu selection
		switch (choice) {
		case CIRCLE:
			cout << "What is the radius of the circle? ";
			cin >> radius;
			// if the user enters a negative number, have the user reenter a valid number
			while (radius < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the radius of the circle? ";
				cin >> radius;
			}
			cout << endl;
			area = PI * pow(radius, 2.0);
			cout << "Circle:\n"
				<< "  Radius = " << radius << endl
				<< "  Area   = " << area << endl;
			break;

		case RECT:
			cout << "What is the length of the rectangle? ";
			cin >> length;
			// if the user enters a negative number, have the user reenter a valid number
			while (length < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the length of the rectangle? ";
				cin >> length;
			}
			cout << endl;
			cout << "What is the width of the rectangle? ";
			cin >> width;
			// if the user enters a negative number, have the user reenter a valid number
			while (width < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the width of the rectangle? ";
				cin >> width;
			}
			cout << endl;
			area = length * width;
			cout << "Rectangle:\n"
				<< "   Length = " << length << endl
				<< "   Width  = " << width << endl
				<< "   Area   = " << area << endl;
			break;

		case TRI:
			cout << "What is the length of the base of the triangle? ";
			cin >> base1;
			// if the user enters a negative number, have the user reenter a valid number
			while (base1 < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the length of the base of the triangle? ";
				cin >> base1;
			}
			cout << endl;
			cout << "What is the height of the triangle? ";
			cin >> height;
			// if the user enters a negative number, have the user reenter a valid number
			while (height < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the height of the triangle? ";
				cin >> height;
			}
			cout << endl;
			area = base1 * height * 0.5;
			cout << "Triangle: \n"
				<< "  Base   = " << base1 << endl
				<< "  Height = " << height << endl
				<< "  Area   = " << area << endl;
			break;

		case TRAP:
			cout << "What is the height of the trapezoid? ";
			cin >> height;
			// if the user enters a negative number, have the user reenter a valid number
			while (height < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the height of the trapezoid? ";
				cin >> height;
			}
			cout << endl;
			cout << "What is the length of one of the bases of the trapezoid? ";
			cin >> base1;
			// if the user enters a negative number, have the user reenter a valid number
			while (base1 < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the length of one of the bases of the trapezoid? ";
				cin >> base1;
			}
			cout << endl;
			cout << "What is the length of the other base of the trapezoid? ";
			cin >> base2;
			// if the user enters a negative number, have the user reenter a valid number
			while (base2 < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the length of the base of the trapezoid? ";
				cin >> base2;
			}
			cout << endl;
			area = height / 2 * (base1 + base2);
			cout << "Trapezoid: \n"
				<< "  Height   = " << height << endl
				<< "  Base one = " << base1 << endl
				<< "  Base two = " << base2 << endl
				<< "  Area     = " << area << endl;
			break;

		case SPHERE:
			cout << "What is the radius of the sphere? ";
			cin >> radius;
			// if the user enters a negative number, have the user reenter a valid number
			while (radius < 0) {
				cout << endl;
				cout << "You cannot enter a negative number." << endl
					<< "What is the radius of the sphere? ";
				cin >> radius;
			}
			area = 4 * PI * pow(radius, 2.0);
			cout << "Sphere: \n"
				<< "  Radius = " << radius << endl
				<< "  Area   = " << area << endl;
			break;

		case EXIT:
			return 0;

			// if the user enters an invalid menu choice, countdown and close the program in 5 seconds
		default: cout << "The only valid menu choices are 1-6.\n"
			<< "Program will close in: ";
			for (int time = 5; time > 0; time--) {
				cout << endl << time;
				Sleep(1000);
			}
			return 0;
		}				// end of switch statement 
		cout << endl << "Redirecting you back to the main menu..." << endl << endl;
		Sleep(5000);
	}					// end of while loop for menu selection
	system("pause");
	return 0;
}						// end of main()
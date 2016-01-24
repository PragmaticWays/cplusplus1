/*
–-----------------------------------------------------------------------------------------------------------------------------------------
Adam Allard
CISS-241
Week 3
Assignment 2
Pizza Orders
–-----------------------------------------------------------------------------------------------------------------------------------------
Joe’s Pizza Palace needs a program to calculate the number of slices a pizza of any size can be divided into. 
The program should also report the number of pizzas someone should order for a party. 
Assume each person at the party will eat 3 slices each. 
The program should prompt the user for the diameter of the pizzas they wish to order and the number of people who will be at the party. 
The program should then calculate and display the number of slices per pizza and the number of pizzas needed for the party. 

  - A slice must have an area of 14.125 inches
  - Number of slices per pizza is the area of the pizza divided by the area of a slice
  - Area of a pizza is calculated with Area = PI * r^2 where PI = 3.14159 and r is the radius of the pizza
  - The number of slices should be fixed point and rounded to one decimal place
  - PI must be a named constant
–----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const double PI = 3.14159,
	             SLICE_AREA = 14.125;
	double 	pizzaRad,
	        pizzaArea,
	        numSlicesPerPizza;
	int slicesPerPerson = 3,
	    numPeople,
	    numPizzasNeed,
	    pizzaDi;

	// prompt user for pizza and party info
	cout << "What size pizza would you like? (Enter the inch diameter of the pizza)\n";
	cin >> pizzaDi;
	cout << "How many people are at the party?\n";
	cin >> numPeople;

	// calculations 
	pizzaRad = pizzaDi / 2;
	pizzaArea = PI * pow(pizzaRad, 2.0);
	numSlicesPerPizza = pizzaArea / SLICE_AREA;
	numPizzasNeed = ((numPeople * slicesPerPerson) / numSlicesPerPizza) + 1;

	// display the results. 
	cout << endl;
	cout << "Pizza Size: "        << right << setw(10) << pizzaDi << endl;
	cout << "Number of slices: "  << right << setw(4) << setprecision(1) << fixed << showpoint << numSlicesPerPizza << endl;
	cout << "Number of people: "  << right << setw(4) << numPeople << endl;
	cout << "Number of pizzas: "  << right << setw(4) << numPizzasNeed << endl << endl;

	system("pause");
	return 0;
}

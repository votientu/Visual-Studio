// Ex2_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Calculating how many rolls of wallpaper are required for a room

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	double height{}, width{}, length{};		// Room dimensions
	double perimeter{};						// Room perimeter 

	const double rollWidth{21.0};			// Standard roll width
	const double rollLength{12.0*33.0};		// Standard roll length{33ft.}

	int strips_per_roll{};					// Number of strips in a roll
	int strips_reqd{};						// Number of strips needed
	int nrolls{};							// Total number of rolls

	cout << endl							// Start a new line
		<< "Enter the height of the room in inches: ";
	cin >> height;

	cout << endl							// Start a new line
		<< "Enter the length and width in inches: ";
	cin >> length >> width;

	strips_per_roll = rollLength / height;	// Get number of strips per roll
	perimeter = 2.0 * (length + width);		// Calculate room perimeter
	strips_reqd = perimeter / rollWidth;	// Get total strips required
	nrolls = strips_reqd / strips_per_roll;	// Calculate number of rolls

	cout << endl
		<< "For your room you need " << nrolls << " rolls of wallpaper."
		<< endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

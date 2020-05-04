// Ex5_14.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using a static variable within a function

#include <iostream>

using std::cout;
using std::endl;

void record();			// Function prototype, no arguments or return value

int main()
{
	for (int i{}; i <= 3; i++)
		record();

	cout << endl;
	return 0;
}

// A function that records how often it is called
void record()
{
	static int count {};
	cout << endl << "This is the " << ++count;
	if ((count > 3) && (count < 21))		// All this...
		cout << "th";
	else 
		switch (count % 10)					// is just to get...
		{
		case 1: 
			cout << "st";
			break;
		case 2:
			cout << "nd";
			break;
		case 3:
			cout << "rd";
			break;
		default: 
			cout << "th";					// the right ending for...
		}									// 1st, 2nd, 3rd, 4th, etc.
	cout << " time I have been called";
	return;
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

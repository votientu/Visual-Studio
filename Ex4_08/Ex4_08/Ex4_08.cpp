// Ex4_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Initializing pointers with strings

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const char* pstr[]{ "Robert Redford",		// Initializing a pointer array 
						"Hopalong Cassidy",
						"Lassie",
						"Slim Pickens",
						"Boris Karloff",
						"Olivier Hardy"
	};

	const char* pstart{ "Your lucky star is " };

	int dice{};
	
	cout << endl
		<< "Pick a lucky star! " 
		<< "Enter a number between 1 and " << _countof(pstr) << ": ";
	cin >> dice;

	cout << endl;
	if (dice >= 1 && dice <= _countof(pstr))		// Check input validity
		cout << pstart << pstr[dice - 1];			// Output star name
	else
		cout << "Sorry, you haven't got a lucky start.";		// Invalid input

	cout << endl;
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

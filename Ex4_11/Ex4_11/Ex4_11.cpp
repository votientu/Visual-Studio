// Ex4_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Calculating primes using dynamic memory allocation

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
	int max{};					// Number of primes required
	cout << endl
		<< "Enter the number of primes you would like (at least 4): ";
	cin >> max;

	if (max < 4)				// Test the user input, if less than 4
		max = 4;				// ensure it is at least 4

	// Allocate prime array and initialize with seed primes 
	long* pprime{ new long[max] {2L, 3L, 5L} };

	long trail {5L};			// Candidate prime 
	int count {3};				// Count of primes found
	bool found {false};			// Indicates when a prime is found

	do
	{
		trail += 2L;				// Next value for checking
		found = false;			// Set found indicator

		for (int i{}; i < count; i++)	// Division by existing primes
		{
			found = (trail % *(pprime + 1)) == 0;	// True for exact division
			if (found)								// If division is exact
				break;								// it's not a prime
		}

		if (!found)									// We got one
			*(pprime + count++) = trail;			// ... so swave it in primes array
	} while (count < max);

	// Output primes 5 to a line
	for (int i{}; i < max; i++)
	{
		if (i % 5 == 0)			// New line on 1st and every 5th line
			cout << endl;
		cout << setw(10) << *(pprime + i);
	}

	delete[] pprime;			// Free up memory ...
	pprime = nullptr;			// ... and reset the pointer
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

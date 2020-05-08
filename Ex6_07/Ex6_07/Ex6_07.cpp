// Ex6_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using overloaded functions

#include <iostream>
using std::cout;
using std::endl;

int max(const int data[], const size_t len);		// Prototype for
long max(const long data[], const size_t len);		// a set of overloaded
double max(const double data[], const size_t len);	// functions


int main()
{
    int small[] {1, 24, 34, 22};
	long medium[] {23, 245, 123, 1, 234, 2345};
	double large[] {23.0, 1.4, 2.456, 345.5, 12.0, 21.0};

	const size_t lensmall {_countof(small)};
	const size_t lenmedium {_countof(medium)};
	const size_t lenlarge {_countof(large)};

	cout << endl << max(small, lensmall);
	cout << endl << max(medium, lenmedium);
	cout << endl << max(large, lenlarge);

	cout << endl;
	return 0;
}

// Maximum of ints
int max(const int x[], const size_t len)
{
	int maximum {x[0]};
	for (size_t i{ 1 }; i < len; i++)
		if (maximum < x[i])
			maximum = x[i];
	return maximum;
}

// Maximum of longs
long max(const long x[], const size_t len)
{
	long maximum{ x[0] };
	for (size_t i{ 1 }; i < len; i++)
		if (maximum < x[i])
			maximum = x[i];
	return maximum;
}

// Maximum of doubles 
double max(const double x[], const size_t len)
{
	double maximum{ x[0] };
	for (size_t i{ 1 }; i < len; i++)
		if (maximum < x[i])
			maximum = x[i];
	return maximum;
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

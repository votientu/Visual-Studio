// Ex6_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A pointer to a function as an argument

#include <iostream>

using std::cout;
using std::endl;

// Function prototypes
double squared(double);
double cubed(double);
double sumarray(const double data[], size_t len, double (*pfun)(double));

int main()
{
    double data[] {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
	size_t len {_countof(data)};

	cout << endl << "Sum of squares = " << sumarray(data, len, squared);
	cout << endl << "Sum of cubes = " << sumarray(data, len, cubed);
	cout << endl;
	return 0;
}

// Function for square of a value
double squared(double x) { return x * x; }

// FUnction for a cube of a value
double cubed(double x) { return x * x * x; }

// Function to sum functions of array elements
double sumarray(const double data[], size_t len, double (*pfun)(double)) 
{
	double total {};			// Accumulate total in here

	for (size_t i{}; i < len; i++)
		total += pfun(data[i]);

	return total;
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

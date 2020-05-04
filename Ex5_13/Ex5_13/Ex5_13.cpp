// Ex5_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Returning a reference

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

double& lowest(double value[], int length);		// Function prototype

int main()
{
	double data[] {3.0, 10.0, 1.5, 15.0, 2.7, 23.0,
				   4.5, 12.0, 6.8, 13.5, 2.1, 14.0 };
	int len {_countof(data)};					// Number of elements
	for (auto value : data)
		cout << setw(6) << value;

	lowest(data, len) = 6.9;					// Change lowest to 6.9
	lowest(data, len) = 7.9;					// Change lowest to 7.9

	cout << endl;
	for (auto value : data)
		cout << setw(6) << value;				

	cout << endl;
	return 0;
}

// Function returning a reference
double& lowest(double a[], int len)
{
	int j {};									// Index of lowest element
	for (int i{ 1 }; i < len; i++)
		if (a[i] < a[j])						// Test fo a lower value...
			j = i;								// ...if so update j
	return a[j];								// Return reference so lowest element
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

// Ex5_15.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A recursive version of x to the power n

#include <iostream>

using std::cout;
using std::endl;

double power(double x, int n);		// Function prototype

int main()
{
    double x {2.0};					// Different x from that in function power
	double result {};

	// Calculate x raised to powers -3 to +3 inclusive
	for (int index {-3}; index <= 3; index++)
		cout << x << " to the power " << index << " is " << power(x, index) << endl;

	return 0;
}

// Recursive function to compute integral powers of a double value
// First argument is value, second argument is power index
double power(double x, int n)
{
	if (n < 0)
	{
		x = 1.0 / x;
		n = -n;
	}
	if (n > 0)
		return x * power(x, n - 1);
	else
		return 1.0;
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

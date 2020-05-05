// Ex6_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercising pointers to functions

#include <iostream>

using std::cout;
using std::endl;

long sum(long a, long b);			// Function prototype
long product(long a, long b);		// Function prototype

int main()
{
	long (*pdo_it)(long, long);		// Pointer to function declaration

	pdo_it = product;
	cout << endl
		<< "3*5 = " << pdo_it(3, 5);	// Call product thru a pointer

	pdo_it = sum;					// Reassign pointer to sum()
	cout << endl
		<< "3*(4 + 5) + 6 = "
		<< pdo_it(product(3, pdo_it(4, 5)), 6);	// Call thru a pointer, twice

	cout << endl;
	return 0;
}

// Function to multiply two values
long product(long a, long b)
{
	return a * b;
}

// Function to add two values
long sum(long a, long b)
{
	return a + b;
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

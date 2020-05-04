// Ex5_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Handling a variable number of arguments

#include <iostream>
#include <cstdarg>

using std::cout;
using std::endl;

int sum(int count, ...)
{
	if (count <= 0)
		return 0;
	
	va_list arg_ptr;			// Declare argument list pointer
	va_start(arg_ptr, count);	// Set arg_ptr to 1st optinal argument

	int sum {};
	for (int i{}; i < count; i++)
		sum += va_arg(arg_ptr, int);	// Add int value from arg_ptr and increment

	va_end(arg_ptr);			// Reset the pointer to null
	return sum;
}

int main()
{
	cout << sum(6, 2, 4, 6, 8, 10, 12) << endl;
	cout << sum(9, 11, 22, 33, 44, 55, 66, 77, 66, 99) << endl;
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

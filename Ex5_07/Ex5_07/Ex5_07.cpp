// Ex5_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using an lvalue reference to modify caller arguments 

#include <iostream>

using std::cout;
using std::endl;

int incr10(int& num);			// Function prototype

int main()
{
    int num {3};
	int value {6};

	int result {incr10(num)};
	cout << endl << "incr10(num) = " << result
		<< endl << "num = " << num;

	result = incr10(value);
	cout << endl << "incr10(value) = " << result
		<< endl << "value = " << value << endl;

	return 0;
}

// Function to increment a variable by 10
int incr10(int& num)		// Function with reference argument
{
	cout << endl << "Value received = " << num;	
	num += 10;				// Increment the caller argument
							// - confidently
	return num;				// Return the incremented value
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

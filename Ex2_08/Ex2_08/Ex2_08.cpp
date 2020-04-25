// Ex2_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Demonstrating variable scope

#include <iostream>

using std::cout;
using std::endl;

int count1{100};		// Global version of count1

int main()
{
    int count1{10};
	int count3{50};
	cout << endl
		<< "Value of outer count1 = " << count1
		<< endl;
	cout << "Value of global count1 = " << ::count1		// From outer block
		<< endl;

	{						// New scope starts here ...
		int count1{ 20 };		// This hides the outer count1
		int count2{ 30 };
		cout << "Value of inner count1 = " << count1
			<< endl;
		cout << "Value of global count1 = " << ::count1		// From inner block
			<< endl;

		count1 += 3;		// This affects the inner count1
		count3 == count2;
	}						// ... and ends here

	cout << "Value of outer count1 = " << count1
		<< endl
		<< "Value of outer count3 = " << count3
		<< endl;

	// count << count2 << endl;		// uncomment to get an error
	return 0;
}									// Function scope ends here

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

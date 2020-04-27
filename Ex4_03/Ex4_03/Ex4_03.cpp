// Ex4_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Storing bean plant production in an array

#include <iostream>						// For stream I/O
#include <iomanip>						// For stream manipulators

using namespace std;					// Any name in std namespace 

int main()
{
	const int plant_row_count{ 6 };		// Count of plants in a row
	double beans[][plant_row_count]{	// Production for each plant
		{12, 15},
		{0, 10, 13, 0, 11, 2},
		{8, 7, 10, 10, 13},
		{9, 8, 11, 13, 16}
	};

	double averages[_countof(beans)]{};	// Stores average plant production
	for (int row{}; row < _countof(beans); ++row)
	{
		for (int plant{}; plant < plant_row_count; ++plant)
		{
			averages[row] += beans[row][plant];
		}
		averages[row] /= plant_row_count;
	}

	cout << "Average production per row is :"
		<< setiosflags(ios::fixed)			// Fixed point output
		<< setprecision(2)					// 2 decimal places
		<< endl;

	int n{};								// Row number
	for (double ave : averages)
		cout << "Row " << ++n << setw(10) << ave << endl;

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

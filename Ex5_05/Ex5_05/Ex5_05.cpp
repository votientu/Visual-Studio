// Ex5_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Handling an array in a function as a pointer

#include <iostream>
using std::cout;
using std::endl;

double average(double* array, int count);		// Function prototype

int main()
{
    double values[] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

	cout << endl << "Average = "
		<< average(values, _countof(values)) << endl;
	return 0;
}

// Function to compute an avarage
double average(double* array, int count)
{
	double sum{};								// Accumulate total in here
	for (int i{}; i < count; i++)				// Sum array elements 
		sum += *array++;
	return sum / count;
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

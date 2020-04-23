// Ex02_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Excercising the comma operator

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	long num1{}, num2{}, num3{}, num4{};

	num4 = (num1 = 10L, num2 = 20L, num3 = 30L);
	cout << endl
		<< "The value of a series of expressions "
		<< "is the value of the rightmost: "
		<< num4;
	cout << endl;

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

#// Ex9_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using the protected access specifier

#include <iostream>			// For stream I/O
#include "CandyBox.h"		// For CBox and CCandyBox

int main()
{
	CCandyBox chocBox{ 2.0, 3.0, 4.0, "Chockies" };		// Declare and initialize
	CCandyBox chocolateBox{ chocBox };					// For CBox and CCandyBox
	
	std::cout << "Volume of chocBox is " << chocBox.volume() << std::endl
		<< "Volume of chocolateBox is " << chocolateBox.volume() << std::endl;

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

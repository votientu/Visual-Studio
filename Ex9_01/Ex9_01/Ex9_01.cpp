#// Ex9_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using a function inherited from a base class

#include <iostream>			// For stream I/O
#include "CandyBox.h"		// For CBox and CCandyBox

int main()
{
    CBox myBox {4.0, 3.0, 2.0};		// Create CBox and CCandyBox object 
	CCandyBox myCandyBox;			
	CCandyBox myMintBox{ "Wafer Thin Mints" };

	std::cout << "myBox occupies " << sizeof myBox		// Show how much memory
		<< " bytes" << std::endl
		<< "myCandyBox occupies " << sizeof myCandyBox
		<< " bytes" << std::endl
		<< "myMintBox occupies " << sizeof myMintBox
		<< " bytes" << std::endl;
	std::cout << "mymintBox volume is " << myMintBox.volume()	// Get volume of a CCandyBox object
		<< std::endl;

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

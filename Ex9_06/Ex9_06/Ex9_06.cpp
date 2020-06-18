// Ex9_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using an abstract class 
#include <iostream>
#include "Box.h"
#include "Can.h"
#include "GlassBox.h"

int main()
{
	// Pointer to abstract base class initialized with CBox object address
	CContainer* pC1{ new CBox {2.0, 3.0, 4.0} };
	CCan myCan{ 6.5, 3.0 };
	CGlassBox myGlassBox{ 2.0, 3.0, 4.0 };
	pC1->showVolume();				// Output the volume of CBox
	std::cout << "Delete CBox" << std::endl;
	delete pC1;

	pC1 = new CGlassBox{ 4.0, 5.0, 6.0 };	// Create CGlassBox dynamically
	pC1->showVolume();
	std::cout << "Delete CGlassBox" << std::endl;
	delete pC1;

	pC1 = &myCan;					// Put myCan address in pointer
	pC1->showVolume();				// Output the volume of CCan
	pC1 = &myGlassBox;				// Put myGlassBox address in pointer
	pC1->showVolume();				// Output the volume of CGlassBox

	return 0;
}

void output(const CBox& aBox)
{
	aBox.showVolume();
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

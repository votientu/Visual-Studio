// Ex8_14.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A sample packaging problem

#include <iostream>
#include "Box.h"
#include "BoxOperators.h"

using std::cout;
using std::endl;

int main()
{
	CBox candy{ 1.5, 1.0, 1.0 };			// Candy definition
	CBox candyBox{ 7.0, 4.5, 2.0 };			// Candy box definition
	CBox carton{ 30.0, 18.0, 18.0 };		// Carton definition

	// Calculate candies per candy box
	int numCandies{ candyBox / candy };

	// Calculate candy boxes per carton
	int numCBoxes{ carton / candyBox };

	// Calculate wasted carton space
	double wasted{ carton % candyBox };

	cout << "There are " << numCandies << " candies per candy box" << endl
		<< "For the standard boxes there are " << numCBoxes
		<< " candy boxes per carton " << endl << "with "
		<< wasted << " cubic inches wasted." << endl;

	cout << endl << "CUSTOM CANDY BOX ANALYSIS (No Waste)" << endl;
	const int minCandiesPerBox{ 30 };

	// Try the whole range of custom candy boxes
	for (double length{ 3.0 }; length <= 7.5; length += 0.5)
	{
		for (double width{ 3.0 }; width <= 5.0; width += 0.5)
		{
			for (double height{ 1.0 }; height <= 2.5; height += 0.5)
			{
				// Create new box each cycle
				CBox tryBox(length, width, height);

				// If carton wast < a candy box & no waste in candy box & candy box holds minimum
				if ((carton % tryBox < tryBox.volume()) &&
					(tryBox % candy == 0.0) &&
					(tryBox / candy >= minCandiesPerBox))
				{
					cout << "Trial Box L = " << tryBox.getLength()
						<< " W = " << tryBox.getWidth()
						<< " H = " << tryBox.getHeight()
						<< endl;
					cout << "Trial Box contains " << tryBox / candy << " candies"
						<< " and a carton contains " << carton / tryBox
						<< " candy boxes." << endl;
				}
			}
		}
	}
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

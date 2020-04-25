// Ex2_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Demontrating type-safe and non-type-safe enumerations

#include <iostream>

using std::cout;
using std::endl;

// You can define enumerations at global scope 
// enum Jewels {Diamonds, Emeralds, Rubies};	// Uncomment this for an error
enum Suit : long {Clubs, Diamonds, Hearts, Spades};

int main()
{
    // Using the old enumeration type...
	Suit suit {Clubs};							// You can use old enumerator names directly
	Suit another {Suit::Diamonds};				// or you can qualify them

	// Automatic conversionn from enumeration type to integer 
	cout << "suit value: " << suit << endl;
	cout << "Add 10 to another: " << another + 10 << endl;

	// Using type-safe enumerations...
	enum class Color : char {Red, Orage, Yellow, Green, Blue, Indigo, Violet};
	Color skyColor {Color::Blue};				// You must qualify enumerator names
	// Color grassColor{Green}					// Uncomment for an error 

	// No auto conversion to numeric type 
	cout << endl
		<< "Sky color value: "
		<< static_cast<long>(skyColor) << endl;

	// cout << skyColor + 10L << endl;				
	cout << "Incremented sky color: "
		<< static_cast<long>(skyColor) + 10L	// OK with explicit cast 
		<< endl;
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

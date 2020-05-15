// Ex7_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A class with private members

#include <iostream>

using std::cout;
using std::endl;

class CBox					// Class definition at global scope
{
public:
	// Constructor definition
	explicit CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0):
		m_Length {lv}, m_Width {wv}, m_Height {hv}
	{
		cout << "Constructor called." << endl;
	}

	// Function to calculate the volume of a box
	double volume()
	{
		return m_Length*m_Width*m_Height;
	}

private:
	double m_Length;		// Length of a box in inches
	double m_Width;			// Width of a box in inches
	double m_Height;		// Height of a box in inches

};

int main()
{
	CBox match {2.2, 1.1, 0.5};		// Declare match box
	CBox box2;						// Declare box2 - no initial values
	
	cout << "Volume of match = " << match.volume() << endl;

	cout << "Volume of box2 = " << box2.volume() << endl;

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

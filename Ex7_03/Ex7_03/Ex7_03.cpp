// Ex7_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Calculating the volume of a box with a member function
// Using a constructor

#include <iostream>

using std::cout;
using std::endl;

class CBox					// Class definition at global scope
{
public:
	double m_Length {1.0};	// Length of a box in inches
	double m_Width {1.0};	// Width of a box in inches
	double m_Height{ 1.0 };	// Height of a box in inches

	// Constructor definition
	CBox(double lv, double wv, double hv)
	{
		cout << "Constructor called." << endl;
		m_Length = lv;		// Set values of data members
		m_Width = wv;
		m_Height = hv;
	}

	// Function to calculate the volume of a box
	double volume()
	{
		return m_Length*m_Width*m_Height;
	}
};

int main()
{
	CBox box1 {78.0, 24.0, 18.0}, cigarBox {8.0, 5.0, 1.0};

	cout << "Volume of box1 = " << box1.volume() << endl;
	cout << "Volume of cigarBox = " << cigarBox.volume() << endl;
	cout << "A CBox object occupies "
		<< sizeof box1 << " bytes." << endl;

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

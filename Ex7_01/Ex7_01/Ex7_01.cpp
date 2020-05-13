// Ex7_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercising structures in the yard

#include <iostream>

using std::cout;
using std::endl;

// Definition of a struct to represent rectangles
struct Rectangle
{
	int left;			// Top-left point coordinate pair
	int top;					

	int right;			// Bottom-right point coordinate pair
	int bottom;
};

// Prototype of function to calculate the area of a rectangle
long area(const Rectangle& aRect);

// Prototype of function to move a rectangle
void moveRect(Rectangle& aRect, const int x, const int y);

int main()
{
    Rectangle yard {0, 0, 100, 120};
	Rectangle pool {30, 40, 70, 80};
	Rectangle hut1, hut2;

	hut1.left = 70;
	hut1.top = 10;
	hut1.right = hut1.left + 25;
	hut1.bottom = 30;

	hut2 = hut1;			// Define hut2 the same as hut1
	moveRect(hut2, 10, 90);	// Now move it the right position

	cout << "Coordinates of hut2 are "
		<< hut2.left << "," << hut2.top << " and "
		<< hut2.right << "," << hut2.bottom << endl;

	cout << "The area of the yard is " << area(yard) << endl;

	cout << "The area of pool is " << area(pool) << endl;

	return 0;
}

// Function to calculate the area of a rectangle 
long area(const Rectangle& aRect)
{
	return (aRect.right - aRect.left) * (aRect.bottom - aRect.top);
}

// Function to Move a Rectangle
void moveRect(Rectangle& aRect, const int x, const int y)
{
	const int length {aRect.right - aRect.left};	// Get length of rectangle
	const int width {aRect.bottom - aRect.top};		// Get width of rectangle

	aRect.left = x;			// Set top-left point to new position
	aRect.top = y;			
	aRect.right = x + length;		// Get bottom-right point as increment from new position
	aRect.bottom = y + width;
	return;
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

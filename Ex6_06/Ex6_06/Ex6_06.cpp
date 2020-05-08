// Ex6_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Catching an exception thrown by new

#include <iostream>
#include <new>				// For bad_alloc type

using std::bad_alloc;
using std::cout;
using std::endl;

int main()
{
    char* pdata {};
	size_t count {~static_cast<size_t>(0)/2};
	cout << "Array size = " << count << endl;
	try
	{
		pdata = new char[count];
		cout << "Memory allocated." << endl;
	}
	catch (bad_alloc& ex)
	{
		cout << "memory allocation failed." << endl
			<< "The information from the exception object is: "
			<< ex.what() << endl;
	}
	delete[] pdata;
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

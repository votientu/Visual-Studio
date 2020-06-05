// Ex8_15.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Creating and joining string objects

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Lisht names and ages
void listnames(string names[], string ages[], size_t count)
{
	cout << "The names you entered are: " << endl;
	for (size_t i{}; i < count && !names[i].empty(); ++i)
		cout << names[i] + " aged " + ages[i] + '.' << endl;
}

int main()
{
	const size_t count{ 100 };
	string names[count];
	string ages[count];
	string firstname, secondname;

	for (size_t i{}; i < count; ++i)
	{
		cout << "Enter a first name or press Enter to end: ";
		std::getline(std::cin, firstname, '\n');
		if (firstname.empty())
		{
			listnames(names, ages, i);
			cout << "Done!!" << endl;
			return 0;
		}

		cout << "Enter a second name: ";
		std::getline(std::cin, secondname, '\n');

		names[i] = firstname + ' ' + secondname;
		cout << "Enter " + firstname + "'s age: ";
		std::getline(std::cin, ages[i], '\n');

		cout << endl;
	}

	cout << "No space for more names." << endl;
	listnames(names, ages, count);
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

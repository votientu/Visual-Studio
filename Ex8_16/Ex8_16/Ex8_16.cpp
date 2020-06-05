// Ex8_16.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Comparing and sorting words

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

string* sort(string* strings, size_t count)
{
	bool swapped{ false };
	while (true) {
		for (size_t i{}; i < count - 1; i++)
		{
			if (strings[i] > strings[i + 1])
			{
				swapped = true;
				strings[i].swap(strings[i + 1]);
			}
		}
		if (!swapped)
			break;
		swapped = false;
	}
	return strings;
}

int main()
{
	const size_t maxstrings{ 100 };
	string strings[maxstrings];
	size_t nstrings{};
	size_t maxwidth{};

	// Read up to 100 words into the strings array
	while (nstrings < maxstrings)
	{
		cout << "Enter a word or press Enter to end: ";
		std::getline(std::cin, strings[nstrings]);
		if (maxwidth < strings[nstrings].length())
			maxwidth = strings[nstrings].length();
		if (strings[nstrings].empty())
			break;
		++nstrings;
	}

	// Sort the input in ascending sequence
	sort(strings, nstrings);
	cout << endl
		<< "In ascending sequence, the words you entered are:"
		<< endl
		<< std::setiosflags(std::ios::left);		// Left-justify the output
	for (size_t i{}; i < nstrings; i++)
	{
		if (i % 5 == 0)
			cout << endl;
		cout << std::setw(maxwidth + 2) << strings[i];
	}
	cout << endl;
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

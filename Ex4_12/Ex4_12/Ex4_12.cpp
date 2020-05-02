// Ex4_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Searching a string

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
	char str[]{ "Smith, where Jones had had\"had had\" had had \"had\"."
		"\n\"Had had had had the examiners' approval." };
	const char* word{ "had" };
	cout << "The string to be searched is: " << endl << str << endl;

	int count{};						// Number of occurrences of word in str 
	char* pstr {str};					// Pointer to search start position
	char* found {};						// Pointer to occurrence of word in str 
	const size_t wordLength { std::strlen(word) };

	while (true)
	{
		found = std::strstr(pstr, word);
		if (!found)
			break;
		++count;
		pstr = found + wordLength;
		// Set next search start as 1 past the word found
	}
	cout << "\"" << word << "\" was found "
		<< count << " times in the string." << endl;
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

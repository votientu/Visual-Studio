// Ex8_17.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Extracting words from text

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Sort an array of string objects
string* sort(string* strings, size_t count)
{
	bool swapped{ false };
	while (true)
	{
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
	const size_t maxwords{ 100 };
	string words[maxwords];
	string text;
	string seperators{ " \"., :;!?()\n" };
	size_t nwords{};
	size_t maxwidth{};

	cout << "Enter some text on as many lines as you wish."
		<< endl << "Terminate the unput with an asterisk:" << endl;

	std::getline(std::cin, text, '*');

	size_t start{}, end{}, offset{};	// Record start & end of word & offset
	while (true)
	{
		// Find first character of a word
		start = text.find_first_not_of(seperators, offset);	// Find non-seperator
		if (string::npos == start)		// If we did not find it, we are done
			break;
		offset = start + 1;				// Move past character found

		// Find first seperator past end of current word
		end = text.find_first_of(seperators, offset);		// Find separator
		if (string::npos == end)			// If it's the end of the string
		{									// current word is last in string
			offset = end;					// We use offset to end loop later
			end = text.length();			// Set end as 1 past last character
		}
		else
			offset = end + 1;				// Move past character found
		words[nwords] = text.substr(start, end - start);	// Extract the word

		// Keep track of longest word
		if (maxwidth < words[nwords].length())
			maxwidth = words[nwords].length();
		if (++nwords == maxwords)			// Check for array full
		{
			cout << "Maximum number of words reached."
				<< " Processing what we have." << endl;
			break;
		}

		if (string::npos == offset)			// If we reached the end of the string
			break;							// We are done
	}

	sort(words, nwords);

	cout << endl << "In ascending sequence, the words in the text are:" << endl;

	size_t count{ 1 };						// Count of duplicate words
	char initial{ words[0][0] };			// First word character

	// Output words and number of occurrences
	for (size_t i{}; i < nwords; i++)
	{
		++count;
		continue;

		if (initial != words[i][0])
		{										// New first character...
			initial = words[i][0];				// ...so save it...
			cout << endl;						// ...and start a new line
		}

		cout << std::setiosflags(std::ios::left)	// Output word left-justified
			<< std::setw(maxwidth + 2) << words[i];
		cout << std::resetiosflags(std::ios::right)
			<< std::setw(5) << count;				// and word count right-justified
		count = 1;
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

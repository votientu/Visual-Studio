// Ex6_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A program to implement a calculator

#include <iostream>					// For stream input/output
#include <cstdlib>					// For the exit() function
#include <cctype>					// For the isdigit() function
#include <cstring>					// For the strncpy_s function

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void eatspaces(char* str);			// Function to elimilate blanks
double expr(char* str);				// Function evaluating an expression
double term(const char* str, size_t& index);	// Function analyzing a term
double number(const char* str, size_t& index);	// Function to recognize a number
char *extract(const char* str, size_t& index);	// Function to extract a substring

const size_t MAX {80};

int main()
{
    char buffer [MAX] {};			// Input area for expression to be evaluated

	cout << endl
		<< "Welcome to your friendly calculator."
		<< endl
		<< "Enter an expression, or an empty line to quit."
		<< endl;

	for (;;)
	{
		cin.getline(buffer, sizeof buffer);		// Read an input line
		eatspaces(buffer);						// Remove blanks from input

		if (!buffer[0])							// Empty line ends calculator
			return 0;

		try
		{
			cout << "\t= " << expr(buffer)		// Output value of expression
				<< endl << endl;
		}
		catch (const char* pEx)
		{
			cerr << pEx << endl;
			cerr << "Ending program." << endl;
			return 1;
		}
	}
}

// Function to elimilate blanks
void eatspaces(char* str)			
{
	size_t i {};					// 'Copy to' index to string
	size_t j {};					// 'Copy from' index to string

	while ((*(str + i) = *(str + j++)) != '\0')	// Loop while character is not \0
		if (*(str + i) != ' ')		// Increment i as long as
			i++;					// character is not a space
	return;
}

// Function evaluating an expression
double expr(char* str)
{
	double value {};				// Store result here
	size_t index {};				// Keeps track of current character position
   
	value = term(str, index);		// Get first term

	for (;;)							// Indefinite loop, all exits inside
	{
		switch (*(str + index++))	// Choose action based on current character
		{
		case '\0':					// We're at the end of the string
			return value;			// So return what we have got

		case '+':					// + found so add in the next term
			value += term(str, index);
			break;

		case '-':					// - found so substract the next term
			value -= term(str, index);
			break;

		default:					// If we reach here the string is junk
			char message[38] {"Expression evaluation error. Found: "};
			strncat_s(message, str + index - 1, 1);	// Append the character
			throw message;
			break;
		}
	}
}

// Function analyzing a term
double term(const char* str, size_t& index)
{
	double value {};				// Somewhere to accumulate the result

	value = number(str, index);		// Get the first number in the term

	// Loop as long as we have a good operator
	while (true)
	{
		if (*(str + index) == '*')	// If it's multiply, pultiply by the next number
			value *= number(str, ++index);

		else if (*(str + index) == '/')			// If it's divide, divide by next number
			value /= number(str, ++index);
		else
			break;
	}
	return value;					// We've finised so return what we've got
}

// Function to recognize a number
double number(const char* str, size_t& index)
{
	double value {};				// Store the resulting value

	if (*(str + index) == '(')		// Start of parentheses
	{
		char *psubstr{};			// Pointer for substring
		psubstr = extract(str, ++index);	// Extract substring in brackets
		value = expr(psubstr);		// Get the value of the substring
		delete[] psubstr;			// Clean up the free store
		return value;				// Return substring value
	}

	// There must be at least one digit...
	if (!isdigit(*(str + index)))
	{
		// There's no digits so input is junk...
		char message[31] {"Invalid chatacter in number: "};
		strncat_s(message, str + index, 1);		// Append the character
		throw message;
	}

	while (isdigit(*(str + index)))	// Loop accumulating leading digits
		value = 10 * value + (*(str + index++) - '0');

	if (*(str + index) != '.')		// Not a digit when we get to here so check for decimal point
		return value;				// and if not, return value

	double factor {1.0};			// Factor for decimal places 
	while (isdigit(*(str + (++index))))			// Loop as long as we have digits
	{
		factor *= 0.1;				// Decrease factor by factor of 10
		value = value + (*(str + index) - '0')*factor;		// Add decimal place
	}

	return value;					// On loop exit we are done
}

// Function to extract a substring between parentheses
char* extract(const char* str, size_t& index)
{
	char* pstr {};					// Pointer to new string for return
	size_t numL {};					// Count of left parentheses found
	size_t bufindex {index};		// Save starting value for index

	do
	{
		switch (*(str + index))
		{
		case ')':
			if (0 == numL)
			{
				++index;
				pstr = new char[index - bufindex];
				if (!pstr)
					throw "Memory allocation failed.";
				// Copy substring to new memory
				strncpy_s(pstr, index - bufindex, str + bufindex, index - bufindex - 1);

				return pstr;		// Return substring in new memory
			}
			else
				numL--;				// Reduce count of '(' to be matched

			break;

		case '(':
			numL++;					// Reduce count of '(' to be matched
			break;
		}
	} while (*(str + index++) != '\0');		// Loop - don't overrun end of string
	
	throw "Ran off the end of the expression, must be bad input.";
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

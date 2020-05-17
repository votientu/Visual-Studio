// Ex8_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Overloaded assignment  operator working well

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class CMessage
{
private:
	char* m_pMessage;			// Pointer to object text string

public:
	// Function to display a message
	void showIt() const
	{
		cout << m_pMessage << endl;
	}

	// Function to reset a message to *
	void reset()
	{
		char* temp {m_pMessage};
		while (*temp)
			*(temp++) = '*';
	}

	// Overloaded assigment operator for CMessage objects
	CMessage& operator=(const CMessage& aMess)
	{
		if (this != &aMess)		// Check addresses are not equal
		{
			// Release memory fro 1st operand
			delete[] m_pMessage;
			size_t length {strlen(aMess.m_pMessage) + 1};
			m_pMessage = new char[length];

			// Copy 2nd operand string to 1st
			strcpy_s(this->m_pMessage, length, aMess.m_pMessage);
		}
		return *this;			// Return a reference to 1st operand
	}

	// Constructor definition 
	CMessage(const char* text = "Default message")
	{
		size_t length {strlen(text) + 1};
		m_pMessage = new char[length];		// Allocate space for text
		strcpy_s(m_pMessage, length, text);	// Copy text to new memory
	}

	// Copy constructor definition
	CMessage(const CMessage& aMess)
	{
		size_t length {strlen(aMess.m_pMessage) + 1 };
		m_pMessage = new char[length];					// Allocate space for text
		strcpy_s(m_pMessage, length, aMess.m_pMessage);	// Copy text to new memory
	}

	// Destructor to free memory allocated by new
	~CMessage()
	{
		cout << "Destructor called." << endl;			// Just to track what happens
		delete[] m_pMessage;
	}
};

int main()
{
	CMessage motto1 {"The devil takes care of his own."};
	CMessage motto2;
	cout << "motto2 contains:" << endl;
	motto2.showIt();
	motto2 = motto1;			// Use new assigment operator
	cout << "motto2 contains:" << endl;
	motto2.showIt();

	motto1.reset();

	cout << "motto1 now contains:" << endl;
	motto1.showIt();
	cout << "motto2 still contains:" << endl;
	motto2.showIt();

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

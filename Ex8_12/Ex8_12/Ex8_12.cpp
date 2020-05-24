// Ex8_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Default values for class template parameters

#include <iostream>
#include <utility>			// For operator overload templates
#include <algorithm>		// For max(), swap() used in CBox

using std::cout;
using std::endl;
using namespace std::rel_ops;	

class CBox
{

};

// CSamples class template definition
template<typename T = double, size_t Size = 100> class CSamples
{
public:
	// Constructors
	CSamples(const T values[], int count);
	CSamples(const T& value);
	CSamples(T&& value);
	CSamples() = default;

	bool add(const T& value);		// Insert a value
	bool add(T&& value);			// Insert a value with move sematics
	T max() const;					// Calculate maximum

private:
	T m_Values[Size];		// Array to store samples
	int m_Next{};			// Index of free location in m_Values
};

// Constructor template definition to accept an array of samples
template<typename T, size_t Size>
CSamples<T, Size>::CSamples(const T values[], int count)
{
	m_Next = count < Size ? count : Size;		// Don't exceed the array
	for (int i{}; i < m_Next; i++)				// Store count of samples
		m_Values[i] = values[i];
}

// Constructor to accept a single sample
template<typename T, size_t Size>
CSamples<T, Size>::CSamples(const T& value)
{
	m_Values[0] = value;			// Store the sample
	m_Next = 1;						// Next is free
}

// Constructor to accept a temporary sample
template<typename T, size_t Size>
CSamples<T, Size>::CSamples(T&& value)
{
	cout << "Move constructor." << endl;
	m_Values[0] = std::move(value);	// Store the sample
	m_Next = 1;						// Next is free
}

// Function to add a sample
template<typename T, size_t Size>
bool CSamples<T, Size>::add(const T& value)
{
	cout << "Add." << endl;
	bool OK{ m_Next < Size };		// Indicates there is a free space
	if (OK)
		m_Values[m_Next++] = value;	// OK true, so store the value
	return OK;
}

template<typename T, size_T Size>
bool CSamples<T, Size>::add(T&& value)
{
	cout << "Add move." << endl;
	bool OK{ m_Next < Size };						// Indicates there is a free space
	if (OK)
		m_Values[m_Next++] = std::move(value);		// OK true, so store the value
	return OK;
}

// Function to obtain maximum sample
template<typename T, size_t Size>
T CSamples<T, Size>::max() const
{
	T theMax{ m_Values[0] };						// Set first sample as maximum
	for (int i{ 1 }; i < m_Next; i++)				// Check all the samples
		if (theMax < m_Values[i])
			theMax = m_Values[i];					// Store any larger sample
	return theMax;
}

int main()
{
    CBox boxes[] {									// Create an array of boxes
		CBox {8.0, 5.0, 2.0},						// Initialize the boxes
		CBox {5.0, 4.0, 6.0},
		CBox {4.0, 3.0, 3.0}
	};

	// Create the CSamples object to hold CBox objects
	CSamples<CBox> myBoxes{ boxes, _countof(boxes) };

	CBox maxBox{ myBoxes.max() };					// Get the biggest box
	cout << "The biggest box has a volume of "		// and output its volume
		<< maxBox.volume() << endl;

	double values[]{ 2.5, 3.6, 4.7, -15.0, 6.8, 7.2, -8.1 };
	CSamples<> data{ values, _countof(values) };
	cout << "Maximum double value = " << data.max() << endl;

	// Uncomment next line for an error
	// CSamples<, _countof(values)> baddata{values, _countof(values)};

	int counts[]{ 21, 32, 444, 15, 6, 7, 8 };
	CSamples<int, _countof(counts)> dataset{ counts, _countof(counts) };
	cout << "Maximum int value = " << dataset.max() << endl;

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

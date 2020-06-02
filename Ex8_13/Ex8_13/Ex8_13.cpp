// Ex8_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>									// input and output stream
#include <algorithm>								// to use min, max, swap
#include <utility>									// for operators overloading

class CBox
{
public:
	CBox(const CBox& obj) = default;				// Copy constructor
	CBox& operator=(const CBox& obj) = default;		// Assignement operator
	~CBox() = default;								// Destructor

	explicit CBox(double lv=1.0, double wv=1.0, double hv=1.0):
		m_Length{ std::max(lv, wv) }, m_Width{ std::min(lv, wv) }, m_Height{ hv }
	{
		// We then need to ensure the heigh <= width <= length
		// At this point, width <= length
		if (m_Height > m_Length)					// so m_Width <= m_Length < m_Height 
		{
			std::swap(m_Height, m_Length);			// m_Length is the biggest
			std::swap(m_Width, m_Height);			// m_Height is the smallest, Done!
		}
		else if (m_Height > m_Width)				// so m_Width < m_Height =< m_Length
			std::swap(m_Width, m_Height);
	}

	double volume() const							// Calculate the volume of a box
	{
		return m_Length * m_Width * m_Height;
	}

	// Comparison operators, if (myBox < aBox)
	// They all will be inline by default because they are written in class definition
	bool operator<(const CBox& aBox) const
	{
		return this->volume() < aBox.volume();
	}

	bool operator==(const CBox& aBox) const
	{
		return this->volume() == aBox.volume();
	}

	// Compare with a value, if (myBox < 10.0)
	bool operator>(const double value) const
	{
		return volume() > value;
	}

	bool operator<(const double value) const
	{
		return volume() < value;
	}
	
	bool operator>=(const double value) const
	{
		return volume() >= value;
	}
	
	bool operator<=(const double value) const
	{
		return volume() <= value;
	}

	bool operator==(const double value) const
	{
		return volume() == value;
	}

	bool operator!=(const double value) const
	{
		return volume() != value;
	}

	// Getters
	double getLength() const { return m_Length; }
	double getWidth() const { return m_Width; }
	double getHeight() const { return m_Height; }

private:
	double m_Length, m_Width, m_Height;
};

//  Comparison operators with left opererand of type double, if (10.0 > aBox)
inline bool operator>(const double value, const CBox& aBox)
{
	return value > aBox.volume();
}

inline bool operator<(const double value, const CBox& aBox)
{
	return value < aBox.volume();
}

inline bool operator>=(const double value, const CBox& aBox)
{
	return value >= aBox.volume();
}

inline bool operator<=(const double value, const CBox& aBox)
{
	return value <= aBox.volume();
}

inline bool operator==(const double value, const CBox& aBox)
{
	return value == aBox.volume();
}

// CBox multiply operator this * n
CBox operator*(int n) const
{
	if (n % 2)
		return CBox{ m_Length, m_Width, m_Height };				// n odd
	else
		return CBox{ m_Length, 2.0*m_Width, (n / 2)*m_Height };	// n even
}

// CBox multiply operator n * aBox
CBox operator*(int n, const CBox& aBox)
{
	return aBox * n;
}

int operator/(const CBox& aBox) const
{
	// Number of boxes in horizontal plane this way
	int tc1{ 
		static_cast<int>(m_Length / aBox.m_Length) * static_cast<int>(m_Width / aBox.m_Width);
	};
	// Number of boxes in horizontal plane this way
	int tc2{
		static_cast<int>(m_Length / aBox.m_Width) * static_cast<int>(m_Width / aBox.m_Length);
	};
	// Return best fit
	return static_cast<int>((m_Height / aBox.m_Height) * (tc1 > tc2 ? tc1 : tc2));
}

// Operator to return the free volume in a packed box
inline double operator%(const CBox& aBox, const CBox& bBox)
{
	return aBox.volume() - ((aBox / bBox) * bBox.volume());
}

int main()
{
    std::cout << "Hello World!\n";
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

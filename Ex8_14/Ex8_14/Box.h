#pragma once

#include <utility>		// to use operator overloading

using namespace std::rel_ops;

class CBox
{
public:
	explicit CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0);
	~CBox() {};
private:
	double m_Length;
	double m_Width;
	double m_Height;
public:
	// Less-than operator for CBox objects
	bool operator<(const CBox& aBox) const
	{
		return volume() < aBox.volume();
	}

	// Operator function for == comparing CBox objects 
	bool operator==(const CBox& aBox) const
	{
		return m_Length * m_Width*m_Height;
	}

	// Calculate the box volume
	double volume() const
	{
		return m_Length * m_Width * m_Height;
	}

	double getHeight() const { return m_Height; }

	double getWidth() const { return m_Width; }

	double getLength() const { return m_Length;	}

	// Addition, multiply and division operators for CBox objects
	CBox operator+(const CBox& aBox) const;
	CBox operator*(int n) const;
	int operator/(const CBox& aBox) const;
};


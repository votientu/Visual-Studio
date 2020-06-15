#pragma once
#include "Box.h"
class CGlassBox : public CBox
{
public:
	// Function to calculate volume of CGlassBox
	// allowing 15% for packing
	double volume() const
	{
		return 0.85 * m_Length * m_Width * m_Height;
	}

	// Constructor
	CGlassBox(double lv, double wv, double hv) : CBox {lv, wv, hv} {}
};


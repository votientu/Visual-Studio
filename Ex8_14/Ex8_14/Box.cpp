#include "Box.h"
#include <algorithm>		// to use max, min, swap

CBox::CBox(double lv, double wv, double hv) :
	m_Length{ std::max(lv, wv) }, m_Width{ std::min(lv, wv) }, m_Height{ hv }
{
	if (lv < 0.0 || wv < 0.0 || hv < 0.0)
		throw "Negative dimension specified for CBox object.";
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

// Add operator
CBox CBox::operator+(const CBox& aBox) const
{
	// New object has larger length and width and sum of the heights
	return CBox{ std::max(m_Length, aBox.m_Length),
		std::max(m_Width, aBox.m_Width),
		m_Height + aBox.m_Height };
}

CBox CBox::operator*(int n) const
{
	return CBox{ m_Length * n, m_Width * n, m_Height * n };
}

int CBox::operator/(const CBox& aBox) const
{
	return static_cast<int>(volume() / aBox.volume());
}
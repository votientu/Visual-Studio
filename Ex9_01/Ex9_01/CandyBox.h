#pragma once
#include "Box.h"
#include <iostream>
#include <cstring>				// For strlen() and strcpy_s()
 class CCandyBox : public CBox
{
public:
	 char* m_Contents;

	 // Constructor to set dimensions and contents
	 // with explicit call of CBox constructor
	 CCandyBox(double lv, double wv, double hv, const char* str = "Candy")
		 : CBox{ lv, wv, hv }
	 {
		 std::cout << "CCandyBox constructor2 called" << std::endl;
		 size_t length{ strlen(str) + 1 };
		 m_Contents = new char[length];
		 strcpy_s(m_Contents, length, str);
	 }

	 // Constructor to set contents
	 // calles default CBox constructor automatically
	 explicit CCandyBox(const char* str = "Candy")		// Constructor
	 {
		 std::cout << "CCandyBox constructor1 called" << std::endl;
		 size_t length {strlen(str) + 1};
		 m_Contents = new char[length];
		 strcpy_s(m_Contents, length, str);
	 }

	 // Derived class copy constructor
	 CCandyBox(const CCandyBox& initB) : CBox {initB}
	 {
		 std::cout << "CCandyBox copy constructor called" << std::endl;
		 size_t length{ strlen(initB.m_Contents) + 1 };
		 m_Contents = new char[length];					// Get new memory
		 strcpy_s(m_Contents, length, initB.m_Contents);// Copy string
	 }

	 // Move constructor
	 CCandyBox(CCandyBox& initB) : CBox{ std::move(initB) }
	 {
		 std::cout << "CCandyBox move constructor called" << std::endl;
		 m_Contents = initB.m_Contents;
		 initB.m_Contents = 0;
	 }

	 // Function to calculate the volume of a CBox object
	 double volume() const
	 {
		 return m_Length * m_Width * m_Height;
	 }

	 CCandyBox& operator=(const CCandyBox& box) = delete;

	 ~CCandyBox()										// Destructor
	 {
		 std::cout << "CCandyBox destructor called" << std::endl;
		 delete[] m_Contents;
	 }
};


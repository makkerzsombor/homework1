#include "Fragment.h"
#include <cmath>

Fragment::Fragment(const int numerator, const int denominator) {
	if (!denominator)
	{
		std::cout << "Nem lehet a nevezo nulla!" << std::endl;
		// Default value
		mNumerator = 0;
		mDenomintator = 1;
	}
	else
	{
		// denominator is negative
		if (denominator < 0) {
			mNumerator = -numerator;
			mDenomintator = -denominator;
		}
		else {
			mNumerator = numerator;
			mDenomintator = denominator;
		}
		int divider = DividedBy(mNumerator, mDenomintator);
		//std::cout << "divider: " << divider << std::endl; // for testing
		if (divider > 1)
		{
			//std::cout << "Alapok: " << std::endl; // for testing
			//std::cout << ToString() << std::endl; // for testing
			DivideWithThis(divider);
			//std::cout << "Belep a dividerbe!" << std::endl << std::endl; // for testing
		}	
	}
}

Fragment::Fragment(const int numerator)
{
	mNumerator = numerator;
	mDenomintator = 1;
}

Fragment::Fragment(const double decimal)
{
	int precision = 1000000;
	mNumerator = std::round(decimal * precision);
	mDenomintator = precision;
	int divider = DividedBy(mNumerator, mDenomintator);
	if (divider > 1) 
	{
		DivideWithThis(divider);
	}
}

Fragment::Fragment(const Fragment& other)
{
	mNumerator = other.mNumerator;
	mDenomintator = other.mDenomintator;
}

std::string Fragment::ToString() const
{
	std::string s = std::to_string(mNumerator);
	s += "/";
	s += std::to_string(mDenomintator);
	return s;
}

int Fragment::GetNumerator() const
{
	return mNumerator;
}

int Fragment::GetDenominator() const
{
	return mDenomintator;
}

Fragment::~Fragment()
{
	//std::cout << GetNumerator() << "/" << GetDenominator() << std::endl; // for testing
	std::cout << "A tort megsemmisult!" << std::endl;
}

int Fragment::DividedBy(const int a, const int b)
{
	int c = std::abs(a);
	int d = std::abs(b);

	if (c == 0)
	{
		return 1;
	}

	while (d) // d != 0; 
	{
		int temp = d; 
		d = c % d; // maradék = c mod d
		c = temp; // léptetés
	}
	return c;
}

void Fragment::DivideWithThis(const int a)
{
	mNumerator /= a;
	mDenomintator /= a;
}

// Operators

Fragment& operator+=(Fragment& current, const Fragment& other)
{
	int newNumerator = (current.GetNumerator() * other.GetDenominator()) + (other.GetNumerator() * current.GetDenominator());
	int newDenominator = current.GetDenominator() * other.GetDenominator();
	current = Fragment(newNumerator, newDenominator);
	return current;
}

Fragment operator+(const Fragment& current, const Fragment& other) 
{
	Fragment result = current;
	return result += other; // meghívja a += -t
}

Fragment& operator-=(Fragment& current, const Fragment& other)
{
	Fragment negativeOther = Fragment(-other.GetNumerator(), other.GetDenominator());
	return current += negativeOther;
}

Fragment operator-(const Fragment& current, const Fragment& other)
{
	Fragment result = current;
	return result -= other; // meghívja a -= -t
}

Fragment& operator*=(Fragment& current, const Fragment& other) 
{
	int newNumerator = current.GetNumerator() * other.GetNumerator();
	int newDenominator = current.GetDenominator() * other.GetDenominator();
	current = Fragment(newNumerator, newDenominator);
	return current;
}

Fragment operator*(const Fragment& current, const Fragment& other) 
{
	Fragment result = current;
	return result *= other; // meghívja a *= -t
}

Fragment& operator/=(Fragment& current, const Fragment& other) 
{
	Fragment reciprocalOther = Fragment(other.GetDenominator(), other.GetNumerator());
	return current *= reciprocalOther;
}

Fragment operator/(const Fragment& current, const Fragment& other) 
{
	Fragment result = current;
	return result /= other; // meghívja a /= -t
}
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
	mNumerator = decimal * precision;
	mDenomintator = precision;
	//std::cout << "At alakitva: " << getNumerator() << std::endl; // for testing
	double vissza = static_cast<double>(mNumerator) / precision;
	//std::cout << "a valodi erteke: " << vissza << std::endl; // for testing
}

Fragment::Fragment(const Fragment& other)
{
	mNumerator = other.mNumerator;
	mDenomintator = other.mDenomintator;
}

std::string Fragment::ToString() const
{
	std::string s = "A tort szamlaloja: ";
	s += std::to_string(mNumerator);
	s += ", nevezoje: ";
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
	result += other;
	return result;
}

Fragment& operator-=(Fragment& current, const Fragment& other)
{
	Fragment negativeOther = Fragment(-other.GetNumerator(), other.GetDenominator());
	return current += negativeOther;
}

Fragment operator-(const Fragment& current, const Fragment& other)
{
	Fragment result = current;
	result -= other;
	return result;
}
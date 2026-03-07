#include "Fragment.h"
#include <cmath>
#include <sstream>

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
	int num = std::round(decimal * precision);
	int den = precision;
	*this = Fragment(num, den);
}

Fragment::Fragment(const Fragment& other)
{
	mNumerator = other.mNumerator;
	mDenomintator = other.mDenomintator;
}

std::string Fragment::ToString() const
{
	return std::to_string(mNumerator) + "/" + std::to_string(mDenomintator);
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

bool operator==(const Fragment& current, const Fragment& other)
{
	return (current.GetNumerator() == other.GetNumerator() &&  
		current.GetDenominator() == other.GetDenominator());
}

bool operator!=(const Fragment& current, const Fragment& other)
{
	return !(current == other); // meghívja a == -t
}

bool operator<(const Fragment& current, const Fragment& other) 
{
	return (current.GetNumerator() * other.GetDenominator() <
		current.GetDenominator() * other.GetNumerator());
}

bool operator<=(const Fragment& current, const Fragment& other) 
{
	return !(current > other); // meghívja a > -t
}

bool operator>(const Fragment& current, const Fragment& other) 
{
	return other < current; // meghívja a < -t csak megfordítva a bemeneteket
}

bool operator>=(const Fragment& current, const Fragment& other) 
{
	return !(current < other); // meghívja a < -t
}

// Converion Operators

Fragment::operator int() const
{
	return mNumerator / mDenomintator;
}

Fragment::operator double() const
{
	return static_cast<double>(mNumerator) / mDenomintator;
}

Fragment::operator bool() const
{
	return mNumerator != 0;
}

Fragment::operator std::string() const
{
	return ToString();
}

// IOStream Operators

std::ostream& operator<<(std::ostream& os, const Fragment& fragment)
{
	os << fragment.ToString();
	return os;
}

std::istream& operator>>(std::istream& is, Fragment& fragment)
{
	int num = 0, den = 1;
	char slash; 

	is >> num >> slash >> den;

	if (slash == '/') {		
		fragment = Fragment(num, den);
	}
	else {
		is.setstate(std::ios::failbit);
	}
	return is;
}

Fragment::Fragment(const std::string& str)
{
	std::stringstream ss(str);
	int num = 0;
	int den = 1;
	char slash;

	ss >> num;

	if (ss >> slash && slash == '/') {
		ss >> den;
	}
	*this = Fragment(num, den);
}
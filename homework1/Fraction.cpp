#include "Fraction.h"
#include <cmath>
#include <sstream>

Fraction::Fraction(const int numerator, const int denominator) {
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

Fraction::Fraction(const int numerator)
{
	mNumerator = numerator;
	mDenomintator = 1;
}

Fraction::Fraction(const double decimal)
{
	int precision = 1000000;
	int num = std::round(decimal * precision);
	int den = precision;
	*this = Fraction(num, den);
}

Fraction::Fraction(const Fraction& other)
{
	mNumerator = other.mNumerator;
	mDenomintator = other.mDenomintator;
}

std::string Fraction::ToString() const
{
	return std::to_string(mNumerator) + "/" + std::to_string(mDenomintator);
}

int Fraction::GetNumerator() const
{
	return mNumerator;
}

int Fraction::GetDenominator() const
{
	return mDenomintator;
}

int Fraction::DividedBy(const int a, const int b)
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

void Fraction::DivideWithThis(const int a)
{
	mNumerator /= a;
	mDenomintator /= a;
}

// Operators

Fraction& operator+=(Fraction& current, const Fraction& other)
{
	int newNumerator = (current.GetNumerator() * other.GetDenominator()) + (other.GetNumerator() * current.GetDenominator());
	int newDenominator = current.GetDenominator() * other.GetDenominator();
	current = Fraction(newNumerator, newDenominator);
	return current;
}

Fraction operator+(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result += other; // meghívja a += -t
}

Fraction& operator-=(Fraction& current, const Fraction& other)
{
	Fraction negativeOther = Fraction(-other.GetNumerator(), other.GetDenominator());
	return current += negativeOther;
}

Fraction operator-(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result -= other; // meghívja a -= -t
}

Fraction& operator*=(Fraction& current, const Fraction& other)
{
	int newNumerator = current.GetNumerator() * other.GetNumerator();
	int newDenominator = current.GetDenominator() * other.GetDenominator();
	current = Fraction(newNumerator, newDenominator);
	return current;
}

Fraction operator*(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result *= other; // meghívja a *= -t
}

Fraction& operator/=(Fraction& current, const Fraction& other)
{
	Fraction reciprocalOther = Fraction(other.GetDenominator(), other.GetNumerator());
	return current *= reciprocalOther;
}

Fraction operator/(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result /= other; // meghívja a /= -t
}

bool operator==(const Fraction& current, const Fraction& other)
{
	return (current.GetNumerator() == other.GetNumerator() &&  
		current.GetDenominator() == other.GetDenominator());
}

bool operator!=(const Fraction& current, const Fraction& other)
{
	return !(current == other); // meghívja a == -t
}

bool operator<(const Fraction& current, const Fraction& other)
{
	return (current.GetNumerator() * other.GetDenominator() <
		current.GetDenominator() * other.GetNumerator());
}

bool operator<=(const Fraction& current, const Fraction& other)
{
	return !(current > other); // meghívja a > -t
}

bool operator>(const Fraction& current, const Fraction& other)
{
	return other < current; // meghívja a < -t csak megfordítva a bemeneteket
}

bool operator>=(const Fraction& current, const Fraction& other)
{
	return !(current < other); // meghívja a < -t
}

// Converion Operators

Fraction::operator int() const
{
	return mNumerator / mDenomintator;
}

Fraction::operator double() const
{
	return static_cast<double>(mNumerator) / mDenomintator;
}

Fraction::operator bool() const
{
	return mNumerator != 0;
}

Fraction::operator std::string() const
{
	return ToString();
}

// IOStream Operators

std::ostream& operator<<(std::ostream& os, const Fraction& fragment)
{
	os << fragment.ToString();
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fragment)
{
	int num = 0, den = 1;
	char slash; 

	is >> num >> slash >> den;

	if (slash == '/') {		
		fragment = Fraction(num, den);
	}
	else {
		is.setstate(std::ios::failbit);
	}
	return is;
}

Fraction::Fraction(const std::string& str)
{
	std::stringstream ss(str);
	int num = 0;
	int den = 1;
	char slash;

	ss >> num;

	if (ss >> slash && slash == '/') {
		ss >> den;
	}
	*this = Fraction(num, den);
}
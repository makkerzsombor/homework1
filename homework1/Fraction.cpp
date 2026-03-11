#include "Fraction.h"
#include <cmath>
#include <sstream>
#include <stdexcept>

Fraction::Fraction(const int numerator, const int denominator)
{
	if (denominator == 0)
	{		
		throw std::invalid_argument("Hiba: A nevezo nem lehet nulla!");
	}
	if (denominator < 0) {
		mNumerator = -numerator;
		mDenomintator = -denominator;
	}
	else {
		mNumerator = numerator;
		mDenomintator = denominator;
	}

	int divider = DividedBy(mNumerator, mDenomintator);
	if (divider > 1)
	{
		DivideWithThis(divider);
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

Fraction& Fraction::operator+=(const Fraction& other)
{
	int newNumerator = (mNumerator * other.mDenomintator) + (other.mNumerator * mDenomintator);
	int newDenominator = mDenomintator * other.mDenomintator;
	*this = Fraction(newNumerator, newDenominator);
	return *this;
}

Fraction operator+(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result += other; // meghívja a += -t
}

Fraction& Fraction::operator-=( const Fraction& other)
{
	Fraction negativeOther(-other.mNumerator, other.mDenomintator);
	return *this += negativeOther;
}

Fraction operator-(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result -= other; // meghívja a -= -t
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	int newNumerator = mNumerator * other.mNumerator;
	int newDenominator = mDenomintator * other.mDenomintator;
	*this = Fraction(newNumerator, newDenominator);
	return *this;
}

Fraction operator*(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result *= other; // meghívja a *= -t
}

Fraction& Fraction::operator/=( const Fraction& other)
{
	Fraction reciprocalOther(other.mDenomintator, other.mNumerator);
	return *this *= reciprocalOther;
}

Fraction operator/(const Fraction& current, const Fraction& other)
{
	Fraction result = current;
	return result /= other; // meghívja a /= -t
}

bool Fraction::operator==(const Fraction& other) const
{
	// Mivel tagfüggvény, közvetlenül elérjük a saját és a másik privát tagjait is
	return (mNumerator == other.mNumerator && mDenomintator == other.mDenomintator);
}

bool Fraction::operator!=(const Fraction& other) const
{
	return !(*this == other); // Az aktuális objektumot (*this) hasonlítjuk a másikhoz
}

bool Fraction::operator<(const Fraction& other) const
{
	return (mNumerator * other.mDenomintator < mDenomintator * other.mNumerator);
}

bool Fraction::operator<=(const Fraction& other) const
{
	return !(*this > other);
}

bool Fraction::operator>(const Fraction& other) const
{
	return other < *this; // Megfordítjuk a relációt
}

bool Fraction::operator>=(const Fraction& other) const
{
	return !(*this < other);
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
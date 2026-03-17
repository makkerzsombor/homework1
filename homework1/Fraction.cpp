#include "Fraction.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <numeric>

Fraction::Fraction(const int numerator, const int denominator)
	: mNumerator(denominator < 0 ? -numerator : numerator),
	mDenominator(denominator < 0 ? -denominator : denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Hiba: A nevezo nem lehet nulla!");
	}
	int divider = std::gcd(mNumerator, mDenominator);
	if (divider > 1)
	{
		mNumerator /= divider;
		mDenominator /= divider;
	}
}

Fraction::Fraction(const int numerator)
	: Fraction{ numerator , 1} {
}

Fraction::Fraction(const double decimal)
	: Fraction{ static_cast<int>(std::round(decimal * 1000000.0)), 1000000 } {
}
// Operators 

Fraction& Fraction::operator+=(const Fraction& other)
{
	int newNumerator = (mNumerator * other.mDenominator) + (other.mNumerator * mDenominator);
	int newDenominator = mDenominator * other.mDenominator;
	*this = Fraction(newNumerator, newDenominator);
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this += -other;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	int newNumerator = mNumerator * other.mNumerator;
	int newDenominator = mDenominator * other.mDenominator;
	*this = Fraction(newNumerator, newDenominator);
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	Fraction reciprocalOther(other.mDenominator, other.mNumerator);
	return *this *= reciprocalOther;
}

Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction result = *this;
	return result += other;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction result = *this;
	return result -= other;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction result = *this;
	return result *= other;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction result = *this;
	return result /= other;
}

// Comparison Operators

bool Fraction::operator==(const Fraction& other) const
{
	return (mNumerator == other.mNumerator && mDenominator == other.mDenominator);
}

bool Fraction::operator!=(const Fraction& other) const
{
	return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const
{
	return (mNumerator * other.mDenominator < mDenominator * other.mNumerator);
}

bool Fraction::operator<=(const Fraction& other) const
{
	return !(*this > other);
}

bool Fraction::operator>(const Fraction& other) const
{
	return other < *this;
}

bool Fraction::operator>=(const Fraction& other) const
{
	return !(*this < other);
}
// Conversion Operators

Fraction::operator int() const
{
	return mNumerator / mDenominator;
}

Fraction::operator double() const
{
	return static_cast<double>(mNumerator) / mDenominator;
}

Fraction::operator bool() const
{
	return mNumerator != 0;
}

Fraction::operator std::string() const
{
	return std::to_string(mNumerator) + "/" + std::to_string(mDenominator);
}
Fraction Fraction::Parse(const std::string& str)
{
	std::stringstream ss(str);
	int num = 0;
	int den = 1;
	char slash;
	ss >> num;

	if (ss >> slash && slash == '/') {
		ss >> den;
	}
	if (den == 0) {
		throw std::invalid_argument("Hiba a parszolasnal: A nevezo nem lehet nulla!");
	}
	return Fraction(num, den);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fragment)
{
	os << static_cast<std::string>(fragment);
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

Fraction Fraction::operator-() const 
{
	return Fraction{ -mNumerator, mDenominator };
}
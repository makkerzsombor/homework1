#include "Fraction.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <numeric>

void Fraction::Simplify()
{
	if (mDenominator < 0) {
		mNumerator = -mNumerator;
		mDenominator = -mDenominator;
	}
	const int divider = std::gcd(mNumerator, mDenominator);
	if (divider > 1) {
		mNumerator /= divider;
		mDenominator /= divider;
	}
}

Fraction::Fraction(const int numerator, const int denominator)
	: mNumerator{ numerator }
	, mDenominator{ denominator }
{
	if (mDenominator == 0) {
		throw std::invalid_argument("Hiba: A nevezo nem lehet nulla!");
	}
	Simplify();
}

Fraction::Fraction(const int numerator)
	: Fraction{ numerator , 1 } {
}

Fraction::Fraction(const double decimal)
	: Fraction{ static_cast<int>(std::round(decimal * 1000000.0)), 1000000 } {
}

// Operators 

Fraction& Fraction::operator+=(const Fraction& other)
{
	mNumerator = (mNumerator * other.mDenominator) + (other.mNumerator * mDenominator);
	mDenominator *= other.mDenominator;
	Simplify();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this += -other;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	mNumerator *= other.mNumerator;
	mDenominator *= other.mDenominator;
	Simplify();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	const Fraction reciprocalOther{ other.mDenominator, other.mNumerator };
	return *this *= reciprocalOther;
}

Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction result{ *this };
	return result += other;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction result{ *this };
	return result -= other;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction result{ *this };
	return result *= other;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction result{ *this };
	return result /= other;
}

Fraction Fraction::operator-() const
{
	return Fraction{ -mNumerator, mDenominator };
}

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
	return static_cast<double>(*this) < static_cast<double>(other);
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
	std::ostringstream oss;
	oss << mNumerator << "/" << mDenominator;
	return oss.str();
}


std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	int num{ 0 };
	int den{ 1 };
	char slash;

	if ((is >> num) && (is.eof() || is.peek() != '/' || ((is >> slash >> den) && den != 0))) {
		fraction.mNumerator = num;
		fraction.mDenominator = den;
		fraction.Simplify();
	}
	else {
		is.setstate(std::ios::failbit);
	}
	return is;
}

Fraction Fraction::Parse(const std::string& str)
{
	std::istringstream iss{ str };
	Fraction result;

	if (!(iss >> result)) {
		throw std::invalid_argument(str + " was not suitable!");
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fragment)
{
	os << static_cast<std::string>(fragment);
	return os;
}

Fraction operator+(const int number, const Fraction& fraction)
{
	return fraction + number;
}

Fraction operator-(const int number, const Fraction& fraction)
{
	return -fraction + number;
}

Fraction operator*(const int number, const Fraction& fraction)
{
	return fraction * number;
}

Fraction operator/(const int number, const Fraction& fraction)
{
	return Fraction{ number } / fraction;
}
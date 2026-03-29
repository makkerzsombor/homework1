#include "Fraction.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <numeric>

Fraction::Fraction(const int numerator, const int denominator)
	: mNumerator{ numerator }
	, mDenominator{ denominator }
{
	if (mDenominator == 0) {
		throw std::invalid_argument("Hiba: A nevezo nem lehet nulla!");
	}
	Simplify(); // Rábízzuk a munkát!
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
	mNumerator = (mNumerator * other.mDenominator) + (other.mNumerator * mDenominator);
	mDenominator *= other.mDenominator;
	Simplify(); // Rábízzuk a munkát!
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
	Simplify(); // Rábízzuk a munkát!
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	const Fraction reciprocalOther(other.mDenominator, other.mNumerator);
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
	std::ostringstream oss;
	oss << mNumerator << "/" << mDenominator;
	return oss.str();
}

Fraction Fraction::Parse(const std::string& str)
{
	std::istringstream iss{ str };
	int num{ 0 };
	int den{ 1 };
	char slash;
	if (!(iss >> num) || (iss >> slash && (slash != '/' || !(iss >> den) || den == 0))) {
		throw std::invalid_argument(str + " was not suitable!");
	}
	return Fraction{ num, den };
}

std::ostream& operator<<(std::ostream& os, const Fraction& fragment)
{
	os << static_cast<std::string>(fragment);
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	int num{ 0 }, den{ 1 };
	char slash;

	// Ha mindent sikeresen beolvasott a stream, és a karakter tényleg '/'
	if (is >> num >> slash >> den && slash == '/') {
		if (den == 0) {
			is.setstate(std::ios::failbit);
		}
		else {
			// HELYBEN MÓDOSÍTUNK! Nincs új Fraction példány!
			fraction.mNumerator = num;
			fraction.mDenominator = den;
			fraction.Simplify();
		}
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
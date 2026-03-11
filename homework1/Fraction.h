#pragma once

#include <iostream>
#include <string>

class Fraction {
public:	
	Fraction(const int numerator, const int denominator); // constructor with two numbers	
	Fraction(const int numerator); // constructor with one number	
	Fraction(const double decimal); // constructor with decimal	
	Fraction(const Fraction& other); // constructor with fragment
	std::string ToString() const;
	int GetNumerator() const;
	int GetDenominator() const;
	// Conversion operators
	explicit operator int() const;
	explicit operator double() const;
	explicit operator bool() const;
	explicit operator std::string() const;
	// Parse constructor
	Fraction(const std::string& str);

	// Binary Arithmetic operators
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);


private:
	int mNumerator;
	int mDenomintator;

	int DividedBy(const int a, const int b);
	void DivideWithThis(const int a);
};

// Operators (szimmetria miatt maradnak)
Fraction operator+(const Fraction& current, const Fraction& other);
Fraction operator-(const Fraction& current, const Fraction& other);
Fraction operator*(const Fraction& current, const Fraction& other);
Fraction operator/(const Fraction& current, const Fraction& other);

// Comparison Operators

bool operator==(const Fraction& current, const Fraction& other);
bool operator!=(const Fraction& current, const Fraction& other);

bool operator<(const Fraction& current, const Fraction& other);
bool operator<=(const Fraction& current, const Fraction& other);
bool operator>(const Fraction& current, const Fraction& other);
bool operator>=(const Fraction& current, const Fraction& other);

// IOStream Operators

std::ostream& operator<<(std::ostream& os, const Fraction& fragment);
std::istream& operator>>(std::istream& is, Fraction& fragment);
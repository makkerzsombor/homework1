#pragma once

#include <iostream>
#include <string>

class Fraction {
public:
	// Constructors
	Fraction() = default;
	Fraction(const int numerator, const int denominator);
	Fraction(const int numerator);
	Fraction(const double decimal);

	// Converion Operators
	explicit operator int() const;
	explicit operator double() const;
	explicit operator bool() const;
	explicit operator std::string() const;	
	static Fraction Parse(const std::string& str);

	// Operators
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	// Inverse Operator
	Fraction operator-() const;

	// Binary Arithmetic Operators
	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;

	// Comparison Operators
	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;

	friend std::istream& operator>>(std::istream& is, Fraction& fraction);

private:
	int mNumerator{ 0 };
	int mDenominator{ 1 };

	void Simplify();
};

// IOStream Operators
std::ostream& operator<<(std::ostream& os, const Fraction& fragment);

Fraction operator+(const int number, const Fraction& fraction);
Fraction operator-(const int number, const Fraction& fraction);
Fraction operator*(const int number, const Fraction& fraction);
Fraction operator/(const int number, const Fraction& fraction);
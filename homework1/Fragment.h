#pragma once

#include <iostream>
#include <string>

class Fragment {
public:	
	Fragment(const int numerator, const int denominator); // constructor with two numbers	
	Fragment(const int numerator); // constructor with one number	
	Fragment(const double decimal); // constructor with decimal	
	Fragment(const Fragment& other); // constructor with fragment
	std::string ToString() const;
	int GetNumerator() const;
	int GetDenominator() const;
	~Fragment();

private:
	int mNumerator;
	int mDenomintator;

	int DividedBy(const int a, const int b);
	void DivideWithThis(const int a);
};

// Operators

Fragment& operator+=(Fragment& current, const Fragment& other);
Fragment operator+(const Fragment& current, const Fragment& other);

Fragment& operator-=(Fragment& current, const Fragment& other);
Fragment operator-(const Fragment& current, const Fragment& other);

Fragment& operator*=(Fragment& current, const Fragment& other);
Fragment operator*(const Fragment& current, const Fragment& other);

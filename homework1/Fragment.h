#pragma once

#include <iostream>
#include <string>

class Fragment {
public:
	// constructor with two numbers
	Fragment(const int numerator, const int denominator) {

		if (!denominator)
		{
			std::cout << "Nem lehet a nevezo nulla!" << std::endl;
		}
		else
		{
			mNumerator = numerator;
			mDenomintator = denominator;
		}
	}

	// constructor with one number
	Fragment(const int numerator)
	{
		mNumerator = numerator;
		mDenomintator = 1;
	}

	// constructor with decimal
	Fragment(const double decimal)
	{
		int precision = 1000000;
		mNumerator = decimal * precision;
		mDenomintator = precision;
		//std::cout << "At alakitva: " << getNumerator() << std::endl; // for testing
		double vissza = static_cast<double>(mNumerator) / precision;
		//std::cout << "a valodi erteke: " << vissza << std::endl; // for testing
	}

	// constructor with fragment
	Fragment(const Fragment& other)
	{
		mNumerator = other.mNumerator;
		mDenomintator = other.mDenomintator;
	}

	std::string ToString() const
	{
		std::string s = "A tort szamlaloja: ";
		s += std::to_string(mNumerator);
		s += ", nevezoje: ";
		s += std::to_string(mDenomintator);
		return s;
	}

	int GetNumerator() const
	{
		return mNumerator;
	}

	int GetDenominator() const
	{
		return mDenomintator;
	}

	~Fragment()
	{
		std::cout << "A tort megsemmisult!" << std::endl;
	}

private:
	int mNumerator;
	int mDenomintator;
};

#include "Fragment.h"

Fragment::Fragment(const int numerator, const int denominator) {
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

Fragment::Fragment(const int numerator)
{
	mNumerator = numerator;
	mDenomintator = 1;
}

Fragment::Fragment(const double decimal)
{
	int precision = 1000000;
	mNumerator = decimal * precision;
	mDenomintator = precision;
	//std::cout << "At alakitva: " << getNumerator() << std::endl; // for testing
	double vissza = static_cast<double>(mNumerator) / precision;
	//std::cout << "a valodi erteke: " << vissza << std::endl; // for testing
}

Fragment::Fragment(const Fragment& other)
{
	mNumerator = other.mNumerator;
	mDenomintator = other.mDenomintator;
}

std::string Fragment::ToString() const
{
	std::string s = "A tort szamlaloja: ";
	s += std::to_string(mNumerator);
	s += ", nevezoje: ";
	s += std::to_string(mDenomintator);
	return s;
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
	std::cout << "A tort megsemmisult!" << std::endl;
}

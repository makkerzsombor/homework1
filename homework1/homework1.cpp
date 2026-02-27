#include <iostream>
#include <string>

class Fragment {
public:
	// constructor with two numbers
	Fragment(const int numerator,const int denominator){

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

	std::string toString() const
	{
		std::string s = "A tort szamlaloja: ";
		s += std::to_string(mNumerator);
		s += ", nevezoje: ";
		s += std::to_string(mDenomintator);
		return s;
	}

	int getNumerator() const
	{
		return mNumerator;
	}

	int getDenominator() const
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

int main()
{   
	Fragment tort1 = Fragment(2, 3);
	std::cout << tort1.toString() << std::endl;
	std::cout << tort1.getNumerator() << " " << tort1.getDenominator() << std::endl;

	Fragment tort2 = Fragment(2, 0);
	std::cout << tort2.toString() << std::endl; // this needs to be fixed

	Fragment tort3 = Fragment(5);	
	std::cout << tort3.toString() << std::endl;


	Fragment tort4 = Fragment(1.25);
	std::cout << tort4.toString() << std::endl;

	std::cout << "tortbol tort" << std::endl;

	Fragment tort5 = Fragment(tort1);
	std::cout << tort5.toString() << std::endl;

}

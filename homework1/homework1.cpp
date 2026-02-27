#include <iostream>

class Fragment {
public:
	Fragment(const int numerator,const int denominator){

		if (!denominator)
		{
			std::cout << "Nem lehet a szamlalo nulla!" << std::endl;
		}
		else
		{
			mNumerator = numerator;
			mDenomintator = denominator;
		}		
	}

	void toString() 
	{
		std::cout << "A tort szamalaloja: " << mNumerator << ", nevezoje: " << mDenomintator << std::endl;
	}

	int getNumerator() 
	{
		return mNumerator;
	}

	int getDenominator() 
	{
		return mDenomintator;
	}

private:	
	int mNumerator;
	int mDenomintator;

};

int main()
{   
	/*int szamlalo;
	int nevezo;
	std::cout << "Adja meg a tort szamlalojat!";
	std::cin >> szamlalo;
	
	std::cout << "Adja meg a tort nevezojet!";
	std::cin >> nevezo;*/

	Fragment tort1 = Fragment(2, 3);
	tort1.toString();
	std::cout << tort1.getNumerator() << " " << tort1.getDenominator() << std::endl;

	Fragment tort2 = Fragment(2, 0);
	tort2.toString();
}

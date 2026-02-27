#include <iostream>

class Fragment {
public:
	Fragment(const int numerator,const int denominator){
		mNumerator = numerator;
		mDenomintator = denominator;
	}

	void toString() 
	{
		std::cout << "A tort szamalaloja: " << mNumerator << ", nevezoje: " << mDenomintator;
	}

private:	
	int mNumerator;
	int mDenomintator;

};

int main()
{   
	int szamlalo;
	int nevezo;
	std::cout << "Adja meg a tort szamlalojat!";
	std::cin >> szamlalo;
	
	std::cout << "Adja meg a tort nevezojet!";
	std::cin >> nevezo;

	Fragment tort1 = Fragment(szamlalo, nevezo);
	tort1.toString();

}

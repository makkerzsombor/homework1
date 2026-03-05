#include <iostream>
#include "Fragment.h"

int main()
{   
	/*Fragment tort1 = Fragment(2, 3);
	std::cout << tort1.ToString() << std::endl;
	std::cout << tort1.GetNumerator() << " " << tort1.GetDenominator() << std::endl;

	Fragment tort2 = Fragment(2, 0);
	std::cout << "Problematic: 2 and 0" << std::endl;
	std::cout << tort2.ToString() << std::endl;

	Fragment tort3 = Fragment(5);	
	std::cout << tort3.ToString() << std::endl;

	Fragment tort4 = Fragment(1.25);
	std::cout << tort4.ToString() << std::endl;

	std::cout << "tortbol tort" << std::endl;

	Fragment tort5 = Fragment(tort1);
	std::cout << tort5.ToString() << std::endl;

	Fragment tort6 = Fragment(2, 4);
	std::cout << "uj ertekek:" << tort6.ToString() << std::endl;

	Fragment tort7 = Fragment(4, 2);
	std::cout << "uj ertekek:" << tort7.ToString() << std::endl;

	Fragment tort8 = Fragment(5, 35);
	std::cout << "uj ertekek:" << tort8.ToString() << std::endl;

	Fragment tort9 = Fragment(6, 4);
	std::cout << "uj ertekek:" << tort9.ToString() << std::endl;

	Fragment tort10 = Fragment(0, 5);
	std::cout << "uj ertekek:" << tort10.ToString() << std::endl;

	Fragment tort11 = Fragment(-2, 4);
	std::cout << "uj ertekek:" << tort11.ToString() << std::endl;*/

	// Operator checks

	Fragment opTort1{ 1, 2 };
	Fragment opTort2{ 1, 3 };

	Fragment result1 = opTort1 + opTort2;
	Fragment result2 = opTort1 += opTort2;


	std::cout << "(+) result1: " << result1.ToString() << std::endl; // 5/6
	std::cout << "(+=) result2: " << result1.ToString() << std::endl; // 5/6

	Fragment opTort3{ 1, 2 };
	Fragment opTort4{ 1, 3 };

	Fragment result3 = opTort3 - opTort4;
	Fragment result4 = opTort3 -= opTort4;

	std::cout << "(-) result3: " << result3.ToString() << std::endl; // 1/6
	std::cout << "(-=) result4: " << result4.ToString() << std::endl; // 1/6
}

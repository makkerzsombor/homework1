#include <iostream>
#include "Fragment.h"

int main()
{   
	Fragment tort1 = Fragment(2, 3);
	std::cout << tort1.ToString() << std::endl;
	std::cout << tort1.GetNumerator() << " " << tort1.GetDenominator() << std::endl;

	Fragment tort2 = Fragment(2, 0);
	std::cout << tort2.ToString() << std::endl; // this needs to be fixed

	Fragment tort3 = Fragment(5);	
	std::cout << tort3.ToString() << std::endl;


	Fragment tort4 = Fragment(1.25);
	std::cout << tort4.ToString() << std::endl;

	std::cout << "tortbol tort" << std::endl;

	Fragment tort5 = Fragment(tort1);
	std::cout << tort5.ToString() << std::endl;
}

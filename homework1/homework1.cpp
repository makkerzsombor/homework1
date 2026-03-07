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

	//Fragment opTort1{ 1, 2 };
	//Fragment opTort2{ 1, 3 };

	//Fragment result1 = opTort1 + opTort2;
	//Fragment result2 = opTort1 += opTort2;

	//std::cout << "(+) result1: " << result1.ToString() << std::endl; // 5/6
	//std::cout << "(+=) result2: " << result1.ToString() << std::endl; // 5/6

	//Fragment opTort3{ 1, 2 };
	//Fragment opTort4{ 1, 3 };

	//Fragment result3 = opTort3 - opTort4;
	//Fragment result4 = opTort3 -= opTort4;

	//std::cout << "(-) result3: " << result3.ToString() << std::endl; // 1/6
	//std::cout << "(-=) result4: " << result4.ToString() << std::endl; // 1/6

	//Fragment opTort5{ 1, 2 };
	//Fragment opTort6{ 1, 3 };

	//Fragment result5 = opTort5 - opTort6;
	//Fragment result6 = opTort5 -= opTort6;

	//std::cout << "(*) result5: " << result5.ToString() << std::endl; // 1/6
	//std::cout << "(*=) result6: " << result6.ToString() << std::endl; // 1/6

	//Fragment opTort7{ 1, 2 };
	//Fragment opTort8{ 1, 3 };

	//Fragment result7 = opTort7 / opTort8;
	//Fragment result8 = opTort7 /= opTort8;

	//std::cout << "(/) result7: " << result7.ToString() << std::endl; // 3/2
	//std::cout << "(/=) result8: " << result8.ToString() << std::endl; // 3/2

	// Összehasonlítási operátorok

	//Fragment oOpTort1{ 1, 2 };
	//Fragment oOpTort2{ 2, 4 };
	//Fragment oOpTort3{ 2, 3 };
	//Fragment oOpTort4{ -1, 2 };

	//std::cout << "(==) 1/2 == 2/4: " << (oOpTort1 == oOpTort2) << std::endl; // 1 
	//std::cout << "(==) 1/2 == 2/3: " << (oOpTort1 == oOpTort3) << std::endl; // 0
	//std::cout << "(!=) 1/2 != 2/4: " << (oOpTort1 != oOpTort2) << std::endl; // 0
	//std::cout << "(!=) 1/2 != 2/3: " << (oOpTort1 != oOpTort3) << std::endl; // 1

	//std::cout << "(<)  1/2 < 2/3:  " << (oOpTort1 < oOpTort3) << std::endl;  // 1
	//std::cout << "(<)  2/3 < 1/2:  " << (oOpTort3 < oOpTort1) << std::endl;  // 0
	//std::cout << "(>)  2/3 > 1/2:  " << (oOpTort3 > oOpTort1) << std::endl;  // 1
	//std::cout << "(<) -1/2 < 1/2:  " << (oOpTort4 < oOpTort1) << std::endl;  // 1

	//std::cout << "(<=) 1/2 <= 2/4: " << (oOpTort1 <= oOpTort2) << std::endl; // 1
	//std::cout << "(<=) 1/2 <= 2/3: " << (oOpTort1 <= oOpTort3) << std::endl; // 1
	//std::cout << "(>=) 1/2 >= 2/4: " << (oOpTort1 >= oOpTort2) << std::endl; // 1
	//std::cout << "(>=) 1/2 >= -1/2:" << (oOpTort1 >= oOpTort4) << std::endl; // 1

	// Konverziós operátorok

	//Fragment konvTort(5, 2);

	//double dErtek = static_cast<double>(konvTort);
	//std::cout << "double (5/2): " << dErtek << std::endl; // 2.5

	//int iErtek = static_cast<int>(konvTort);
	//std::cout << "int (5/2): " << iErtek << std::endl; // 2

	//std::string sErtek = static_cast<std::string>(konvTort);
	//std::cout << "string: " << sErtek << std::endl; // 5/2

	//Fragment nullaTort(0, 5);	

	//bool bIgaz = static_cast<bool>(konvTort);
	//bool bHamis = static_cast<bool>(nullaTort);

	//std::cout << "bool (5/2): " << bIgaz << std::endl;  // 1
	//std::cout << "bool (0/5): " << bHamis << std::endl; // 0

	// IOStream operátorok

    Fragment kiirTort(10, 4); 
    std::cout << "Uj kiiras: " << kiirTort << std::endl;

    Fragment beolvasottTort(0); 
    
    std::cout << "\nKerlek, adj meg egy tortet (pl. 4/6 formaban): ";
    std::cin >> beolvasottTort;

    if (std::cin.fail()) {
        std::cout << "Hibas formatum!" << std::endl;
    } else {
        std::cout << "A beolvasott tort: " << beolvasottTort << std::endl;
    }


}

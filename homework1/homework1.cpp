#include <iostream>
#include "Fraction.h"

int main()
{   
	Fraction tort1 = Fraction(2, 3);
	std::cout << tort1.ToString() << std::endl;
	std::cout << tort1.GetNumerator() << " " << tort1.GetDenominator() << std::endl;

	Fraction tort2 = Fraction(2, 0);
	std::cout << "Problematic: 2 and 0" << std::endl;
	std::cout << tort2.ToString() << std::endl;

	Fraction tort3 = Fraction(5);
	std::cout << tort3.ToString() << std::endl;

	Fraction tort4 = Fraction(1.25);
	std::cout << tort4.ToString() << std::endl;

	std::cout << "tortbol tort" << std::endl;

	Fraction tort5 = Fraction(tort1);
	std::cout << tort5.ToString() << std::endl;

	Fraction tort6 = Fraction(2, 4);
	std::cout << "uj ertekek:" << tort6.ToString() << std::endl;

	Fraction tort7 = Fraction(4, 2);
	std::cout << "uj ertekek:" << tort7.ToString() << std::endl;

	Fraction tort8 = Fraction(5, 35);
	std::cout << "uj ertekek:" << tort8.ToString() << std::endl;

	Fraction tort9 = Fraction(6, 4);
	std::cout << "uj ertekek:" << tort9.ToString() << std::endl;

	Fraction tort10 = Fraction(0, 5);
	std::cout << "uj ertekek:" << tort10.ToString() << std::endl;

	Fraction tort11 = Fraction(-2, 4);
	std::cout << "uj ertekek:" << tort11.ToString() << std::endl;

	// Operator checks

	Fraction opTort1{ 1, 2 };
	Fraction opTort2{ 1, 3 };

	Fraction result1 = opTort1 + opTort2;
	Fraction result2 = opTort1 += opTort2;

	std::cout << "(+) result1: " << result1.ToString() << std::endl; // 5/6
	std::cout << "(+=) result2: " << result1.ToString() << std::endl; // 5/6

	Fraction opTort3{ 1, 2 };
	Fraction opTort4{ 1, 3 };

	Fraction result3 = opTort3 - opTort4;
	Fraction result4 = opTort3 -= opTort4;

	std::cout << "(-) result3: " << result3.ToString() << std::endl; // 1/6
	std::cout << "(-=) result4: " << result4.ToString() << std::endl; // 1/6

	Fraction opTort5{ 1, 2 };
	Fraction opTort6{ 1, 3 };

	Fraction result5 = opTort5 - opTort6;
	Fraction result6 = opTort5 -= opTort6;

	std::cout << "(*) result5: " << result5.ToString() << std::endl; // 1/6
	std::cout << "(*=) result6: " << result6.ToString() << std::endl; // 1/6

	Fraction opTort7{ 1, 2 };
	Fraction opTort8{ 1, 3 };

	Fraction result7 = opTort7 / opTort8;
	Fraction result8 = opTort7 /= opTort8;

	std::cout << "(/) result7: " << result7.ToString() << std::endl; // 3/2
	std::cout << "(/=) result8: " << result8.ToString() << std::endl; // 3/2

	// Összehasonlítási operátorok

	Fraction oOpTort1{ 1, 2 };
	Fraction oOpTort2{ 2, 4 };
	Fraction oOpTort3{ 2, 3 };
	Fraction oOpTort4{ -1, 2 };

	std::cout << "(==) 1/2 == 2/4: " << (oOpTort1 == oOpTort2) << std::endl; // 1 
	std::cout << "(==) 1/2 == 2/3: " << (oOpTort1 == oOpTort3) << std::endl; // 0
	std::cout << "(!=) 1/2 != 2/4: " << (oOpTort1 != oOpTort2) << std::endl; // 0
	std::cout << "(!=) 1/2 != 2/3: " << (oOpTort1 != oOpTort3) << std::endl; // 1

	std::cout << "(<)  1/2 < 2/3:  " << (oOpTort1 < oOpTort3) << std::endl;  // 1
	std::cout << "(<)  2/3 < 1/2:  " << (oOpTort3 < oOpTort1) << std::endl;  // 0
	std::cout << "(>)  2/3 > 1/2:  " << (oOpTort3 > oOpTort1) << std::endl;  // 1
	std::cout << "(<) -1/2 < 1/2:  " << (oOpTort4 < oOpTort1) << std::endl;  // 1

	std::cout << "(<=) 1/2 <= 2/4: " << (oOpTort1 <= oOpTort2) << std::endl; // 1
	std::cout << "(<=) 1/2 <= 2/3: " << (oOpTort1 <= oOpTort3) << std::endl; // 1
	std::cout << "(>=) 1/2 >= 2/4: " << (oOpTort1 >= oOpTort2) << std::endl; // 1
	std::cout << "(>=) 1/2 >= -1/2:" << (oOpTort1 >= oOpTort4) << std::endl; // 1

	// Konverziós operátorok

	Fraction konvTort(5, 2);

	double dErtek = static_cast<double>(konvTort);
	std::cout << "double (5/2): " << dErtek << std::endl; // 2.5

	int iErtek = static_cast<int>(konvTort);
	std::cout << "int (5/2): " << iErtek << std::endl; // 2

	std::string sErtek = static_cast<std::string>(konvTort);
	std::cout << "string: " << sErtek << std::endl; // 5/2

	Fraction nullaTort(0, 5);

	bool bIgaz = static_cast<bool>(konvTort);
	bool bHamis = static_cast<bool>(nullaTort);

	std::cout << "bool (5/2): " << bIgaz << std::endl;  // 1
	std::cout << "bool (0/5): " << bHamis << std::endl; // 0

	// IOStream operátorok

	Fraction kiirTort(10, 4);
    std::cout << "Uj kiiras: " << kiirTort << std::endl;

	Fraction beolvasottTort(0);
    
    std::cout << "\nKerlek, adj meg egy tortet (pl. 4/6 formaban): ";
    std::cin >> beolvasottTort;

    if (std::cin.fail()) {
        std::cout << "Hibas formatum!" << std::endl;
    } else {
        std::cout << "A beolvasott tort: " << beolvasottTort << std::endl;
    }

	// Parse constructor
	
	Fraction strTort1("6/8");
	std::cout << "A '6/8' sztringbol tort: " << strTort1 << std::endl; // 3/4

	Fraction strTort2("5/-2");
	std::cout << "Az '5/-2' sztringbol tort: " << strTort2 << std::endl; // -5/2

	Fraction strTort3("42");
	std::cout << "A '42' sztringbol tort: " << strTort3 << std::endl; // 42/1

	Fraction strTort4("7/0");
	std::cout << "A '7/0' sztringbol (hiba utan): " << strTort4 << std::endl; // 0/1
}

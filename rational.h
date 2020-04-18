#pragma once
#include <vector>
#include "__BigNatural.h"
#include "BigInteger.h"
#include <iostream>
using namespace std;

class Rational
{


private :
	int natural;
	int zeloe;


public:

	//Конструктор на вход целое и натуральное
	Rational(int zeloe = 0, int natural = 1)
	{
		this->natural = natural;
		this->zeloe = zeloe;
	}


public:

	// Cокращение дроби
	vector<int> Reduction(int zeloe, int natural)
	{
		vector<int> result;
		int ostatok = zeloe % natural;
		int zelay_chast = zeloe / natural;

		if (ostatok == 0)
		{
			result.push_back(zelay_chast);
			result.push_back(0);
			result.push_back(0);
		}

		else
		{
			result.push_back(zelay_chast);
			result.push_back(ostatok);
			result.push_back(natural);
		}

		return result;
	}

	// Проверка на целое
	void CheckOnWhole(int zeloe, int natural)
	{
		if (Reduction(zeloe, natural).at(1) == 0)
		{
			cout << "Да" << endl;
		}

		else
		{
			cout << "Нет" << endl;
		}
	}

	//Преобразование целого в дробное 
	vector<int> ConvertionWholeToRational (int zeloe)
	{
		vector<int> result; 
		result.push_back(0);
		result.push_back(zeloe);
		result.push_back(1);

	}

	//Преобразование дробного в  целое 
	int ConvertionRationalToWhole(int zeloe, int natural)
	{
		if (natural == 1)
		{
			return zeloe;
		}
		else
		{
			cout << "Ошибка, знаменатель не 1" << endl;
			return;
		}
	}

	//Сложение дробей
	vector<int> Addition(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * natural2 + natural1 * zeloe2);
		result.push_back(natural1 * natural2);

		return result;
	}

	//Вычитание дробей
	vector<int> Subtraction(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * natural2 - natural1 * zeloe2);
		result.push_back(natural1 * natural2);

		return result;
	}

	//Умножение дробей
	vector<int> Multiplication(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * zeloe2);
		result.push_back(natural1 * natural2);

		return result;
	}


	//Деление дробей
	vector<int> Division(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * natural2);
		result.push_back(natural1 * zeloe2);

		if (result.at(2) == 0)
		{
			cout << "Деление на 0 запрещено" << endl;
			return;
		}
		else
		{
			return result;
		}
	}
};
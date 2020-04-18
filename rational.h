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

	//����������� �� ���� ����� � �����������
	Rational(int zeloe = 0, int natural = 1)
	{
		this->natural = natural;
		this->zeloe = zeloe;
	}


public:

	// C��������� �����
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

	// �������� �� �����
	void CheckOnWhole(int zeloe, int natural)
	{
		if (Reduction(zeloe, natural).at(1) == 0)
		{
			cout << "��" << endl;
		}

		else
		{
			cout << "���" << endl;
		}
	}

	//�������������� ������ � ������� 
	vector<int> ConvertionWholeToRational (int zeloe)
	{
		vector<int> result; 
		result.push_back(0);
		result.push_back(zeloe);
		result.push_back(1);

	}

	//�������������� �������� �  ����� 
	int ConvertionRationalToWhole(int zeloe, int natural)
	{
		if (natural == 1)
		{
			return zeloe;
		}
		else
		{
			cout << "������, ����������� �� 1" << endl;
			return;
		}
	}

	//�������� ������
	vector<int> Addition(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * natural2 + natural1 * zeloe2);
		result.push_back(natural1 * natural2);

		return result;
	}

	//��������� ������
	vector<int> Subtraction(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * natural2 - natural1 * zeloe2);
		result.push_back(natural1 * natural2);

		return result;
	}

	//��������� ������
	vector<int> Multiplication(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * zeloe2);
		result.push_back(natural1 * natural2);

		return result;
	}


	//������� ������
	vector<int> Division(int zeloe1, int natural1, int zeloe2, int natural2)
	{
		vector<int> result;
		result.push_back(0);
		result.push_back(zeloe1 * natural2);
		result.push_back(natural1 * zeloe2);

		if (result.at(2) == 0)
		{
			cout << "������� �� 0 ���������" << endl;
			return;
		}
		else
		{
			return result;
		}
	}
};
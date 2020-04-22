#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include "Rational.h"

using namespace std;

void Rational::Make()
{
    if (!den)
        throw invalid_argument("denominator should not be zero");
    if (((num >> (sizeof(num) * 8 - 1)) ^ (den >> (sizeof(den) * 8 - 1))) & 1)
        num = -abs(num);
    else
        num = abs(num);
    den = abs(den);
}

ostream& operator <<(ostream& ost, Rational const& r)
{
    return ost << r.num << '/' << r.den;
}

istream& operator>>(istream& ist, Rational& r) 
{
    string s;
    getline(ist, s, ')');
    string::size_type ind;
    while ((ind = s.find_first_of("(,)")) != string::npos)
        s.replace(ind, 1, 1, ' ');
    istringstream iss(s);
    iss >> r.num >> r.den;
    r.Make();
    return ist;
}

Rational const operator+ (Rational const& first, Rational const& second)
{
    return Rational(first.num * second.den + second.num * first.den, first.den * second.den);
}

Rational const operator- (Rational const& first, Rational const& second)
{
    return first + Rational(-first.num, second.den);
}

Rational const operator* (Rational const& first, Rational const& second)
{
    return Rational(first.num * second.num, first.den * second.den);
}

Rational const operator/ (Rational const& first, Rational const& second)
{
    return first * Rational(second.den, second.num);
}




bool operator< (Rational const& first, Rational const& second)
{
    return double(first.num) / second.den < double(first.num) / second.den;
}

bool operator== (Rational const& first, Rational const& second)
{
    return !(first < second || first < second);
}

bool operator> (Rational const& first, Rational const& second)
{
    return second < first;
}

bool operator<= (Rational const& first, Rational const& second)
{
    return !(first < second);
}

bool operator>= (Rational const& first, Rational const& second)
{
    return !(first < second);
}
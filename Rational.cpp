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
        throw runtime_error("ERROR : denominator should not be zero");
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




Rational& operator +=( Rational& first, const  Rational  &second)
{
    Rational &r = first;
    r.num = first.num * second.den + first.den * second.num;
    r.den = first.den * second.den;
    first.num = r.num;
    first.den = r.den;
    delete &r;
    return first;
}
Rational& operator -=(Rational&  first, Rational  const &second)
{
    Rational& r = first;
    r.num = first.num * second.den - first.den * second.num;
    r.den = first.den * second.den;
    first.num = r.num;
    first.den = r.den;
    delete& r;
    return first;
}
Rational& operator *=(Rational& first, Rational const &second)
{
    Rational& r = first;
    r.num = first.num * second.num;
    r.den = first.den * second.den;
    first.num = r.num;
    first.den = r.den;
    delete& r;
    return first;
}

Rational& operator /=(Rational& first, Rational const &second)
{
    
    if (second.num == 0)
    {
        throw runtime_error("ERROR: div by null");
    }
    Rational& r = first;
    r.num = first.num * second.den;
    r.den = first.den * second.num;
    first.num = r.num;
    first.den = r.den;
    delete& r;
    return first;
}


Rational& operator+(Rational& first, Rational& second)
{
    return first += second;
}

 Rational&  operator- (Rational&  first, Rational&  second)
{
    return first -= second;
}

Rational& const operator* (Rational& first, Rational&  second)
{
    return first *= second;
}

Rational& const operator/ (Rational&  first, Rational&  second)
{
    return first /=second;
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
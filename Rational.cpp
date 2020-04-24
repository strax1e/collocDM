#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include "Rational.h"
#include "standart_functions.h"

using namespace std;

void Rational::Make()
{
    if (!den)
        throw runtime_error("ERROR : denominator should not be zero");
    //if ((((long long)num >> (sizeof(num) * 8 - 1)) ^ (den >> (sizeof(den) * 8 - 1))) & 1)
    //    num = ABS_Z_N(num) * -1;
   // else
   //     num = ABS_Z_N(num);
   // den = ABS_Z_N(den);
}

ostream& operator <<(ostream& ost, Rational const& r)
{
    return ost << r.num << '/' << r.den;
}

/*
istream& operator>>(istream& ist, Rational& r) 
{
    string s;
    getline(ist, s, ')');
    string::size_type ind;
    while ((ind = s.find_first_of("(,)")) != string::npos)
        s.replace(ind, 1, 1, ' ');
    istringstream iss(s);
    iss >>  r.num >> r.den;
    r.Make();
    return ist;
}
*/




Rational& operator +=( Rational& first,  const Rational  &second)
{
    
    first.num = first.num * (BigInteger)second.den + (BigInteger)first.den * second.num;
    first.den = first.den * second.den;
    return first;
}
Rational& operator -=(Rational&  first, Rational  const &second)
{
    first.num = first.num * (BigInteger)second.den - (BigInteger)first.den * second.num;
    first.den = first.den * second.den;
    return first;
}
Rational& operator *=(Rational& first, Rational const &second)
{
    first.num = first.num * second.num;
    first.den = first.den * second.den;
    return first;
}

Rational& operator /=(Rational& first, Rational const &second)
{
    
    if (second.num == 0)
    {
        throw runtime_error("ERROR: div by null");
    }
    first.num = first.num * (BigInteger)second.den;
    first.den = (BigInteger)first.den * second.num;
    return first;
}


const Rational operator+(Rational first, Rational const& second)
{
    return first += second;
}

 const Rational  operator- (Rational  first, Rational const& second)
{
    return first -= second;
}

const Rational  operator* (Rational first, Rational const& second)
{
    return first *= second;
}

const Rational operator/ (Rational  first, Rational const& second)
{
    return first /=second;
}




bool operator< (Rational const& first, Rational const& second)
{
    return double(first.num / (BigInteger)second.den )< double(first.num / (BigInteger)second.den);
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
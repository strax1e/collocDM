#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include "Rational.h"
#include "BigInteger.h"
#include "BigNatural.h"
#include "standart_functions.h"
#include "standart_rational_functions.h"

using namespace std;

void Rational::Make()
{
    if (!den)
        throw runtime_error("ERROR : denominator should not be zero");
    
}

ostream& operator <<(ostream& ost, Rational const& r)
{
    return ost << r.num << '/' << r.den;
}






Rational& operator +=( Rational& first,  const Rational  &second)
{
    
    first.num = first.num * (BigInteger)second.den + (BigInteger)first.den * second.num;
    first.den = first.den * second.den;
    return RED_Q_Q(first);
}
Rational& operator -=(Rational&  first, Rational  const &second)
{
    first.num = first.num * (BigInteger)second.den - (BigInteger)first.den * second.num;
    first.den = first.den * second.den;
    return RED_Q_Q(first);
}
Rational& operator *=(Rational& first, Rational const &second)
{
    first.num = first.num * second.num;
    first.den = first.den * second.den;
    return RED_Q_Q(first);
}

Rational& operator /=(Rational& first, Rational const &second)
{
    
    if (second.num == 0)
    {
        throw runtime_error("ERROR: div by null");
    }
    first.num = first.num * (BigInteger)second.den;
    first.den = first.den * ABS_Z_N(second.num);
    return RED_Q_Q(first);
}


const Rational operator+(Rational first, Rational const& second)
{
    return RED_Q_Q(first += second);
}

 const Rational  operator- (Rational  first, Rational const& second)
{
    return RED_Q_Q(first -= second);
}

const Rational  operator* (Rational first, Rational const& second)
{
    return RED_Q_Q(first *= second);
}

const Rational operator/ (Rational  first, Rational const& second)
{
    return RED_Q_Q(first /=second);
}




bool operator< (Rational const& first, Rational const& second)
{
    return (first - second).num < 0 ? true : false;
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
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>

#include "../standart_functions.h"

using namespace std;

void Rational::Make()
{
  if (!den)
    throw runtime_error("ERROR : denominator should not be zero");   
}

const BigInteger Rational::GetNum( void )
{
  return num;
}

const BigNatural Rational::GetDen( void )
{
  return den;
}

void Rational::Reduct( void )
{
  bool flag = false;
  Rational new_r = *this;
  if (new_r.num < 0)
    flag = true;
  BigNatural new_r_num = ABS_Z_N(new_r.num), gcd = GCD(new_r_num, new_r.den);
  new_r.num = new_r_num / gcd;
  if (flag)
    new_r.num *= -1;
  new_r.den /= gcd;
  *this = new_r;
}

ostream& operator <<(ostream& ost, Rational const& r)
{
  if (r.den != 1)
    ost << r.num << '/' << r.den;
  else
    ost << r.num;
  return ost;
}

Rational& operator +=( Rational& first,  const Rational  &second)
{    
  first.num = first.num * (BigInteger)second.den + (BigInteger)first.den * second.num;
  first.den = first.den * second.den;
  first.Reduct();
  return first;
}
Rational& operator -=(Rational&  first, Rational  const &second)
{
  first.num = first.num * (BigInteger)second.den - (BigInteger)first.den * second.num;
  first.den = first.den * second.den;
  first.Reduct();
  return first;
}
Rational& operator *=(Rational& first, Rational const &second)
{
  first.num = first.num * second.num;
  first.den = first.den * second.den;
  first.Reduct();
  return first;
}

Rational& operator /=(Rational& first, Rational const &second)
{
  int sign = 1;

  if (second.num == 0)
    throw runtime_error("ERROR: div by null");
  if (second.num.isNegative())
    sign = -1;
  first.num = first.num * (BigInteger)second.den * sign;
  first.den = first.den * ABS_Z_N(second.num);
  first.Reduct();
  return first;
}

const Rational operator+(Rational first, Rational const& second)
{
  return first += second;
}

 const Rational operator-(Rational  first, Rational const& second)
{
  return first -= second;
}

const Rational operator*(Rational first, Rational const& second)
{
  return first *= second;
}

const Rational operator/(Rational  first, Rational const& second)
{
  return first /= second;
}

bool operator<(Rational const& first, Rational const& second)
{
  return (first - second).num < 0 ? true : false;
}

bool operator==(Rational const& first, Rational const& second)
{
  return !(first < second || first > second);
}

bool operator>(Rational const& first, Rational const& second)
{
  return second < first;
}

bool operator<=(Rational const& first, Rational const& second)
{
  return !(first > second);
}

bool operator>=(Rational const& first, Rational const& second)
{
  return !(first < second);
}
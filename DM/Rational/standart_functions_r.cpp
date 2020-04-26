#include "../standart_functions.h"

Rational RED_Q_Q(const Rational &r)
{
  bool flag = false;
  Rational new_r = r;
  if (new_r.num < 0)
    flag = true;
  BigNatural new_r_num = ABS_Z_N(new_r.num), gcd = GCD(new_r_num, new_r.den);
  new_r.num = new_r_num / gcd;
  if (flag)
    new_r.num *= -1;
  new_r.den /= gcd;
  return new_r;
}

bool INT_Q_B(const Rational& r)
{
  return RED_Q_Q(r).GetDen() == 1;
}

Rational TRANS_Z_Q(BigInteger i)
{
  return Rational(i, 1);
}

BigInteger TRANS_Q_Z(Rational r)
{
  if (r.den == 1)
    return r.num;
  throw std::runtime_error("Impossible to convert");
}

Rational ADD_QQ_Q(Rational first, Rational const& second)
{
  return RED_Q_Q(first + second);
}

Rational SUB_QQ_Q(Rational first, Rational const& second)
{
  return RED_Q_Q(first - second);
}

Rational MUL_QQ_Q(Rational first, Rational const& second)
{
  return RED_Q_Q(first * second);
}

Rational DIV_QQ_Q(Rational first, Rational const& second)
{
  return RED_Q_Q(first / second);
}
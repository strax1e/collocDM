#include "standart_functions.h"

Polynom ADD_PP_P(Polynom left, const Polynom &right)
{
  return left += right;
}

Polynom SUB_PP_P(Polynom left, const Polynom &right)
{
  return left -= right;
}

Polynom MUL_PQ_P(Polynom left, const Rational &right)
{
  return left *= right;
}

Polynom MUL_Pxk_P(Polynom left, int k)
{
  return MulByMono(left, k);
}

Rational LED_P_Q(const Polynom &p)
{
  return p.LeadCoef();
}
BigNatural DEG_P_N(const Polynom &p)
{
  return p.GetDegree();
}
Rational FAC_P_Q(const Polynom &p)
{
  return FAC(p);
}
Polynom MUL_PP_P(Polynom left, const Polynom &right)
{
  return left *= right;
}
Polynom DIV_PP_P(Polynom left, const Polynom &right)
{
  return left /= right;
}
Polynom MOD_PP_P(Polynom left, const Polynom &right)
{
  return left %= right;
}
Polynom GCF_PP_P(const Polynom &left, const Polynom &right)
{
  return GCD(left, right);
}
Polynom DER_P_P(const Polynom &p)
{
  return DER(p);
}
Polynom NMR_P_P(const Polynom &p)
{
  return NMR(p);
}
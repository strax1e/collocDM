#include "../standart_functions.h"

int COM_NN_D(const BigNatural &left, const BigNatural &right)
{
  if (left > right)
    return 2;
  else if (left == right)
    return 0;
  return 1;
}

bool NZER_N_B(const BigNatural &x)
{
  return x == 0;
}

BigNatural ADD_1N_N(BigNatural x)
{
  return ++x;
}
BigNatural ADD_NN_N(BigNatural left, const BigNatural &right)
{
  return left += right;
}
BigNatural SUB_NN_N(BigNatural left, const BigNatural &right)
{
  return left -= right;
}
BigNatural MUL_ND_N(BigNatural left, int digit)
{
  return left *= digit;
}
BigNatural MUL_Nk_N(BigNatural left, long long k)
{
  return left.pow10(k);
}
BigNatural MUL_NN_N(BigNatural left, const BigNatural &right)
{
  return left *= right;
}
BigNatural SUB_NDN_N(BigNatural left, int digit, BigNatural right)
{
  right = MUL_ND_N(right, digit);
  return left > right ? left - right : right - left;
}
BigNatural DIV_NN_Dk(BigNatural left, const BigNatural &right)
{
  left /= right;
  BigNatural k = 0;
  int kInt = 0;
  while (left != 0)
  {
    k = left % 10;
    left /= 10;
  }
  while (k != kInt)
    ++kInt;
  return MUL_Nk_N(k, kInt);
}
BigNatural DIV_NN_N(BigNatural left, const BigNatural &right)
{
  return left /= right;
}
BigNatural MOD_NN_N(BigNatural left, const BigNatural &right)
{
  return left %= right;
}
BigNatural GCF_NN_N(const BigNatural &left, const BigNatural &right)
{
  return GCD(left, right);
}
BigNatural LCM_NN_N(const BigNatural &left, const BigNatural &right)
{
  return LCM(left, right);
}

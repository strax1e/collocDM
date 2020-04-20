#include "standart_functions.h"
#include "BigInteger.h"

template < typename T >
BigNatural ABS_Z_N(T&& x)
{
    return ((std::forward<T>(x)).getNatural());
}

template < typename T >
BigInteger TRANS_N_Z(T&& x)
{
    return BigInteger(std::forward<T>(x));
}

template < typename T >
BigNatural TRANS_Z_N(T&& x)
{
    if (x < BigNatural(0))
        throw std::runtime_error("ERROR: invalid transformation from integer to natural");

    return ((std::forward<T>(x)).getNatural());
}

int POZ_Z_D(const BigInteger& x)
{
    if (x == BigInteger(0))
        return 0;

    if (x.isNegative())
        return 1;

    return 2;
}

void MUL_ZM_Z(BigInteger& x)
{
    x *= -1;
}

BigInteger ADD_ZZ_Z(const BigInteger& left, const BigInteger& right)
{
    return left + right;
}
BigInteger SUB_ZZ_Z(const BigInteger& left, const BigInteger& right)
{
    return left - right;
}
BigInteger MUL_ZZ_Z(const BigInteger& left, const BigInteger& right)
{
    return left * right;
}
BigInteger DIV_ZZ_Z(const BigInteger& left, const BigInteger& right)
{
    if (left <= BigInteger(0) || right <= BigInteger(0))
        throw std::runtime_error("ERROR: div with not natural numbers");

    return left / right;
}
BigInteger MOD_ZZ_Z(const BigInteger& left, const BigInteger& right)
{
    if (left <= BigInteger(0) || right <= BigInteger(0))
        throw std::runtime_error("ERROR: div with not natural numbers");

    return left % right;
}

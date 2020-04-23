#include "BigInteger.h"

const BigInteger operator +(BigInteger left, const BigInteger& right)
{
    left += right;
    return left;
}

const BigInteger operator -(BigInteger left, const BigInteger& right)
{
    left -= right;
    return left;
}

const BigInteger operator *(BigInteger left, const BigInteger& right)
{
    left *= right;
    return left;
}

const BigInteger operator /(BigInteger left, const BigInteger& right)
{
    left /= right;
    return left;
}

const BigInteger operator %(BigInteger left, const BigInteger& right)
{
    left %= right;
    return left;
}

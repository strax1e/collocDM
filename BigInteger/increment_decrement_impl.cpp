#include "BigInteger.h"

BigInteger& BigInteger::operator ++()
{
    if (isPositive)
        number++;
    else
        number--;

    if (number == 0)
        isPositive = true;

    return *this;
}

BigInteger BigInteger::operator ++(int)
{
    BigInteger copy(*this);
    if (isPositive)
        number++;
    else
        number--;

    if (number == 0)
        isPositive = true;

    return copy;
}

BigInteger& BigInteger::operator --()
{
    if (isPositive)
        number--;
    else
        number++;

    if (number < 0)
        isPositive = false;

    return *this;
}

BigInteger BigInteger::operator --(int)
{
    BigInteger copy(*this);
    if (isPositive)
        number--;
    else
        number++;

    if (number < 0)
        isPositive = false;

    return copy;
}

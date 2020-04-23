#include "BigInteger.h"

BigInteger& BigInteger::operator ++()
{
    if (isPositive)
        number++;
    else
        number--;

    // maybe need to realise comparison with int(0)
    if (number == BigNatural(0))
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

    // maybe need to realise comparison with int(0)
    if (number == BigNatural(0))
        isPositive = true;

    return copy;
}

BigInteger& BigInteger::operator --()
{
    // maybe need to realise comparison with int(0)
    if (!isPositive || number == BigNatural(0))
    {
        number++;
        isPositive = false;
    }
    else
        number--;

    return *this;
}

BigInteger BigInteger::operator --(int)
{
    BigInteger copy(*this);

    // maybe need to realise comparison with int(0)
    if (!isPositive || number == BigNatural(0))
    {
        number++;
        isPositive = false;
    }
    else
        number--;

    return copy;
}

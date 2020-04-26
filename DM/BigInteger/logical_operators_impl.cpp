#include "BigInteger.h"

bool BigInteger::operator ==(const BigInteger& other) const
{
    if (isPositive != other.isPositive)
        return false;

    return number == other.number;
}

bool BigInteger::operator !=(const BigInteger& other) const
{
    return !(*this == other);
}

bool BigInteger::operator > (const BigInteger& other) const
{
    return other < *this;
}

bool BigInteger::operator < (const BigInteger& other) const
{
    if (isPositive == other.isPositive)
    {
        if (isPositive == true)
            return number < other.number;
        else
            return number > other.number;
    }
    else
        return isPositive == false;
}

bool BigInteger::operator >=(const BigInteger& other) const
{
    return *this > other | *this == other;
}

bool BigInteger::operator <=(const BigInteger& other) const
{
    return *this < other | *this == other;
}

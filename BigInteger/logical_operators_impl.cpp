#include "BigInteger.h"

bool BigInteger::operator ==(const BigInteger& other) const
{
    return number == other.number;
}

bool BigInteger::operator !=(const BigInteger& other) const
{
    return number != other.number;
}

bool BigInteger::operator > (const BigInteger& other) const
{
    return number > other.number;
}

bool BigInteger::operator < (const BigInteger& other) const
{
    return number < other.number;
}

bool BigInteger::operator >=(const BigInteger& other) const
{
    return number >= other.number;
}

bool BigInteger::operator <=(const BigInteger& other) const
{
    return number <= other.number;
}

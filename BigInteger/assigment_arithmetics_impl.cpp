#include <exception>
#include <stdexcept>
#include "BigInteger.h"

BigInteger& BigInteger::operator +=(const BigInteger& other)
{
    if (isPositive == other.isPositive)
        number += other.number;
    else
    {
        if (number >= other.number)
            number -= other.number;
        else
        {
            isPositive = !isPositive;
            BigNatural n(std::move(number));
            number = other.number;
            number -= n;
        }
    }
    return *this;
}

BigInteger& BigInteger::operator -=(const BigInteger& other)
{
    if (isPositive != other.isPositive)
        number += other.number;
    else
    {
        if (number >= other.number)
            number -= other.number;
        else
        {
            isPositive = !isPositive;
            BigNatural n(std::move(number));
            number = other.number;
            number -= n;
        }
    }
    return *this;
}

BigInteger& BigInteger::operator *=(const BigInteger& other)
{
    isPositive = isPositive == other.isPositive ? true : false;
    number *= other.number;
    return *this;
}

BigInteger& BigInteger::operator *=(int num) // -9 <= num <= 9
{
    if (std::abs(num) % 10 != 0)
        throw std::runtime_error("ERROR: multiplying by num(abs(num) > 10)");

    isPositive = num >= 0;
    number *= std::abs(num);
    return *this;
}

BigInteger& BigInteger::operator /=(const BigInteger& other)
{
    // maybe need to realise comparison with int(0)
    if (other.number == BigNatural(0))
        throw std::runtime_error("Error: div by null");

    number /= other.number;
    if (!isPositive)
        number++;

    if (!other.isPositive)
        isPositive = !isPositive;

    return *this;
}

BigInteger& BigInteger::BigInteger::operator %=(const BigInteger& other)
{
    // maybe need to realise comparison with int(0)
    if (other.number == BigNatural(0))
        throw std::runtime_error("Error: div by null");

    number %= other.number;
    if (!isPositive)
    {
        number = other.number - number;
        isPositive = true;
    }
    return *this;
}

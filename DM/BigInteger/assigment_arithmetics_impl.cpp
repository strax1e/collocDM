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

    if (number == BigNatural(0))
        isPositive = true;

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

    if (number == BigNatural(0))
        isPositive = true;

    return *this;
}

BigInteger& BigInteger::operator *=(const BigInteger& other)
{
    isPositive = isPositive == other.isPositive ? true : false;
    number *= other.number;

    if (number == BigNatural(0))
        isPositive = true;

    return *this;
}

BigInteger& BigInteger::operator *=(int num) // -9 <= num <= 9
{
    if (std::abs(num) / 10 != 0)
        throw std::runtime_error("Multiplying by digit(abs(num) > 10)");

    isPositive = num >= 0;
    number *= std::abs(num);

    if (number == BigNatural(0))
        isPositive = true;

    return *this;
}

BigInteger& BigInteger::operator /=(const BigInteger& other)
{
    // maybe need to realise comparison with int(0)
    if (other.number == BigNatural(0))
        throw std::runtime_error("Division by zero");

    bool isIntegerMod = number % other.number == BigNatural(0);
    number /= other.number;
    if (!isIntegerMod)
        if (!isPositive)
            number++;

    if (!other.isPositive)
        isPositive = !isPositive;

    if (number == BigNatural(0))
        isPositive = true;

    return *this;
}

BigInteger& BigInteger::BigInteger::operator %=(const BigInteger& other)
{
    // maybe need to realise comparison with int(0)
    if (other.number == BigNatural(0))
        throw std::runtime_error("Division by zero");

    number %= other.number;
    if (!isPositive)
    {
        if (number != BigNatural(0))
            number = other.number - number;

        isPositive = true;
    }

    if (number == BigNatural(0))
        isPositive = true;

    return *this;
}

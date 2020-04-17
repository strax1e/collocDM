#include <exception>
#include <algorithm>
#include "BigInteger.h"

BigInteger::BigInteger(): isPositive(true), number(0){}

BigInteger::BigInteger(const BigInteger& x): isPositive(x.isPositive),
                number(x.number){}

BigInteger::BigInteger(BigInteger&& x): isPositive(x.isPositive), number(std::move(x.number)){}

BigInteger::BigInteger(const std::string& x)
{
    size_t it = 0;
    if (x.front() == '-')
    {
        isPositive = false;
        it++;
    }
    std::string s(x.substr(it, x.size()));
    number = std::stoll(s); // number = s;
}

BigInteger::BigInteger(const BigNatural& n): isPositive(true), number(n){}

BigInteger::BigInteger(BigNatural&& n): isPositive(true), number(std::move(n)){}

BigInteger::BigInteger(long long n): isPositive(n >= 0), number(std::abs(n)){}

BigInteger& BigInteger::operator =(const BigInteger& x)
{
    isPositive = x.isPositive;
    number = x.number;
    return *this;
}

BigInteger& BigInteger::operator =(BigInteger&& x)
{
    isPositive = x.isPositive;
    number = std::move(x.number);
    return *this;
}

BigInteger& BigInteger::operator =(const BigNatural& x)
{
    number = x;
    isPositive = true;
    return *this;
}

BigInteger& BigInteger::operator =(BigNatural&& x)
{
    number = std::move(x);
    return *this;
}

BigInteger::~BigInteger(){}

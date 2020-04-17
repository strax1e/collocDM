#ifndef ASSIGMENT_ARITHMETICS_IMPL_H_INCLUDED
#define ASSIGMENT_ARITHMETICS_IMPL_H_INCLUDED

#include <exception>

template < typename T >
BigInteger<T>& BigInteger<T>::operator +=(const BigInteger<T>& other)
{
    if (sign == other.sign)
        number += other.number;
    else
    {
        if (number >= other.number)
            number -= other.number;
        else
        {
            sign = !sign;
            T n(std::move(number));
            number = other.number;
            number -= n;
        }
    }
    return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator -=(const BigInteger<T>& other)
{
    if (sign != other.sign)
        number += other.number;
    else
    {
        if (number >= other.number)
            number -= other.number;
        else
        {
            sign = !sign;
            T n(std::move(number));
            number = other.number;
            number -= n;
        }
    }
    return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator *=(const BigInteger<T>& other)
{
    sign = sign == other.sign ? true : false;
    number *= other.number;
    return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator *=(int num) // -9 <= num <= 9
{
    if (std::abs(num) % 10 != 0)
        throw std::runtime_error("ERROR: multiplying by num(abs(num) % 10 != 0)");

    sign = sign == num > 0 ? true : false;
    number *= std::abs(num);
    return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator /=(const BigInteger<T>& other)
{
    throw std::runtime_error("feature not realised: operator /=(const BigInteger<T>&)");
    //return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::BigInteger::operator %=(const BigInteger<T>& other)
{
    throw std::runtime_error("feature not realised: operator %=(const BigInteger<T>&)");
    //return *this;
}


#endif // ASSIGMENT_ARITHMETICS_IMPL_H_INCLUDED

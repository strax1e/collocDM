#ifndef BASE_METHODS_IMPL_H_INCLUDED
#define BASE_METHODS_IMPL_H_INCLUDED

#include <exception>
#include <algorithm>

template < typename T >
BigInteger<T>::BigInteger(): sign(true), number("0"){}
template < typename T >
BigInteger<T>::BigInteger(const BigInteger<T>& x): sign(x.sign), number(x.number){}

template < typename T >
BigInteger<T>::BigInteger(BigInteger<T>&& x): sign(x.sign), number(std::move(x.number)){}

template < typename T >
BigInteger<T>::BigInteger(const std::string& x)
{
    size_t it = 0;
    if (x.front() == '-')
    {
        sign = false;
        it++;
    }
    std::string s(x.substr(it, x.size()));
    number(std::move(s));
}

template < typename T >
BigInteger<T>::BigInteger(const T& n): sign(true), number(n){}

template < typename T >
BigInteger<T>::BigInteger(T&& n): sign(true), number(std::move(n)){}

template < typename T >
BigInteger<T>::BigInteger(long long n): number(std::abs(n)), sign(n >= 0){}


template < typename T >
BigInteger<T>& BigInteger<T>::operator =(const BigInteger<T>& x)
{
    sign = x.sign;
    number = x.number;
    return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator =(BigInteger<T>&& x)
{
    sign = x.sign;
    number = std::move(x.number);
    return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator =(const T& x)
{
    number = x;
    return *this;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator =(T&& x)
{
    number = std::move(x);
    return *this;
}

template < typename T >
BigInteger<T>::~BigInteger(){}

#endif // BASE_METHODS_IMPL_H_INCLUDED

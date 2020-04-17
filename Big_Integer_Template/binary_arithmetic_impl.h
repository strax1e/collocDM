#ifndef BINARY_ARITHMETIC_IMPL_H_INCLUDED
#define BINARY_ARITHMETIC_IMPL_H_INCLUDED

template < typename T >
const BigInteger<T> operator +(BigInteger<T> left, const BigInteger<T>& right)
{
    left += right;
    return left;
}

template < typename T >
const BigInteger<T> operator -(BigInteger<T> left, const BigInteger<T>& right)
{
    left -= right;
    return left;
}

template < typename T >
const BigInteger<T> operator *(BigInteger<T> left, const BigInteger<T>& right)
{
    left *= right;
    return left;
}

template < typename T >
const BigInteger<T> operator /(BigInteger<T> left, const BigInteger<T>& right)
{
    left /= right;
    return left;
}

template < typename T >
const BigInteger<T> operator %(BigInteger<T> left, const BigInteger<T>& right)
{
    left %= right;
    return left;
}


#endif // BINARY_ARITHMETIC_IMPL_H_INCLUDED

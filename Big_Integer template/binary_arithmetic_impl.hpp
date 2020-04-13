#ifndef BINARY_ARITHMETIC_IMPL_HPP_INCLUDED
#define BINARY_ARITHMETIC_IMPL_HPP_INCLUDED

template < typename T >
const Big_Integer<T> operator +(Big_Integer<T> left, const Big_Integer<T>& right)
{
    left += right;
    return left;
}

template < typename T >
const Big_Integer<T> operator -(Big_Integer<T> left, const Big_Integer<T>& right)
{
    left -= right;
    return left;
}

template < typename T >
const Big_Integer<T> operator *(Big_Integer<T> left, const Big_Integer<T>& right)
{
    left *= right;
    return left;
}

template < typename T >
const Big_Integer<T> operator /(Big_Integer<T> left, const Big_Integer<T>& right)
{
    left /= right;
    return left;
}

template < typename T >
const Big_Integer<T> operator %(Big_Integer<T> left, const Big_Integer<T>& right)
{
    left %= right;
    return left;
}


#endif // BINARY_ARITHMETIC_IMPL_HPP_INCLUDED

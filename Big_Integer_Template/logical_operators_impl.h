#ifndef LOGICAL_OPERATORS_IMPL_H_INCLUDED
#define LOGICAL_OPERATORS_IMPL_H_INCLUDED

template < typename T >
bool BigInteger<T>::operator ==(const BigInteger<T>& other) const
{
    return number == other.number;
}

template < typename T >
bool BigInteger<T>::operator !=(const BigInteger<T>& other) const
{
    return number != other.number;
}

template < typename T >
bool BigInteger<T>::operator > (const BigInteger<T>& other) const
{
    return number > other.number;
}

template < typename T >
bool BigInteger<T>::operator < (const BigInteger<T>& other) const
{
    return number < other.number;
}

template < typename T >
bool BigInteger<T>::operator >=(const BigInteger<T>& other) const
{
    return number >= other.number;
}

template < typename T >
bool BigInteger<T>::operator <=(const BigInteger<T>& other) const
{
    return number <= other.number;
}


#endif // LOGICAL_OPERATORS_IMPL_H_INCLUDED

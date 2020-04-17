#ifndef INCREMENT_DECREMENT_IMPL_H_INCLUDED
#define INCREMENT_DECREMENT_IMPL_H_INCLUDED

template < typename T >
BigInteger<T>& BigInteger<T>::operator ++()
{
    if (sign)
        number++;
    else
        number--;

    if (number == 0)
        sign = true;

    return *this;
}

template < typename T >
BigInteger<T> BigInteger<T>::operator ++(int)
{
    BigInteger<T> copy(*this);
    if (sign)
        number++;
    else
        number--;

    if (number == 0)
        sign = true;

    return copy;
}

template < typename T >
BigInteger<T>& BigInteger<T>::operator --()
{
    if (sign)
        number--;
    else
        number++;

    if (number < 0)
        sign = false;

    return *this;
}

template < typename T >
BigInteger<T> BigInteger<T>::operator --(int)
{
    BigInteger<T> copy(*this);
    if (sign)
        number--;
    else
        number++;

    if (number < 0)
        sign = false;

    return copy;
}


#endif // INCREMENT_DECREMENT_IMPL_H_INCLUDED

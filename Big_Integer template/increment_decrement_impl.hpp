#ifndef INCREMENT_DECREMENT_IMPL_HPP_INCLUDED
#define INCREMENT_DECREMENT_IMPL_HPP_INCLUDED

template < typename T >
Big_Integer<T>& Big_Integer<T>::operator ++()
{
    if (_sign)
        _number++;
    else
        _number--;

    if (_number == 0)
        _sign = true;

    return *this;
}

template < typename T >
Big_Integer<T> Big_Integer<T>::operator ++(int)
{
    Big_Integer<T> copy(*this);
    if (_sign)
        _number++;
    else
        _number--;

    if (_number == 0)
        _sign = true;

    return copy;
}

template < typename T >
Big_Integer<T>& Big_Integer<T>::operator --()
{
    if (_sign)
        _number--;
    else
        _number++;

    if (_number < 0)
        _sign = false;

    return *this;
}

template < typename T >
Big_Integer<T> Big_Integer<T>::operator --(int)
{
    Big_Integer<T> copy(*this);
    if (_sign)
        _number--;
    else
        _number++;

    if (_number < 0)
        _sign = false;

    return copy;
}


#endif // INCREMENT_DECREMENT_IMPL_HPP_INCLUDED

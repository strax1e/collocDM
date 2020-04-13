#ifndef LOGICAL_OPERATORS_IMPL_HPP_INCLUDED
#define LOGICAL_OPERATORS_IMPL_HPP_INCLUDED

template < typename T >
bool Big_Integer<T>::operator ==(const Big_Integer<T>& other) const
{
    return _number == other._number;
}

template < typename T >
bool Big_Integer<T>::operator !=(const Big_Integer<T>& other) const
{
    return _number != other._number;
}

template < typename T >
bool Big_Integer<T>::operator > (const Big_Integer<T>& other) const
{
    return _number > other._number;
}

template < typename T >
bool Big_Integer<T>::operator < (const Big_Integer<T>& other) const
{
    return _number < other._number;
}

template < typename T >
bool Big_Integer<T>::operator >=(const Big_Integer<T>& other) const
{
    return _number >= other._number;
}

template < typename T >
bool Big_Integer<T>::operator <=(const Big_Integer<T>& other) const
{
    return _number <= other._number;
}


#endif // LOGICAL_OPERATORS_IMPL_HPP_INCLUDED

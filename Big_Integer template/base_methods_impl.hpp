#ifndef BASE_METHODS_IMPL_HPP_INCLUDED
#define BASE_METHODS_IMPL_HPP_INCLUDED

#include <exception>

template < typename T >
Big_Integer<T>::Big_Integer()
{
    throw std::runtime_error("featch not realised: Big_Integer()");
}
template < typename T >
Big_Integer<T>::Big_Integer(const Big_Integer<T>& x): _sign(x._sign), _number(x._number){}

template < typename T >
Big_Integer<T>::Big_Integer(Big_Integer<T>&& x): _sign(x._sign), _number(std::move(x._number)){}

template < typename T >
Big_Integer<T>::Big_Integer(const std::string& x)
{
    throw std::runtime_error("featch not realised: Big_Integer(const std::string&)");
}

template < typename T >
Big_Integer<T>::Big_Integer(const T& n): _sign(true), _number(n){}

template < typename T >
Big_Integer<T>::Big_Integer(T&& n): _sign(true), _number(std::move(n)){}

template < typename T >
Big_Integer<T>& Big_Integer<T>::operator =(const Big_Integer& x)
{
    _sign = x._sign;
    _number = x._number;
}

template < typename T >
Big_Integer<T>& Big_Integer<T>::operator =(Big_Integer<T>&& x)
{
    _sign = x._sign;
    _number = std::move(x._number);
}

template < typename T >
Big_Integer<T>::~Big_Integer(){}





#endif // BASE_METHODS_IMPL_HPP_INCLUDED

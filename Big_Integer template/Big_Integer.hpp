#ifndef BIG_INTEGER_HPP_INCLUDED
#define BIG_INTEGER_HPP_INCLUDED

#include <string>

//class Big_Natural{};
typedef unsigned short Big_Natural;

//inline std::ostream& operator <<(std::ostream& os, const Big_Natural& x)
//{
//    //os << "big natural value\n";
//    return os;
//}

template < typename T >
class Big_Integer
{
public:
    Big_Integer();
    Big_Integer(const Big_Integer&);
    Big_Integer(Big_Integer&&);

    Big_Integer(const std::string&);
    Big_Integer(const T&);
    Big_Integer(T&&);

    ~Big_Integer();

    Big_Integer& operator =(const Big_Integer&);
    Big_Integer& operator =(Big_Integer&&);

    bool operator ==(const Big_Integer&) const;
	bool operator !=(const Big_Integer&) const;
	bool operator > (const Big_Integer&) const;
	bool operator < (const Big_Integer&) const;
	bool operator >=(const Big_Integer&) const;
	bool operator <=(const Big_Integer&) const;

    Big_Integer& operator +=(const Big_Integer&);
    Big_Integer& operator -=(const Big_Integer&);
    Big_Integer& operator *=(const Big_Integer&);
    Big_Integer& operator *=(int);
    Big_Integer& operator /=(const Big_Integer&);
    Big_Integer& operator %=(const Big_Integer&);

    Big_Integer& operator ++();
    Big_Integer  operator ++(int);
    Big_Integer& operator --();
    Big_Integer  operator --(int);

    template < typename U >
    friend const Big_Integer<U> operator +(Big_Integer<U>, const Big_Integer<U>&);
    template < typename U >
    friend const Big_Integer<U> operator -(Big_Integer<U>, const Big_Integer<U>&);
    template < typename U >
    friend const Big_Integer<U> operator *(Big_Integer<U>, const Big_Integer<U>&);
    template < typename U >
    friend const Big_Integer<U> operator /(Big_Integer<U>, const Big_Integer<U>&);
    template < typename U >
    friend const Big_Integer<U> operator %(Big_Integer<U>, const Big_Integer<U>&);

    template < typename U >
    friend inline std::ostream& operator <<(std::ostream& os, const Big_Integer<U>& x);

private:
    bool _sign; // true -> number >= 0
    T _number;
};

#include "assigment_arithmetics_impl.hpp"
#include "base_methods_impl.hpp"
#include "binary_arithmetic_impl.hpp"
#include "increment_decrement_impl.hpp"
#include "iostream_impl.hpp"
#include "logical_operators_impl.hpp"

#endif // BIG_INTEGER_HPP_INCLUDED

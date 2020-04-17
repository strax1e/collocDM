#ifndef BigInteger_H_INCLUDED
#define BigInteger_H_INCLUDED

#include <string>

template < typename T >
class BigInteger
{
public:
    BigInteger();
    BigInteger(const BigInteger<T>&);
    BigInteger(BigInteger<T>&&);

    BigInteger(const std::string&);
    explicit BigInteger(const T&);
    explicit BigInteger(T&&);
    explicit BigInteger(long long);

    BigInteger<T>& operator =(const BigInteger<T>&);
    BigInteger<T>& operator =(BigInteger<T>&&);
    BigInteger<T>& operator =(const T&);
    BigInteger<T>& operator =(T&&);

    ~BigInteger();

    bool operator ==(const BigInteger<T>&) const;
	bool operator !=(const BigInteger<T>&) const;
	bool operator > (const BigInteger<T>&) const;
	bool operator < (const BigInteger<T>&) const;
	bool operator >=(const BigInteger<T>&) const;
	bool operator <=(const BigInteger<T>&) const;

    BigInteger<T>& operator +=(const BigInteger<T>&);
    BigInteger<T>& operator -=(const BigInteger<T>&);
    BigInteger<T>& operator *=(const BigInteger<T>&);
    BigInteger<T>& operator *=(int);
    BigInteger<T>& operator /=(const BigInteger<T>&);
    BigInteger<T>& operator %=(const BigInteger<T>&);

    BigInteger<T>& operator ++();
    BigInteger<T>  operator ++(int);
    BigInteger<T>& operator --();
    BigInteger<T>  operator --(int);

    template < typename U >
    friend const BigInteger<U> operator +(BigInteger<U>, const BigInteger<U>&);
    template < typename U >
    friend const BigInteger<U> operator -(BigInteger<U>, const BigInteger<U>&);
    template < typename U >
    friend const BigInteger<U> operator *(BigInteger<U>, const BigInteger<U>&);
    template < typename U >
    friend const BigInteger<U> operator /(BigInteger<U>, const BigInteger<U>&);
    template < typename U >
    friend const BigInteger<U> operator %(BigInteger<U>, const BigInteger<U>&);

    template < typename U >
    friend inline std::ostream& operator <<(std::ostream& os, const BigInteger<U>& x);

private:
    bool sign; // true -> number >= 0
    T number;
};

#include "assigment_arithmetics_impl.h"
#include "base_methods_impl.h"
#include "binary_arithmetic_impl.h"
#include "increment_decrement_impl.h"
#include "iostream_impl.h"
#include "logical_operators_impl.h"

#endif // BigInteger_H_INCLUDED

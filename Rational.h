
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include "BigInteger.h"
#include "BigNatural.h"
using namespace std;

class Rational
{
public:
    explicit Rational(BigInteger num_ = 0, BigNatural den_ = 1) : num(num_), den(den_)
    {
        Make();
    }

    
    void Make();
    


    friend Rational& operator +=(Rational&,  Rational const&);
    friend Rational& operator -=(Rational&, Rational const&);
    friend Rational& operator *=(Rational&, Rational const&);
    friend Rational& operator *=(Rational&, Rational const&);
    friend Rational& operator /=(Rational&, Rational const&);

    friend ostream& operator << (ostream&, Rational const&);
    friend istream& operator>> (istream&, Rational&);

    friend Rational& operator+ (Rational& ,  Rational& );
    friend Rational&  operator- (Rational&, Rational&);
    friend Rational&  operator* (Rational&, Rational&);
    friend Rational&  operator/ (Rational&, Rational&);

    
    
    
    
    friend bool operator< (Rational const&, Rational const&);
    friend bool operator== (Rational const&, Rational const&);
    friend bool operator> (Rational const&, Rational const&);
    friend bool operator<= (Rational const&, Rational const&);
    friend bool operator>= (Rational const&, Rational const&);


    Rational& operator= (const Rational& r)
    {
        num = r.num;
        den = r.den;

        return *this;
    }
        
    Rational& operator= (Rational& r)
    {
        num = r.num;
        den = r.den;

        return *this;
    }
    
    
    
public:
   
    BigInteger num;
    BigNatural den;
};


#endif // RATIONAL_H
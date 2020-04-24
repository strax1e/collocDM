
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include "BigInteger.h"
#include "BigNatural.h"
using namespace std;

class Rational
{
public:
    explicit Rational(int num_ = 0, int den_ = 1) : num(num_), den(den_)
    {
        Make();
    }

    
    void Make();
    
public:
    Rational RED_Q_Q(Rational &r)
    {

    }

    bool INT_Q_B(Rational &r)
    {
        if (RED_Q_Q(r).den == 1)
        {
            return true;
        }
        else return false;
    }

    Rational& TRANS_Z_Q(int i)
    {
        num = i; 
        den = 1;

        return *this;
    }

    BigInteger TRANS_Q_Z(Rational& r)
    {
        if (r.den == 1)
        {
            return r.num;
        }
        else
        {
            throw invalid_argument("something");
        }
    }

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
        
    Rational& operator= (Rational&& r)
    {
        num = r.num;
        den = r.den;

        return *this;
    }
    
    
    
private:
   
    BigInteger num;
    BigNatural den;
};


#endif // RATIONAL_H

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
    
    Rational(string s)
    { 
        int k = 0;
        den = 0;
        for (int i = 0; i < s.size; i++)
        {
            if (s[0] < 48 || s[0] > 57)
            {
                throw runtime_error("Invalid synatax");
            }
            else
            {
                while (s[i] != '\\')
                {
                    if ((s[i] < 48 || s[i] > 57) && s[i] != '\\')
                    {
                        throw runtime_error("Invalid synatax");
                    }
                    i++;
                    k++;
                }
                num = (BigInteger)s.substr(0, i);

                if (s[i] < 48 || s[i] > 57)
                {
                    throw runtime_error("Invalid synatax");
                }
            }
        }

        den = (BigInteger)s.substr(k + 1, k);



    }

    friend Rational& operator +=(Rational&,  Rational const&);
    friend Rational& operator -=(Rational&, Rational const&);
    friend Rational& operator *=(Rational&, Rational const&);
    friend Rational& operator *=(Rational&, Rational const&);
    friend Rational& operator /=(Rational&, Rational const&);

    friend ostream& operator << (ostream&, Rational const&);
    friend istream& operator>> (istream&, Rational&);

    friend const Rational operator+ (Rational , Rational const& );
    friend const Rational  operator- (Rational, Rational const&);
    friend  const Rational  operator* (Rational, Rational const&);
    friend  const Rational  operator/ (Rational, Rational const&);

    
    
    
    
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
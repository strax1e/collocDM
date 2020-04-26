
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

#include "../BigInteger/BigInteger.h"

using namespace std;

class Rational
{
public:
  explicit Rational(BigInteger num_ = 0, BigNatural den_ = 1) : num(num_), den(den_)
  {
    Make();
  }
  
  void Make();
  
  Rational( const string &s )
  { 
    int k = 0, i;
    den = 1;
    for (i = 0; i < s.size(); i++)
    {
      if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
        throw runtime_error("Invalid syntax");
      if (s[i] == '-')
      {
        i++;
        if (s[i] == '0')
          throw std::runtime_error("Invalid syntax");
      }
      while (s[i] != '/' && i < s.size())
      {
        if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
            throw runtime_error("Invalid syntax");
        i++;
      }
      num = (BigInteger)s.substr(0, i);
      if (s[i] != '/')
        break;
      k = ++i;
      while (i < s.size())
      {
        if (!((s[i] >= '0' && s[i] <= '9')))
          throw runtime_error("Invalid syntax");
        i++;
      }
    }

    if (k > 0)
      den = (BigNatural)s.substr(k, s.size() - 1);
    if (den == 0)
      throw std::runtime_error("Denominator must not be zero");
  }

  const BigInteger GetNum( void );
  const BigNatural GetDen( void );
  void Reduct( void );

  friend  Rational RED_Q_Q(const Rational&);
  friend BigInteger TRANS_Q_Z(Rational);
  friend  bool INT_Q_B(Rational&);

  friend Rational& operator +=(Rational&,  Rational const&);
  friend Rational& operator -=(Rational&, Rational const&);
  friend Rational& operator *=(Rational&, Rational const&);
  friend Rational& operator *=(Rational&, Rational const&);
  friend Rational& operator /=(Rational&, Rational const&);

  friend ostream& operator << (ostream&, Rational const&);

  friend const Rational operator+ (Rational, Rational const&);
  friend const Rational operator- (Rational, Rational const&);
  friend const Rational operator* (Rational, Rational const&);
  friend const Rational operator/ (Rational, Rational const&);

  friend bool operator<(Rational const&, Rational const&);
  friend bool operator>(Rational const&, Rational const&);
  friend bool operator<=(Rational const&, Rational const&);
  friend bool operator>=(Rational const&, Rational const&);
  friend bool operator==(Rational const&, Rational const&);


  Rational& operator=(const Rational& r)
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
      
private:
  
  BigInteger num;
  BigNatural den;
};

#endif // RATIONAL_H
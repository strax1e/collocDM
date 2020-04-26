/* Polynom declaration modeule
 * Authors:
 * - Kodukov Aleksandr 9373
 * - Emilia Shmidt 9373
 */

#ifndef _POLYNOM_H
#define _POLYNOM_H

#include <vector>
#include <string>

#include "../Rational/Rational.h"

class Polynom
{
private:
  size_t degree;               // Polynomial degree
  std::vector<Rational> coefs; // vector of coefficients

  Polynom( int lenght );
  Polynom( int pos, Rational coef );
  void Optimize( void );
public: 
  Polynom( void );
  Polynom( const std::vector<Rational> &coef );
  Polynom( const std::string &expr );
  ~Polynom( void );

  void Print( void );
  size_t GetDegree( void ) const;
  Rational LeadCoef( void ) const;

  Rational operator[]( int ind ) const;
  friend Polynom &operator+=( Polynom &left, const Polynom &right );
  friend const Polynom operator+( Polynom left, const Polynom &right );
  friend const Polynom operator+( const Polynom &p );

  friend Polynom &operator-=( Polynom &left, const Polynom &right );
  friend const Polynom operator-( Polynom left, const Polynom &right );
  friend const Polynom operator-( const Polynom &p );

  friend Polynom &operator*=( Polynom &p, Rational num );
  friend const Polynom operator*( Polynom p, Rational num );

  friend Polynom &operator/=( Polynom &p, Rational num );
  friend const Polynom operator/( Polynom p, Rational num );

  friend Polynom &operator*=( Polynom &left, const Polynom &right );
  friend const Polynom operator*( Polynom left, const Polynom &right );

  friend Polynom MulByMono( const Polynom &p, int degree );

  friend Polynom &operator/=( Polynom &left, const Polynom &right );
  friend const Polynom operator/( Polynom left, const Polynom &right );

  friend Polynom &operator%=( Polynom &left, const Polynom &right );
  friend const Polynom operator%( Polynom left, const Polynom &right );

  friend std::ostream& operator<<(std::ostream& os, const Polynom& x);

};
const Polynom GCD( const Polynom &left, const Polynom &right );
Rational FAC( const Polynom &p );
const Polynom DER( const Polynom &p );
const Polynom NMR( Polynom p );

#endif // _POLYNOM_H
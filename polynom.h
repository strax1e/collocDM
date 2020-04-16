/* Polynom declaration modeule
 * Authors:
 * - Kodukov Aleksandr 9373
 * - Emilia Shmidt 9373
 */

#ifndef _POLYNOM_H
#define _POLYNOM_H

#include <vector>
#include <exception>

namespace poly
{
  class Polynom
  {
  private:
    int degree;               // Polynomial degree
    std::vector<float> coefs; // vector of coefficients

    void Optimize( void );
  public: 
    Polynom( void );
    Polynom( const std::vector<float> &coef );
    ~Polynom( void );

    /* Ya */

    void Print( void );
    const float GetCoef( int pos );
    const float GetDegree( void );
    friend Polynom &operator+=( Polynom &left, const Polynom &right );
    friend const Polynom operator+( const Polynom &left, const Polynom &right );
    friend const Polynom operator+( const Polynom &p );
    friend Polynom &operator*=( Polynom &p, float num );
    friend const Polynom operator*( const Polynom &p, float num );
    ///friend const Polynom operator/( const Polynom &left, const Polynom &right );
    ///friend Polynom &operator/=( Polynom &left, const Polynom &right );

    /* Ti */

    ///friend Polynom &operator-=( Polynom &left, const Polynom &right );
    ///friend const Polynom operator-( const Polynom &left, const Polynom &right );
    //унарный минус
    ///friend const Polynom operator-( const Polynom &p );
    ///friend const Polynom operator*( const Polynom &left, const Polynom &right );
    ///friend Polynom &operator*=( Polynom &left, const Polynom &right );
    //умножения на x^k
    ///friend Polynom &operator*=( Polynom &p, int degree );
    ///friend const Polynom operator*( const Polynom &p, int degree );
    //остаток от деления
    ///friend const Polynom operator%( const Polynom &left, const Polynom &right );
    ///friend Polynom &operator%=( Polynom &left, const Polynom &right );

  };
  /* Ya */
  ///const Rational FAC_P_Q( const Polynom &p );
  ///const Polynom GCF_PP_P( const Polynom &p1, const polynom &p2 );
  ///const Polynom NMR_P_P( const Polynom &p );

  /* Ti */
  ///const Polynom DEP_P_P( const Polynom &p );
} 
#endif // _POLYNOM_H
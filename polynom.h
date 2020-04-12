/* Polynom declaration modeule
 * Authors:
 * - Kodukov Aleksandr 9373
 * - Emilia Shmidt 9373
 */

#ifndef _POLYNOM_H
#define _POLYNOM_H

#include <vector>

namespace poly
{
  class polynom
  {
  private:
    int degree;               // polynomial degree
    std::vector<float> coefs; // vector of coefficients

    const polynom ADD_PP_P( const polynom &p1, const polynom &p2 );

  public:
    polynom( void );
    polynom( const std::vector<float> &coef );
    ~polynom( void );

    const polynom &operator+=( const polynom &p );
    const polynom operator+( const polynom &p );
  };
}
#endif // _POLYNOM_H
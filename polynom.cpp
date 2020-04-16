/* Polynomial source code module
 * Authors:
 * - Kodukov Aleksandr 9373
 * - Emilia Shmidt 9373
 */

#include "typedef.h"

using namespace poly;

/* Default Polynom contructor */
Polynom::Polynom( void )
{
  degree = 0;
  coefs = {0};
} /* End of 'Polynom' function */

/* Polynom destructor */
Polynom::~Polynom( void )
{
} /* End of '~Polynom' function */

/* Polynom constructor from coefficients
 * ARGUMENTS:
 *   - coefficients vector:
 *       const std::vector<float> &coefs;
 */
Polynom::Polynom( const std::vector<float> &coefs )
{
  degree = coefs.size();
  this->coefs = coefs;
  Optimize();
} /* End of 'Polynom' function */

/* Polynomial simplifying function
 * ARGUMENTS: None
 * RETURNS: None
 */
void Polynom::Optimize( void )
{
  int cur = degree - 1, size;

  if (coefs[cur] == 0)
  {
    while (coefs[cur] == 0 && cur > 0)
      cur--;
    coefs.resize(cur + 1);
  }
} /* End of 'Optimize' function */


/* Polynom print function
 * ARGUMENTS: None
 * RETURNS: None
 */
void Polynom::Print( void )
{
  for (int i = coefs.size() - 1; i >= 0; i--)
  {
    if (coefs[i] > 0 && i != 0)
      printf("%fx^%i + ", coefs[i], i);
    if (i == 0)
    {
      if (coefs[i] == 0)
      {
        if (coefs.size() == 1)
          printf("0");
      }
      else
        printf("%f", coefs[0]);
    }
  }
} /* End of 'Print' function */

/* Polynomial coefficient getting function
 * ARGUMENTS:
 *   - Position:
 *       int pos;
 * RETURNS:
 *   (Rational) Coefficient
 */
const float Polynom::GetCoef( int pos )
{
  return coefs[pos - 1];
} /* End of 'GetCoef' function */

/* Polynomial degree getting function
 * ARGUMENTS: None
 * RETURNS: Degree
 */
const float Polynom::GetDegree( void )
{
  return degree;
} /* End of 'GetCoef' function */

/* Polynom addition with assignment operator
 * ARGUMENTS:
 *   - Polynomials:
 *       Polynom &left, const Polynom &right;
 * RETURNS:
 *   (Polynom) Summing result
 */
Polynom &poly::operator+=( Polynom &left, const Polynom &right )
{
  if (right.degree > left.degree)
    left.coefs.resize(right.degree);
  for (int i = 0; i < fmin(left.degree, right.degree); i++)
    left.coefs[i] += right.coefs[i];
  left.Optimize();
  
  return left;
} /* End of 'operator+=' function */

/* Polynom sum operator
 * ARGUMENTS:
 *   - Polynomials:
 *       const Polynom &left, const Polynom &right
 * RETURNS:
 *   (Polynom) Summing result
 */
const Polynom poly::operator+( const Polynom &left, const Polynom &right )
{
  Polynom res = left;

  return res += right;
} /* End of 'operator+' function */

/* Polynom unary '+' operator
 * ARGUMENTS:
 *   - second Polynomial:
 *       const Polynom &p;
 * RETURNS:
 *   (Polynom) Summing result
 */
const Polynom poly::operator+( const Polynom &p )
{
  return p;
} /* End of 'operator+' function */

/* Polynom multiplying by number operator
 * ARGUMENTS:
 *   - Polynomial:
 *       Polynom &p;
 *   - Number:
 *       float num;
 * RETURNS:
 *   (Polynom) Multiplying result
 */
Polynom &poly::operator*=( Polynom &p, float num )
{
  for (int i = 0; i < p.degree; i++)
    p.coefs[i] *= num;
  p.Optimize();
  
  return p;
} /* End of 'operator*=' function */

/* Polynom multiplying by number and assignment operator
 * ARGUMENTS:
 *   - Polynomial:
 *       const Polynom &p;
 *   - Number:
 *       float num;
 * RETURNS:
 *   (Polynom) Multiplying result
 */
const Polynom poly::operator*( const Polynom &p, float num )
{
  Polynom res = p;

  return res *= num;
} /* End of 'operator+' function */

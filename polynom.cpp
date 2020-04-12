/* Polynomial source code module
 * Authors:
 * - Kodukov Aleksandr 9373
 * - Emilia Shmidt 9373
 */

#include "typedef.h"

using namespace poly;

/* Default polynom contructor */
polynom::polynom( void )
{
} /* End of 'polynom' function */

/* Polynom destructor */
polynom::~polynom( void )
{
} /* End of '~polynom' function */

/* Polynom constructor from coefficients
 * ARGUMENTS:
 *   - coefficients vector:
 *       const std::vector<float> &coefs;
 */
polynom::polynom( const std::vector<float> &coefs )
{
  degree = coefs.size();
  this->coefs = coefs;
} /* End of 'polynom' function */

/* Polynomial summing funtion
 * ARGUMENTS:
 *   - coefficients vector:
 *       const std::vector<float> &coefs;
 * RETURNS:
 *   (polynom) Summing result
 */
const polynom polynom::ADD_PP_P( const polynom &p1, const polynom &p2 )
{
  polynom res = p1.degree > p2.degree ? p1 : p2;

  for (int i = 0; i < fmin(p1.degree, p2.degree); i++)
    res.coefs[i] = p1.coefs[i] + p2.coefs[i];

  return res;
} /* End of 'ADD_PP_P' function */

/* Polynom addition with assignment operator
 * ARGUMENTS:
 *   - second polynomial:
 *       const polynom &p;
 * RETURNS:
 *   (polynom) Summing result
 */
const polynom &poly::polynom::operator+=( const polynom &p )
{
  return *this = polynom::ADD_PP_P(*this, p);
} /* End of 'operator+=' function */

/* Polynom sum operator
 * ARGUMENTS:
 *   - second polynomial:
 *       const polynom &p;
 * RETURNS:
 *   (polynom) Summing result
 */
const polynom poly::polynom::operator+( const polynom &p )
{
  return *this += p;
} /* End of 'operator+' function */

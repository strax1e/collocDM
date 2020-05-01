#include "standart_functions.h"

/* Polynomials addition function
 * ARGUMENTS:
 *   - Polynomials:
 *       Polynom left, const Polynom &right;
 * RETURNS:
 *   (Polynom) Result
 */
Polynom ADD_PP_P(Polynom left, const Polynom &right)
{
  return left += right;
}

/* Polynomials subtraction function
 * ARGUMENTS:
 *   - Polynomials:
 *       Polynom left, const Polynom &right;
 * RETURNS:
 *   (Polynom) Result
 */
Polynom SUB_PP_P(Polynom left, const Polynom &right)
{
  return left -= right;
}

/* Polynomial by number multiplication function
 * ARGUMENTS:
 *   - Polynomial:
 *       Polynom left
 *   - Number:
 *       const Rational &right;
 * RETURNS:
 *   (Polynom) Result
 */
Polynom MUL_PQ_P(Polynom left, const Rational &right)
{
  return left *= right;
}

/* Polynomial by x^k multiplying function
 * ARGUMENTS:
 *   - x degree:
 *       size_t degree;
 * RETURNS:
 *   (Polynom) Multiplying result
 */
Polynom MUL_Pxk_P(Polynom left, size_t k)
{
  return MulByMono(left, k);
}

/* Leading coefficient getting function
 * ARGUMENTS:
 *   - polynomial:
 *       const Polynom &p;
 * RETURNS: 
 *   (Rational) Coefficient
 */
Rational LED_P_Q(const Polynom &p)
{
  return p.LeadCoef();
}

/* Polynomial degree getting function
 * ARGUMENTS: None
 * RETURNS:
 *   (size_t) Degree
 */
BigNatural DEG_P_N(const Polynom &p)
{
  return p.GetDegree();
}

/* Coeffsicients GCD/LCM finding function
 * ARGUMENTS:
 *  - Polynomial:
 *      const Polynom &p;
 * RETURNS:
 *   (Rational) GCD/LCM
 */
Rational FAC_P_Q(const Polynom &p)
{
  return FAC(p);
}

/* Polynomials multipication function
 * ARGUMENTS:
 *   - Polynomials:
 *       Polynom left, const Polynom &right;
 * RETURNS:
 *   (Polynom) Result
 */
Polynom MUL_PP_P(Polynom left, const Polynom &right)
{
  return left *= right;
}

/* Polynomials division function
 * ARGUMENTS:
 *   - Polynomials:
 *       Polynom left, const Polynom &right;
 * RETURNS:
 *   (Polynom) Result
 */
Polynom DIV_PP_P(Polynom left, const Polynom &right)
{
  return left /= right;
}

/* Polynomials reminder of division getting function
 * ARGUMENTS:
 *   - Polynomials:
 *       Polynom left, const Polynom &right;
 * RETURNS:
 *   (Polynom) Result
 */
Polynom MOD_PP_P(Polynom left, const Polynom &right)
{
  return left %= right;
}

/* Greatest common divider of polynomials fiding function
 * ARGUMENTS:
 *  - Polynomials:
 *      const Polynom &left, const Polynom &right;
 * RETURNS:
 *   (Polynom) GCD
 */
Polynom GCF_PP_P(const Polynom &left, const Polynom &right)
{
  return GCD(left, right);
}

/* Polynomial derivative finding function
 * ARGUMENTS:
 *  - Polynomial:
 *      const Polynom &p;
 * RETURNS:
 *   (Polynom) Deriative
 */
Polynom DER_P_P(const Polynom &p)
{
  return DER(p);
}

/* Converting multiple roots to simple function
 * ARGUMENTS:
 *  - Polynomial:
 *      const Polynom &p;
 * RETURNS:
 *   (Polynom) Result
 */
Polynom NMR_P_P(const Polynom &p)
{
  return NMR(p);
}
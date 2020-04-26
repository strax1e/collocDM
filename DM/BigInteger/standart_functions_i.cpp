#include "../standart_functions.h"

/* ABS function
 * ARGUMENTS:
 *   - BigInteger:
 *       BigInteger& x or BigInteger&& x (xvalue)
 * RETURNS:
 *   - BigNatural(result of abs)
 */
BigNatural ABS_Z_N(const BigInteger &x) 
{ 
  return x.getNatural(); 
}

/* Transformation function(BigNatural to BigInteger)
 * ARGUMENTS:
 *   - BigNatural:
 *       BigNatural& x or BigNatural&& x (xvalue)
 * RETURNS:
 *   - BigInteger(result of transformation)
 */
BigInteger TRANS_N_Z(const BigNatural &x)
{ 
  return BigInteger(x); 
}

/* Transformation function(BigInteger to BigNatural)
 * ARGUMENTS:
 *   - BigInteger:
 *       BigInteger& x or BigInteger&& x (xvalue)
 * RETURNS:
 *   - BigNatural(result of transformation)
 */
BigNatural TRANS_Z_N(const BigInteger &x)
{
  if (x < BigNatural(0))
    throw std::runtime_error("ERROR: invalid transformation from integer to natural");

  return x.getNatural();
}

/* Reversing sign of BigInteger function
 * ARGUMENTS:
 *   - BigInteger:
 *       BigInteger& x
 * RETURNS:
 *   - none
 */
void MUL_ZM_Z(BigInteger& x) 
{ 
  x *= -1; 
}

/* Getting position of number function
* ARGUMENTS:
*   - BigInteger:
*       const BigInteger& x
* RETURNS:
*   - int(0 if x == 0, 1 if x < 0, 2 if x > 0)
*/
int POZ_Z_D(const BigInteger& x)
{
  if (x == BigInteger(0))
    return 0;

  if (x.isNegative())
    return 1;

  return 2;
}

/* Simple arithmetic operatoins functions
 * ARGUMENTS:
 *   - BigInteger:
 const BigInteger& left, const BigInteger& right
 * RETURNS:
 *   - BigInteger(result of operation)
 */
BigInteger ADD_ZZ_Z(const BigInteger& left, const BigInteger& right)
{ 
  return left + right; 
}
BigInteger SUB_ZZ_Z(const BigInteger& left, const BigInteger& right)
{ 
  return left - right; 
}
BigInteger MUL_ZZ_Z(const BigInteger& left, const BigInteger& right)
{ 
  return left * right; 
}
BigInteger DIV_ZZ_Z(const BigInteger& left, const BigInteger& right)
{
  if (left <= BigInteger(0) || right <= BigInteger(0))
    throw std::runtime_error("ERROR: div with not natural numbers");

  return left / right;
}
BigInteger MOD_ZZ_Z(const BigInteger& left, const BigInteger& right)
{
  if (left <= BigInteger(0) || right <= BigInteger(0))
    throw std::runtime_error("ERROR: div with not natural numbers");

  return left % right;
}
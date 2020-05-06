/* Polynomial source code module
 * Authors:
 * - Kodukov Aleksandr 9373
 * - Emilia Shmidt 9373
 */

#include <map>
#include <algorithm>
#include <exception>
#include <stdexcept>

#include "polynom.h"
#include "../standart_functions.h"

#define zero Rational(0, 1)

/* Default Polynom contructor */
Polynom::Polynom( void )
{
  degree = 0;
  coefs = {Rational(0, 1)};
}

/* Polynom destructor */
Polynom::~Polynom( void )
{
}

/* Polynom constructor from length
 * ARGUMENTS:
 *   - Polynomial predicted degree:
 *       const std::vector<Rational> &coefs;
 */
Polynom::Polynom( size_t length ) : degree(length - 1)
{
  coefs.resize(length, Rational(0, 1));
}

/* Polynom constructor from coefficients
 * ARGUMENTS:
 *   - coefficients vector:
 *       const std::vector<Rational> &coefs;
 */
Polynom::Polynom( const std::vector<Rational> &coefs ) : degree(coefs.size() - 1), coefs(coefs)
{
  if (coefs.size() > 9223372036854775806LL)
    throw std::runtime_error("Too big polynom");
  Optimize();
}

/* Polynom constructor from string
 * ARGUMENTS:
 *   - expression string:
 *       const std::string &expr;
 */
Polynom::Polynom( const std::string &expr )
{
  int cur = 0;
  char ch = expr[cur];
  bool iscoef = false, isdeg = false;
  int numsize = 0;
  Rational coef = Rational(1);
  size_t deg = 0;
  std::string curnum;

  if (expr.size() == 0)
  {
    degree = 0;
    coefs = {zero};
    return;
  }

  while (cur < expr.size())
  {
    ch = expr[cur];
    if (ch == ' ')
    {
      cur++;
      continue;
    }
    else if (iscoef && !isdeg)
    {
      bool wasx = false;
      while (1)
      {
        ch = expr[cur++];
        if (ch == ' ')
          continue;
        else if (ch == 'x' && !wasx)
          wasx = true;
        else if (ch == '^' && wasx)
        {
          isdeg = true;
          break;
        }
        else
        {
          if (wasx)
            deg = 1;
          if (coefs.size() < deg + 1)
            coefs.resize(deg + 1, zero);
          coefs[deg] += coef;
          deg = 0;
          iscoef = false;
          cur--;
          break;
        }
      }
    }
    else if (ch >= '0' && ch <= '9' || ch == '-' || ch == '+')
    {
      if (!iscoef)
      {
        iscoef = true;
        if (coefs.size() > 0 && ch != '-' && ch != '+')
          throw std::runtime_error("Invalid syntax");
        if (ch == '+')
        {
          cur++;
          ch = expr[cur];
        }
        else if (ch == '-')
        {
          curnum.push_back(ch);
          ch = expr[++cur];
        }
        while (ch >= '0' && ch <= '9' || ch == '/' || ch == ' ')
        {
          if (ch == ' ')
          {
            ch = expr[++cur];
            continue;
          }
          curnum.push_back(ch);
          ch = expr[++cur];
        }
        if (curnum.size() == 1 && curnum[0] == '-' || curnum.size() == 0)
          throw std::runtime_error("Invalid syntax");
        coef = Rational(curnum);
        curnum.clear();
      }
      else if (isdeg)
      {
        int size = 0, firstdigit;
        if (ch < '0' || ch > '9')
          throw std::runtime_error("Invalid syntax");
        deg = 0;
        ch = expr[cur];
        while (ch >= '0' && ch <= '9' || ch == ' ')
        {
          if (ch == ' ')
          {
            ch = expr[++cur];
            continue;
          }
          if (isdeg)
          {
            firstdigit = ch - '0';
            isdeg = false;
          }
          curnum.push_back(ch);
          numsize++;
          ch = expr[++cur];
        }
        deg = atoll(curnum.data());
        if (deg == 0 && firstdigit != 0 || numsize > 4)
          throw std::runtime_error("Invalid syntax");
        curnum.clear();
        numsize = 0;
        if (coefs.size() < deg + 1)
          coefs.resize(deg + 1, zero);
        coefs[deg] += coef;
        deg = 0;
        coef = Rational(1);
        iscoef = false;
      }
      else
        throw std::runtime_error("Invalid syntax");
    }
    else
      throw std::runtime_error("Invalid syntax");
  }
  if (iscoef && !isdeg)
  {
    if (coefs.size() < deg + 1)
      coefs.resize(deg + 1, zero);
    coefs[deg] += coef;
  }
  if (isdeg)
    throw std::runtime_error("Missing degree");
  
  Optimize();
}

/* Polynomial simplifying function
 * ARGUMENTS: None
 * RETURNS: None
 */
void Polynom::Optimize( void )
{
  size_t cur = coefs.size() - 1;

  if (coefs[cur] == zero)
  {
    while (coefs[cur] == zero && cur > 0)
      cur--;
    coefs.resize(cur + 1);
  }
  degree = coefs.size() - 1;
}

/* Polynomial coefficient getting function
 * ARGUMENTS:
 *   - Position:
 *       size_t int;
 * RETURNS:
 *   (Rational) Coefficient
 */
Rational Polynom::operator[]( size_t ind ) const
{
  return coefs[ind];
}

/* Polynomial degree getting function
 * ARGUMENTS: None
 * RETURNS:
 *   (size_t) Degree
 */
size_t Polynom::GetDegree( void ) const
{
  return degree;
}

/* Greatest common divider of polynomials fiding function
 * ARGUMENTS:
 *  - Polynomials:
 *      const Polynom &left, const Polynom &right;
 * RETURNS:
 *   (Polynom) GCD
 */
const Polynom GCD( const Polynom &left, const Polynom &right )
{
  if (left.GetDegree() == 0 && left[0] == zero)
    return right;
  else if (left.GetDegree() == 0 && left[0] == zero)
    return left;
  if (left.GetDegree() == 0 && right.GetDegree() == 0)
  {
    Rational r = RED_Q_Q(right[0]), l = RED_Q_Q(left[0]);
    if (l.GetDen() == 1 && r.GetDen() == 1)
        return Polynom({TRANS_Z_Q(GCD(TRANS_Q_Z(l), TRANS_Q_Z(r)))});
  }
  Polynom newLeft = left / FAC(left), newRight = right / FAC(right), tmp;
  if (right.GetDegree() > left.GetDegree())
  {
    newLeft = right;
    newRight = left;
  }
  Polynom rem;
  while ((rem = newLeft % newRight).GetDegree() > 0)
  {
    tmp = newLeft;
    newLeft = newRight;
    newRight = tmp % newRight;
  }

  if (rem.GetDegree() == 0 && !(rem[0] == zero))
    return Polynom({rem[0]});

  return newRight;
}

/* Polynomial degree getting function
 * ARGUMENTS: None
 * RETURNS: 
 *   (Rational) Coefficient
 */
Rational Polynom::LeadCoef( void ) const
{
  return coefs[degree];
}

/* Coeffsicients GCD/LCM finding function
 * ARGUMENTS:
 *  - Polynomial:
 *      const Polynom &p;
 * RETURNS:
 *   (Rational) GCD/LCM
 */
Rational FAC( const Polynom &p )
{
  BigNatural gcdnum = ABS_Z_N(p[0].GetNum()), gcdden = 1, lcmden = p[0].GetDen();
  if (p.GetDegree() == 0)
    return p[0];
  for (size_t i = 0; i <= p.GetDegree(); i++)
  {
    gcdnum = GCD(gcdnum, ABS_Z_N(p[i].GetNum()));
    lcmden = LCM(lcmden, p[i].GetDen());
  }

  return RED_Q_Q(Rational(gcdnum, lcmden));
}

/* Polynomial derivative finding function
 * ARGUMENTS:
 *  - Polynomial:
 *      const Polynom &p;
 * RETURNS:
 *   (Polynom) Deriative
 */
const Polynom DER( const Polynom &p )
{
  std::vector<Rational> dep;

  if (p.GetDegree() == 0)
    return Polynom({zero});
  else
  {
    dep.reserve(p.GetDegree());
    for (size_t i = 1; i <= p.GetDegree(); i++)
      dep.push_back(p[i] * Rational(i, 1));
    return Polynom(dep);
  }
}

/* Converting multiple roots to simple function
 * ARGUMENTS:
 *  - Polynomial:
 *      const Polynom &p;
 * RETURNS:
 *   (Polynom) Result
 */
const Polynom NMR( Polynom p )
{
  if (p.GetDegree() == 0)
    return p;
  Polynom gcd = GCD(p, DER(p));
  if (gcd.GetDegree() == 0)
    return p;
  return p /= GCD(p, DER(p));
}

Polynom &operator+=( Polynom &left, const Polynom &right )
{
  if (right.degree > left.degree)
  {
    left.coefs.resize(right.degree + 1);
    left.degree = right.degree;
  }
  for (size_t i = 0; i <= fmin(left.degree, right.degree); i++)
    left.coefs[i] += right.coefs[i];
  left.Optimize();
  
  return left;
}

const Polynom operator+( Polynom left, const Polynom &right )
{
  return left += right;
}

const Polynom operator+( const Polynom &p )
{
  return p;
}

Polynom &operator-=( Polynom &left, const Polynom &right )
{
  if (right.degree > left.degree)
  {
    left.coefs.resize(right.degree + 1, zero);
    left.degree = right.degree;
  }
  for (size_t i = 0; i <= fmin(left.degree, right.degree); i++)
    left.coefs[i] -= right.coefs[i];
  left.Optimize();

  return left;
}

const Polynom operator-( Polynom left, const Polynom &right )
{
  return left -= right;
}

const Polynom operator-( const Polynom &p )
{
  return p * (-1);
}

Polynom &operator*=( Polynom &p, Rational num )
{
  for (size_t i = 0; i <= p.degree; i++)
    p.coefs[i] *= num;
  p.Optimize();
  
  return p;
}

const Polynom operator*( Polynom p, Rational num )
{
  return p *= num;
}

Polynom &operator/=( Polynom &p, Rational num )
{
  for (size_t i = 0; i <= p.degree; i++)
    p.coefs[i] /= num;
  p.Optimize();

  return p;
}

const Polynom operator/( Polynom p, Rational num )
{
  return p /= num;
}

/* Polynomial by x^k multiplying function
 * ARGUMENTS:
 *   - x degree:
 *       size_t degree;
 * RETURNS:
 *   (Polynom) Multiplying result
 */
Polynom MulByMono( const Polynom &p, size_t degree )
{
  Polynom res(p);

  if (degree == 0)
    return p;
  if (degree < 0)
    throw std::runtime_error("Negative degrees are not supported");
  res.coefs.resize(res.degree + degree + 1, zero);
  std::rotate(res.coefs.begin(), res.coefs.begin() + res.degree + 1, res.coefs.end());

  res.Optimize();

  return res;
}

Polynom &operator*=( Polynom &left, const Polynom &right )
{
  Polynom res(left.degree + 1);

  for (size_t i = 0; i <= right.degree; i++)
    res += MulByMono(left * right.coefs[i], i);
  res.Optimize();

  return left = res;
}

const Polynom operator*( Polynom left, const Polynom &right )
{
  return left *= right;
}

Polynom &operator/=( Polynom &left, const Polynom &right )
{
  Polynom res;

  if (right.degree == 0 && right.coefs[0] == zero)
    throw std::runtime_error("Division by zero");
  if (left.degree < right.degree)
  {
    left.coefs.resize(1, zero);
    left.coefs = {zero};
    left.degree = 0;
    return left;
  }

  res = Polynom(left.degree - right.degree + 1);
  while (left.degree >= right.degree && !(left.degree == 0 && left.coefs[0] == zero))
  {
    size_t curdeg = left.degree - right.degree;
    Rational curcoef = left.LeadCoef() / right.LeadCoef();

    res.coefs[curdeg] = curcoef;
    left -= MulByMono(right * curcoef, curdeg); 
    left.Optimize();
  }

  return left = res;
}

const Polynom operator/( Polynom left, const Polynom &right )
{
  return left /= right;
}

Polynom &operator%=( Polynom &left, const Polynom &right )
{
  if (left.degree == 0 && right.degree == 0)
  {
    Rational r = RED_Q_Q(right[0]), l = RED_Q_Q(left[0]);
    if (l.GetDen() == 1 && r.GetDen() == 1)
      return left = Polynom({TRANS_Z_Q(TRANS_Q_Z(l) % TRANS_Q_Z(r))});
    throw std::runtime_error("Impossible to divide with remainder");
  }
  if (right.degree == 0 && right.coefs[0] == zero)
    throw std::runtime_error("Division by zero");
  else if (right.degree == 0)
    return left = Polynom({zero});
  if (left.degree < right.degree)
    return left;

  while (left.degree >= right.degree)
  {
    size_t curdeg = left.degree - right.degree;
    Rational curcoef = left.LeadCoef() / right.LeadCoef();

    left -= MulByMono(right * curcoef, curdeg);
    left.Optimize();
  }

  return left;
}

const Polynom operator%( Polynom left, const Polynom &right )
{
  return left %= right;
}

std::ostream& operator <<(std::ostream& os, const Polynom& x)
{
  for (size_t i = x.coefs.size(); i > 0; i--)
  {
    i--;
    if (!(x.coefs[i] == zero) && i != 0)
    { 
      if (i >= 1 && i < x.coefs.size() - 1 && x.coefs[i] > zero)
        os << "+";
      if (!(x.coefs[i] == Rational(1)))
        os << x.coefs[i];
      os << "x";
      if (i != 1)
        os << "^" << i;
    }
    if (i == 0)
    {
      if (x.coefs[i] == zero)
      {
        if (x.coefs.size() == 1)
          os << 0;
      }
      else
      {
        if (x.coefs[i] >= zero && x.coefs.size() > 1)
          os << "+";
        os << x.coefs[0];
      } 
    }
    i++;
  }

  return os;
}


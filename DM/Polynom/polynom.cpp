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
Polynom::Polynom( int length ) : degree(length - 1)
{
  coefs.resize(length, Rational(0, 1));
}

/* Polynom constructor from coefficients
 * ARGUMENTS:
 *   - coefficients vector:
 *       const std::vector<Rational> &coefs;
 */
Polynom::Polynom( const std::vector<Rational> &coefs ) : degree((int)coefs.size() - 1), coefs(coefs)
{
  if (coefs.size() > 30)
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
  bool leftv = true, isok = true, firstdone = false; 
  char ch = 0;
  std::string num1, num2 = {"/1"};

  if (expr.size() == 0)
  {
    degree = 1;
    coefs = {zero};
  }
  for (int i = 0; i < expr.size(); i++)
  {
    ch = expr[i];
    if (ch == ' ')
      continue;
    else if (ch == ',')
    {
      coefs.push_back(Rational(std::string(num1 + num2)));
      firstdone = false;
      num1.clear();
      num2.clear();
      num2 = {"/1"};
    }
    else if (ch == '-' || ch == '/' || (ch <= '9' && ch >= '0'))
    {
      if (!firstdone)
      {
        if (ch == '/')
          throw std::runtime_error("Missing the numerator");
        if (num1.size() != 0)
          throw std::runtime_error("Wrong syntax");
        num1.push_back(ch);
        ch = expr[++i];
        while (ch <= '9' && ch >= '0')
        {
          num1.push_back(ch);
          ch = expr[++i];
        }
        i--;
        firstdone = true;
      }
      else if (num1.size() > 0 && ch != '-')
      {
        num2.clear();
        num2.push_back(ch);
        ch = expr[++i];
        while (ch <= '9' && ch >= '0')
        {
          num2.push_back(ch);
          ch = expr[++i];
        }
        i--;
        firstdone = false;
      }
      else
        throw std::runtime_error("Wrong symbol");
    }
  }
  if (num1.size() > 0)
    coefs.push_back(Rational(std::string(num1 + num2)));
  Optimize();
}

/* Polynomial simplifying function
 * ARGUMENTS: None
 * RETURNS: None
 */
void Polynom::Optimize( void )
{
  int cur = (int)coefs.size() - 1;

  if (coefs[cur] == zero)
  {
    while (coefs[cur] == zero && cur > 0)
      cur--;
    coefs.resize(size_t(cur) + 1);
  }
  degree = (int)coefs.size() - 1;
}

/* Polynomial coefficient getting function
 * ARGUMENTS:
 *   - Position:
 *       int pos;
 * RETURNS:
 *   (Rational) Coefficient
 */
Rational Polynom::operator[]( int ind ) const
{
  return coefs[ind];
}

/* Polynomial degree getting function
 * ARGUMENTS: None
 * RETURNS:
 *   (int) Degree
 */
size_t Polynom::GetDegree( void ) const
{
  return degree;
}

const Polynom GCD( const Polynom &left, const Polynom &right )
{
  if (left.GetDegree() == 0 && left[0] == zero)
    return right;
  else if (left.GetDegree() == 0 && left[0] == zero)
    return left;
  Rational r = RED_Q_Q(right[0]), l = RED_Q_Q(left[0]);
  if (l.GetDen() == 1 && r.GetDen() == 1)
      return Polynom({TRANS_Z_Q(GCD(TRANS_Q_Z(l), TRANS_Q_Z(r)))});
  Polynom newLeft = left, newRight = right, tmp;
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
 *   (Rational) Degree
 */
Rational Polynom::LeadCoef( void ) const
{
  return coefs[degree];
}

Rational FAC( const Polynom &p )
{
  BigNatural gcdnum = ABS_Z_N(p[0].GetNum()), gcdden = p[0].GetDen(), lcmden = 1;
  for (int i = 0; i <= p.GetDegree(); i++)
  {
    gcdnum = GCD(gcdnum, ABS_Z_N(p[i].GetNum()));
    gcdden = GCD(gcdden, p[i].GetDen());
    lcmden *= p[i].GetDen();
  }
  lcmden /= gcdden;

  return Rational(gcdnum, lcmden);
}

const Polynom DER( const Polynom &p )
{
  std::vector<Rational> dep;

  if (p.GetDegree() == 0)
    return Polynom({zero});
  else
  {
    dep.reserve(p.GetDegree());
    for (int i = 1; i <= p.GetDegree(); i++)
      dep.push_back(p[i] * Rational(i, 1));
    return Polynom(dep);
  }
}

const Polynom NMR( Polynom p )
{
  if (p.GetDegree() == 0)
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
  for (int i = 0; i <= fmin(left.degree, right.degree); i++)
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
  for (int i = 0; i <= fmin(left.degree, right.degree); i++)
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
  for (int i = 0; i <= p.degree; i++)
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
  for (int i = 0; i <= p.degree; i++)
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
 *       int degree;
 * RETURNS:
 *   (Polynom) Multiplying result
 */
Polynom MulByMono( const Polynom &p, int degree )
{
  Polynom res(p);

  if (degree == 0)
    return p;
  if (degree < 0)
    throw std::runtime_error("Negative degrees are not supported");
  res.coefs.resize(size_t(res.degree) + degree + 1, zero);
  std::rotate(res.coefs.begin(), res.coefs.begin() + res.degree + 1, res.coefs.end());

  res.Optimize();

  return res;
}

Polynom &operator*=( Polynom &left, const Polynom &right )
{
  Polynom res(left.degree + 1);

  for (int i = 0; i <= right.degree; i++)
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
    left.degree = 0;
    return left;
  }

  res = Polynom(left.degree - right.degree + 1);
  while (left.degree >= right.degree && !(left.degree == 0 && left.coefs[0] == zero))
  {
    int curdeg = left.degree - right.degree;
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
    throw std::runtime_error("Impossible to divide with reminder");
  }
  if (right.degree == 0 && right.coefs[0] == zero)
    throw std::runtime_error("Division by zero");
  else if (right.degree == 0)
    return left = Polynom({zero});
  if (left.degree < right.degree)
    return left;

  while (left.degree >= right.degree)
  {
    int curdeg = left.degree - right.degree;
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
  for (int i = (int)x.coefs.size() - 1; i >= 0; i--)
  {
    if (!(x.coefs[i] == zero) && i != 0)
    { 
      if (i >= 1 && i < (int)x.coefs.size() - 1 && x.coefs[i] > zero)
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
  }

  return os;
}


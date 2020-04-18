#include "__BigNatural.h"

const BigNatural operator +(BigNatural left, const BigNatural& right)
{
    left += right;
    return left;
}
const BigNatural operator -(BigNatural left, const BigNatural& right)
{
    left -= right;
    return left;
}
const BigNatural operator *(BigNatural left, const BigNatural& right)
{
    left *= right;
    return left;
}
const BigNatural operator /(BigNatural left, const BigNatural& right)
{
    left /= right;
    return left;
}
const BigNatural operator %(BigNatural left, const BigNatural& right)
{
    left %= right;
    return left;
}
std::ostream& operator <<(std::ostream& os, const BigNatural& x)
{
    os << x.num;
    return os;
}

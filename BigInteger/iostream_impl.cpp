#include <iostream>
#include "BigInteger.h"

std::ostream& operator <<(std::ostream& os, const BigInteger& x)
{
    x.isPositive ? os << "" : os << "-";
    os << x.number;
    return os;
}

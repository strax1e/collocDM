#ifndef IOSTREAM_IMPL_H_INCLUDED
#define IOSTREAM_IMPL_H_INCLUDED

#include <iostream>

template < typename T >
inline std::ostream& operator <<(std::ostream& os, const BigInteger<T>& x)
{
    x.sign ? os << "" : os << "-";
    os << x.number;
    return os;
}


#endif // IOSTREAM_IMPL_H_INCLUDED

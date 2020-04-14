#ifndef IOSTREAM_IMPL_H_INCLUDED
#define IOSTREAM_IMPL_H_INCLUDED

#include <iostream>

template < typename T >
inline std::ostream& operator <<(std::ostream& os, const Big_Integer<T>& x)
{
    x._sign ? os << "" : os << "-";
    os << x._number;
    return os;
}


#endif // IOSTREAM_IMPL_H_INCLUDED

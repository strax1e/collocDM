#include "Big_Integer.hpp"

inline std::ostream& operator <<(std::ostream& os, const Big_Integer& x)
{
//    x._sign ? os << "+" : os << "-";
    os << x._number;
    return os;
}

#include "Big_Integer.hpp"

Big_Integer& Big_Integer::operator ++()
{
    if (_sign)
        _number++;
    else
        _number--;

    if (_number == 0)
        _sign = true;

    return *this;
}
Big_Integer Big_Integer::operator ++(int)
{
    Big_Integer copy(*this);
    if (_sign)
        _number++;
    else
        _number--;

    if (_number == 0)
        _sign = true;

    return copy;
}
Big_Integer& Big_Integer::operator --()
{
    if (_sign)
        _number--;
    else
        _number++;

    if (_number < 0)
        _sign = false;

    return *this;
}
Big_Integer Big_Integer::operator --(int)
{
    Big_Integer copy(*this);
    if (_sign)
        _number--;
    else
        _number++;

    if (_number < 0)
        _sign = false;

    return copy;
}

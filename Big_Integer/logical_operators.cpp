#include "Big_Integer.hpp"

bool Big_Integer::operator ==(const Big_Integer& other) const
{
    return _number == other._number;
}
bool Big_Integer::operator !=(const Big_Integer& other) const
{
    return _number != other._number;
}
bool Big_Integer::operator > (const Big_Integer& other) const
{
    return _number > other._number;
}
bool Big_Integer::operator < (const Big_Integer& other) const
{
    return _number < other._number;
}
bool Big_Integer::operator >=(const Big_Integer& other) const
{
    return _number >= other._number;
}
bool Big_Integer::operator <=(const Big_Integer& other) const
{
    return _number <= other._number;
}

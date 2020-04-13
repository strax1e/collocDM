#include <iostream>
#include "Big_Integer.hpp"

const Big_Integer operator +(Big_Integer left, const Big_Integer& right)
{
    left += right;
    return left;
}
const Big_Integer operator -(Big_Integer left, const Big_Integer& right)
{
    left -= right;
    return left;
}
const Big_Integer operator *(Big_Integer left, const Big_Integer& right)
{
    left *= right;
    return left;
}
const Big_Integer operator /(Big_Integer left, const Big_Integer& right)
{
    left /= right;
    return left;
}
const Big_Integer operator %(Big_Integer left, const Big_Integer& right)
{
    left %= right;
    return left;
}

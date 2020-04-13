#include <iostream>
#include <exception>
#include "Big_Integer.hpp"

Big_Integer& Big_Integer::Big_Integer::operator +=(const Big_Integer& other)
{
    if (_sign == other._sign)
        _number += other._number;
    else
    {
        if (_number >= other._number)
            _number -= other._number;
        else
        {
            _sign = !_sign;
            Big_Natural n(std::move(_number));
            _number = other._number;
            _number -= n;
        }
    }
    return *this;
}
Big_Integer& Big_Integer::Big_Integer::operator -=(const Big_Integer& other)
{
    if (_sign != other._sign)
        _number += other._number;
    else
    {
        if (_number >= other._number)
            _number -= other._number;
        else
        {
            _sign = !_sign;
            Big_Natural n(std::move(_number));
            _number = other._number;
            _number -= n;
        }
    }
    return *this;
}
Big_Integer& Big_Integer::Big_Integer::operator *=(const Big_Integer& other)
{
    _sign = _sign == other._sign ? true : false;
    _number *= other._number;
    return *this;
}
Big_Integer& Big_Integer::operator *=(int num) // -9 <= num <= 9
{
    if (std::abs(num) % 10 != 0)
        throw std::runtime_error("ERROR: multiplying by num(abs(num) % 10 != 0)");

    _sign = _sign == num > 0 ? true : false;
    _number *= std::abs(num);
    return *this;
}
Big_Integer& Big_Integer::Big_Integer::operator /=(const Big_Integer& other)
{
    throw std::runtime_error("featch not realised: Big_Integer()");
    //return *this;
}
Big_Integer& Big_Integer::Big_Integer::operator %=(const Big_Integer& other)
{
    throw std::runtime_error("featch not realised: Big_Integer()");
    //return *this;
}

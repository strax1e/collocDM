#include <iostream>
#include <exception>
#include "Big_Integer.hpp"

Big_Integer::Big_Integer()
{
    throw std::runtime_error("featch not realised: Big_Integer()");
}
Big_Integer::Big_Integer(const Big_Integer& x): _sign(x._sign), _number(x._number){}
Big_Integer::Big_Integer(Big_Integer&& x): _sign(x._sign), _number(std::move(x._number)){}
Big_Integer::Big_Integer(const std::string& x)
{
    throw std::runtime_error("featch not realised: Big_Integer(const std::string&)");
}
Big_Integer::Big_Integer(const Big_Natural& n): _sign(true), _number(n){}
Big_Integer::Big_Integer(Big_Natural&& n): _sign(true), _number(std::move(n)){}
Big_Integer& Big_Integer::operator =(const Big_Integer& x)
{
    _sign = x._sign;
    _number = x._number;
}
Big_Integer& Big_Integer::operator =(Big_Integer&& x)
{
    _sign = x._sign;
    _number = std::move(x._number);
}
Big_Integer::~Big_Integer(){}




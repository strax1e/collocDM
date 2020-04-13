#ifndef BIG_INTEGER_HPP_INCLUDED
#define BIG_INTEGER_HPP_INCLUDED

#include <string>

//class Big_Natural{};
typedef unsigned short Big_Natural;

inline std::ostream& operator <<(std::ostream& os, const Big_Natural& x)
{
    //os << "big natural value\n";
    return os;
}

class Big_Integer
{
public:
    Big_Integer();
    Big_Integer(const Big_Integer&);
    Big_Integer(Big_Integer&&);

    Big_Integer(const std::string&);
    Big_Integer(const Big_Natural&);
    Big_Integer(Big_Natural&&);

    ~Big_Integer();

    Big_Integer& operator =(const Big_Integer&);
    Big_Integer& operator =(Big_Integer&&);

    bool operator ==(const Big_Integer&) const;
	bool operator !=(const Big_Integer&) const;
	bool operator > (const Big_Integer&) const;
	bool operator < (const Big_Integer&) const;
	bool operator >=(const Big_Integer&) const;
	bool operator <=(const Big_Integer&) const;

    Big_Integer& operator +=(const Big_Integer&);
    Big_Integer& operator -=(const Big_Integer&);
    Big_Integer& operator *=(const Big_Integer&);
    Big_Integer& operator *=(int);
    Big_Integer& operator /=(const Big_Integer&);
    Big_Integer& operator %=(const Big_Integer&);

    Big_Integer& operator ++();
    Big_Integer  operator ++(int);
    Big_Integer& operator --();
    Big_Integer  operator --(int);

    friend const Big_Integer operator +(Big_Integer, const Big_Integer&);
    friend const Big_Integer operator -(Big_Integer, const Big_Integer&);
    friend const Big_Integer operator *(Big_Integer, const Big_Integer&);
    friend const Big_Integer operator /(Big_Integer, const Big_Integer&);
    friend const Big_Integer operator %(Big_Integer, const Big_Integer&);

    friend inline std::ostream& operator <<(std::ostream& os, const Big_Integer& x);

private:
    bool _sign; // true -> number >= 0
    Big_Natural _number;
};


#endif // BIG_INTEGER_HPP_INCLUDED

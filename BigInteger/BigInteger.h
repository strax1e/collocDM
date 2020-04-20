#ifndef BigInteger_H_INCLUDED
#define BigInteger_H_INCLUDED

#include <string>
#include "__BigNatural.h"

class BigInteger
{
public:
    BigInteger();
    BigInteger(const BigInteger&);
    BigInteger(BigInteger&&);

    BigInteger(const std::string&);
    BigInteger(const BigNatural&);
    BigInteger(BigNatural&&);
    BigInteger(long long);

    BigInteger& operator =(const BigInteger&);
    BigInteger& operator =(BigInteger&&);
    BigInteger& operator =(const BigNatural&);
    BigInteger& operator =(BigNatural&&);

    ~BigInteger();

    bool operator ==(const BigInteger&) const;
	bool operator !=(const BigInteger&) const;
	bool operator > (const BigInteger&) const;
	bool operator < (const BigInteger&) const;
	bool operator >=(const BigInteger&) const;
	bool operator <=(const BigInteger&) const;

	bool isNegative() const { return !isPositive; }
	bool isZero() const { return number == BigNatural(0); }

//	bool operator ==(int) const; // == 0
//	bool operator !=(int) const; // != 0
//	bool operator > (int) const; //  > 0
//	bool operator < (int) const; //  < 0
//	bool operator >=(int) const; // >= 0
//	bool operator <=(int) const; // <= 0

    BigInteger& operator +=(const BigInteger&);
    BigInteger& operator -=(const BigInteger&);
    BigInteger& operator *=(const BigInteger&);
    BigInteger& operator *=(int); // *= n, -9 <= n <= 9
    BigInteger& operator /=(const BigInteger&);
    BigInteger& operator %=(const BigInteger&);

    BigInteger& operator ++();
    BigInteger  operator ++(int);
    BigInteger& operator --();
    BigInteger  operator --(int);

    friend const BigInteger operator +(BigInteger, const BigInteger&);
    friend const BigInteger operator -(BigInteger, const BigInteger&);
    friend const BigInteger operator *(BigInteger, const BigInteger&);
    friend const BigInteger operator /(BigInteger, const BigInteger&);
    friend const BigInteger operator %(BigInteger, const BigInteger&);
    friend std::ostream& operator <<(std::ostream&, const BigInteger&);

    BigNatural getNatural() const & {BigNatural copy(number); return copy;}
    BigNatural&& getNatural() && {return std::move(number);}

private:
    bool isPositive; // true -> number >= 0
    BigNatural number;
};

#endif // BigInteger_H_INCLUDED

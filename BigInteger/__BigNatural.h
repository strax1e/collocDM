#ifndef __BIGNATURAL_H_INCLUDED
#define __BIGNATURAL_H_INCLUDED

#include <string>
#include <sstream>
#include <iostream>

class BigNatural
{
public:
    BigNatural(): num(0){}
    BigNatural(const BigNatural& other): num(other.num){/*std::cout << "copy\n";*/}
    BigNatural(BigNatural&& other): num(other.num){/*std::cout << "move\n";*/}

    BigNatural(const std::string& s): num(std::stoll(s)){}
    BigNatural(unsigned long long n): num(n){}

    BigNatural& operator =(const BigNatural& other) {num = other.num; return *this;}
    BigNatural& operator =(BigNatural&& other) {num = other.num; return *this;}

    ~BigNatural(){}

    bool operator ==(const BigNatural& other) const{return num == other.num;}
	bool operator !=(const BigNatural& other) const{return num != other.num;}
	bool operator > (const BigNatural& other) const{return num >  other.num;}
	bool operator < (const BigNatural& other) const{return num <  other.num;}
	bool operator >=(const BigNatural& other) const{return num >= other.num;}
	bool operator <=(const BigNatural& other) const{return num <= other.num;}

//	bool operator ==(int n) const; // == 0
//	bool operator !=(int n) const; // != 0
//	bool operator > (int n) const; //  > 0
//	bool operator < (int n) const; //  < 0
//	bool operator >=(int n) const; // >= 0
//	bool operator <=(int n) const; // <= 0

    BigNatural& operator +=(const BigNatural& other) {num += other.num; return *this;}
    BigNatural& operator -=(const BigNatural& other) {num -= other.num; return *this;}
    BigNatural& operator *=(const BigNatural& other) {num *= other.num; return *this;}
    BigNatural& operator *=(unsigned int n) {num *= n; return *this;}
    BigNatural& operator /=(const BigNatural& other) {num /= other.num; return *this;}
    BigNatural& operator %=(const BigNatural& other) {num %= other.num; return *this;}

    BigNatural& operator ++() {num++; return *this;}
    BigNatural  operator ++(int) {BigNatural copy(*this); num++; return copy; }
    BigNatural& operator --() {num--; return *this;}
    BigNatural  operator --(int) {BigNatural copy(*this); num--; return copy; }

    friend const BigNatural operator +(BigNatural left, const BigNatural& right);
    friend const BigNatural operator -(BigNatural left, const BigNatural& right);
    friend const BigNatural operator *(BigNatural left, const BigNatural& right);
    friend const BigNatural operator /(BigNatural left, const BigNatural& right);
    friend const BigNatural operator %(BigNatural left, const BigNatural& right);
    friend std::ostream& operator <<(std::ostream&, const BigNatural&);

private:
    unsigned long long num;
};

#endif // __BIGNATURAL_H_INCLUDED

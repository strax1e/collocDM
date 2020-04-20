#ifndef STANDART_FUNCTIONS_H_INCLUDED
#define STANDART_FUNCTIONS_H_INCLUDED

class BigInteger;
class BigNatural;

template < typename T >
BigNatural ABS_Z_N(T&&);

template < typename T >
BigInteger TRANS_N_Z(T&&);

template < typename T >
BigNatural TRANS_Z_N(T&&);

int POZ_Z_D(const BigInteger&);

void MUL_ZM_Z(BigInteger&);

BigInteger ADD_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger SUB_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger MUL_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger DIV_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger MOD_ZZ_Z(const BigInteger&, const BigInteger&);

#endif // STANDART_FUNCTIONS_H_INCLUDED

#ifndef STANDART_FUNCTIONS_H_INCLUDED
#define STANDART_FUNCTIONS_H_INCLUDED

#include "Polynom/polynom.h"

/*** BIG NATURAL ***/
int COM_NN_D(const BigNatural &left, const BigNatural &right);
bool NZER_N_B(const BigNatural &x);
BigNatural ADD_1N_N(BigNatural x);
BigNatural ADD_NN_N(BigNatural left, const BigNatural &right);
BigNatural SUB_NN_N(BigNatural left, const BigNatural &right);
///BigNatural MUL_ND_N(BigNatural left, int digit);
BigNatural MUL_Nk_N(BigNatural left, long long k);
BigNatural MUL_NN_N(BigNatural left, const BigNatural &right);
BigNatural SUB_NDN_N(BigNatural left, int digit, const BigNatural &right);
///DIV_NN_Dk
BigNatural DIV_NN_N(BigNatural left, const BigNatural &right);
BigNatural MOD_NN_N(BigNatural left, const BigNatural &right);
BigNatural GCF_NN_N(BigNatural left, const BigNatural &right);
BigNatural LCM_NN_N(BigNatural left, const BigNatural &right);

/*** BIG INTEGER ***/
BigNatural ABS_Z_N(const BigInteger &x);
BigInteger TRANS_N_Z(const BigNatural &x);
BigNatural TRANS_Z_N(const BigInteger &x);
int POZ_Z_D(const BigInteger& x);
void MUL_ZM_Z(BigInteger& x);
BigInteger ADD_ZZ_Z(const BigInteger& left, const BigInteger& right);
BigInteger SUB_ZZ_Z(const BigInteger& left, const BigInteger& right);
BigInteger MUL_ZZ_Z(const BigInteger& left, const BigInteger& right);
BigInteger DIV_ZZ_Z(const BigInteger& left, const BigInteger& right);
BigInteger MOD_ZZ_Z(const BigInteger& left, const BigInteger& right);

/*** RATIONAL ***/
Rational RED_Q_Q(const Rational &r);
bool INT_Q_B(Rational& r);
Rational TRANS_Z_Q(BigInteger i);
BigInteger TRANS_Q_Z( Rational r);
Rational ADD_QQ_Q(Rational first, Rational const& second);
Rational SUB_QQ_Q(Rational first, Rational const& second);
Rational MUL_QQ_Q(Rational first, Rational const& second);
Rational DIV_QQ_Q(Rational first, Rational const& second);

/*** POLYNOM ***/
Polynom ADD_PP_P(Polynom left, const Polynom &right);
Polynom SUB_PP_P(Polynom left, const Polynom &right);
Polynom MUL_PQ_P(Polynom left, const Rational &right);
Polynom MUL_Pxk_P(Polynom left, int k);
Rational LED_P_Q(const Polynom &p);
BigNatural DEG_P_N(const Polynom &p);
Rational FAC_P_Q(const Polynom &p);
Polynom MUL_PP_P(Polynom left, const Polynom &right);
Polynom DIV_PP_P(Polynom left, const Polynom &right);
Polynom MOD_PP_P(Polynom left, const Polynom &right);
Polynom GCF_PP_P(const Polynom &left, const Polynom &right);
Polynom DER_P_P(const Polynom &p);
Polynom NMR_P_P(const Polynom &p);

#endif // STANDART_FUNCTIONS_H_INCLUDED

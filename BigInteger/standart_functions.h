#ifndef STANDART_FUNCTIONS_H_INCLUDED
#define STANDART_FUNCTIONS_H_INCLUDED

class BigInteger;
class BigNatural;

// Возвращает модуль целого числа
template < typename T >
BigNatural ABS_Z_N(T&&);

// Создает целое число на основе переданного натурального
template < typename T >
BigInteger TRANS_N_Z(T&&);

// Возвращает натуральное число на основе переданного целого
// Не позволяет создать натуральное число из целого
template < typename T >
BigNatural TRANS_Z_N(T&&);

// Определят принадлежность числа к положительным, отрицательным или нулю
// 0 - число равно нулю
// 1 - число отрицательно
// 2 - число положительно
int POZ_Z_D(const BigInteger&);

// Производит умножение переданного целого числа на -1
void MUL_ZM_Z(BigInteger&);

// Арифметические операции над целыми числами - сложение, вычитание, умножение и деление
BigInteger ADD_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger SUB_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger MUL_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger DIV_ZZ_Z(const BigInteger&, const BigInteger&);
BigInteger MOD_ZZ_Z(const BigInteger&, const BigInteger&);

#endif // STANDART_FUNCTIONS_H_INCLUDED

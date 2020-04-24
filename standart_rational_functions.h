#ifndef STANDART_RATIONAL_FUNCTIONS_H
#define STANDART_RATIONAL_FUNCTIONS_H

#include "Rational.h"
#include "standart_functions.h"


    inline Rational& RED_Q_Q(const Rational &r)
    {
        bool flag = false;
        Rational new_r = r;
        if (new_r.num < 0)
        {
            flag = true;
        }
        BigNatural new_r_num = ABS_Z_N(new_r.num);
        BigNatural nod = GCD(new_r_num, new_r.den);
        new_r.num = new_r_num / nod;
        if (flag)
        {
            new_r.num = new_r.num * -1;
        }
        new_r.den = new_r.den / nod;
        return new_r;
    }

    inline bool INT_Q_B(Rational& r)
    {
        if (RED_Q_Q(r).den == 1)
        {
            return true;
        }
        else return false;
    }

    inline Rational TRANS_Z_Q(BigInteger i)
    {
        
        Rational r(i, 1);

        return r;
    }

    inline BigInteger TRANS_Q_Z( Rational r)
    {
        if (r.den == 1)
        {
            return r.num;
        }
        else
        {
            throw invalid_argument("something");
        }
    }


    inline const Rational ADD_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first + second);
    }

    inline const Rational SUB_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first - second);
    }

    inline const Rational MUL_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first * second);
    }

    inline const Rational DIV_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first / second);
    }


#endif // STANDART_RATIONAL_FUNCTIONS_H
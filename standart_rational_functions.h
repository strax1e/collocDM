
#include "Rational.h"
#include "standart_functions.h"


    Rational& RED_Q_Q(const Rational &r)
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

    bool INT_Q_B(Rational& r)
    {
        if (RED_Q_Q(r).den == 1)
        {
            return true;
        }
        else return false;
    }

    Rational TRANS_Z_Q(BigInteger i)
    {
        
        Rational r(i, 1);

        return r;
    }

    BigInteger TRANS_Q_Z( Rational r)
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


    const Rational ADD_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first + second);
    }

    const Rational SUB_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first - second);
    }

    const Rational MUL_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first * second);
    }

    const Rational DIV_QQ_Q(Rational first, Rational const& second)
    {
        return RED_Q_Q(first / second);
    }
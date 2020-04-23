#include <iostream>
#include <string>
#include "../BigInteger/BigInteger.h"
#include "../BigInteger/standart_functions.h"
#include "../BigInteger/__BigNatural.h"

#define FIRST_STATE 1

#define NATURAL 2
#define INTEGER 3
#define RATIONAL 4
#define POLINOM 5

#define OPERATION_NATURAL 6
#define OPERATION_INTEGER 7
#define OPERATION_RATIONAL 8
#define OPERATION_POLINOM 9

void printSetOfNumbers()
{
    std::cout << "Choose variant of number:\n";
    std::cout << "0) Close\n";
    std::cout << "1) Natural number\n";
    std::cout << "2) Integer number\n";
    std::cout << "3) Rational number\n";
    std::cout << "4) Polinom\n";
}
void printSetOfNaturalOperations()
{
    std::cout << "Choose variant of operation:\n";
    std::cout << "0)  Go to the previous state\n";
    std::cout << "1)  COM_NN_D\n";
    std::cout << "2)  NZER_N_B\n";
    std::cout << "3)  ADD_1N_N\n";
    std::cout << "4)  ADD_NN_N\n";
    std::cout << "5)  SUB_NN_N\n";
    std::cout << "6)  MUL_ND_N\n";
    std::cout << "7)  MUL_Nk_N\n";
    std::cout << "8)  MUL_NN_N\n";
    std::cout << "9)  SUB_NDN_N\n";
    std::cout << "10) DIV_NN_Dk\n";
    std::cout << "11) DIV_NN_N\n";
    std::cout << "12) MOD_NN_N\n";
    std::cout << "13) GCF_NN_N\n";
    std::cout << "14) LCM_NN_N\n";
}
void printSetOfIntegerOperations()
{
    std::cout << "Choose variant of operation:\n";
    std::cout << "0)  Go to the previous state\n";
    std::cout << "1)  ABS_Z_N\n";
    std::cout << "2)  POZ_Z_D\n";
    std::cout << "3)  MUL_ZM_Z\n";
    std::cout << "4)  TRANS_N_Z\n";
    std::cout << "5)  TRANS_Z_N\n";
    std::cout << "6)  ADD_ZZ_Z\n";
    std::cout << "7)  SUB_ZZ_Z\n";
    std::cout << "8)  MUL_ZZ_Z\n";
    std::cout << "9)  DIV_ZZ_Z\n";
    std::cout << "10) MOD_ZZ_Z\n";
}
void printSetOfRationalOperations()
{
    std::cout << "Choose variant of operation:\n";
    std::cout << "0) Go to the previous state\n";
    std::cout << "1) RED_Q_Q\n";
    std::cout << "2) INT_Q_B\n";
    std::cout << "3) TRANS_Z_Q\n";
    std::cout << "4) TRANS_Q_Z\n";
    std::cout << "5) ADD_QQ_Q\n";
    std::cout << "6) SUB_QQ_Q\n";
    std::cout << "7) MUL_QQ_Q\n";
    std::cout << "8) DIV_QQ_Q\n";
}
void printSetOfPolinomOperations()
{
    std::cout << "Choose variant of operation:\n";
    std::cout << "0)  Go to the previous state\n";
    std::cout << "1)  ADD_PP_P\n";
    std::cout << "2)  SUB_PP_P\n";
    std::cout << "3)  MUL_PQ_P\n";
    std::cout << "4)  MUL_Pxk_P\n";
    std::cout << "5)  LED_P_Q\n";
    std::cout << "6)  DEG_P_N\n";
    std::cout << "7)  FAC_P_Q\n";
    std::cout << "8)  MUL_PP_P\n";
    std::cout << "9)  DIV_PP_P\n";
    std::cout << "10) MOD_PP_P\n";
    std::cout << "11) GCF_PP_P\n";
    std::cout << "12) DER_P_P\n";
    std::cout << "13) NMR_P_P\n";
}

int getVariant(int lastVariant)
{
    int num = -1;
    std::cout << "-->";
    std::cin >> num;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\n";
    if (!(num >= 0 && num <= lastVariant))
    {
        std::cout << "Invalid value, enter again\n\n";
        num = -1;
    }
    return num;
}

template < typename T >
T getNumber(std::string&& message)
{
    T result;
    for (;;)
    {
        std::cout << message << "-->";
        std::string numS;
        std::getline(std::cin, numS);
        std::cout << "\n";
        if (numS.size() == 0 || numS == "q" || numS == "Q" || numS == "quit")
            throw std::exception();
        try
        {
            result = T(numS);
            break;
        }
        catch(...)
        {
            std::cout << "Invalid value, enter again\n";
            continue;
        }
    }
    return result;
}

template < typename T >
T getFirst(){return getNumber<T>("Enter first number:\n");}

//template <>
//Polinom getFirst<Polinom>(){return getNumber<T>("Enter first polinom:\n");}

template < typename T >
T getSecond(){return getNumber<T>("Enter second number:\n");}

//template <>
//Polinom getSecond<Polinom>(){return getNumber<T>("Enter second polinom:\n");}

int main()
{
    int state = FIRST_STATE;
    int numberOfOperation = 0;
    for (;;)
    {
        switch(state)
        {
            case FIRST_STATE:
            {
                printSetOfNumbers();
                int num = getVariant(4);
                switch(num)
                {
                    case 0:
                    case 'q':
                    case 'Q':
                        return 0;
                    case 1: state = NATURAL; break;
                    case 2: state = INTEGER; break;
                    case 3: state = RATIONAL; break;
                    case 4: state = POLINOM; break;
                }
                break;
            }
            case NATURAL:
            {
                printSetOfNaturalOperations();
                int operation = getVariant(14);
                if (operation >= 0 && operation <= 14)
                {
                    if (operation == 0)
                        state = FIRST_STATE;
                    else
                    {
                        state = OPERATION_NATURAL;
                        numberOfOperation = operation;
                    }
                }
                break;
            }
            case INTEGER:
            {
                printSetOfIntegerOperations();
                int operation = getVariant(10);
                if (operation >= 0 && operation <= 10)
                {
                    if (operation == 0)
                        state = FIRST_STATE;
                    else
                    {
                        state = OPERATION_INTEGER;
                        numberOfOperation = operation;
                    }
                }
                break;
            }
            case RATIONAL:
            {
                printSetOfRationalOperations();
                int operation = getVariant(8);
                if (operation >= 0 && operation <= 8)
                {
                    if (operation == 0)
                        state = FIRST_STATE;
                    else
                    {
                        state = OPERATION_RATIONAL;
                        numberOfOperation = operation;
                    }
                }
                break;
            }
            case POLINOM:
            {
                printSetOfPolinomOperations();
                int operation = getVariant(13);
                if (operation >= 0 && operation <= 13)
                {
                    if (operation == 0)
                        state = FIRST_STATE;
                    else
                    {
                        state = OPERATION_POLINOM;
                        numberOfOperation = operation;
                    }
                }
                break;
            }
            case OPERATION_NATURAL:
            {
                BigNatural first, second;
                try
                {
                    first = getFirst<BigNatural>();
                }
                catch(...)
                {
                    state = NATURAL;
                    continue;
                }

                if (numberOfOperation == 1 || numberOfOperation == 4 || numberOfOperation == 5 ||
                    numberOfOperation == 8 || numberOfOperation == 9 || numberOfOperation == 10 ||
                    numberOfOperation == 11 || numberOfOperation == 12 ||
                    numberOfOperation == 13 || numberOfOperation == 14)
                    try
                    {
                        second = getSecond<BigNatural>();
                    }
                    catch(...)
                    {
                        state = NATURAL;
                        continue;
                    }


                switch(numberOfOperation)
                {
                    case 1:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = COM_NN_D(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 2:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = NZER_N_B(first);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 3:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = ADD_1N_N(first);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 4:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = ADD_NN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 5:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = SUB_NN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 6:
                    {
                        state = NATURAL;
                        int n;
                        std::cout << "Enter number:\n-->";
                        std::cin >> n;
                        try
                        {
                            BigNatural result = MUL_ND_N(first, n);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 7:
                    {
                        state = NATURAL;
                        int n;
                        std::cout << "Enter number:\n-->";
                        std::cin >> n;
                        try
                        {
                            BigNatural result = MUL_Nk_N(first, n);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 8:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = MUL_NN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 9:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = SUB_NDN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 10:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = DIV_NN_Dk(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 11:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = DIV_NN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 12:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = MOD_NN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 13:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = GCF_NN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 14:
                    {
                        state = NATURAL;
                        try
                        {
                            BigNatural result = LCM_NN_N(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                }

                break;
            }
            case OPERATION_INTEGER:
            {
                BigInteger first, second;
                try
                {
                    first = getFirst<BigInteger>();
                }
                catch(...)
                {
                    state = INTEGER;
                    continue;
                }

                if (numberOfOperation == 6 || numberOfOperation == 7 || numberOfOperation == 8 ||
                    numberOfOperation == 9 || numberOfOperation == 10)
                    try
                    {
                        second = getSecond<BigInteger>();
                    }
                    catch(...)
                    {
                        state = INTEGER;
                        continue;
                    }

                switch(numberOfOperation)
                {
                    case 1:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = BigInteger(ABS_Z_N(first));
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 2:
                    {
                        state = INTEGER;
                        try
                        {
                            int result = POZ_Z_D(first);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 3:
                    {
                        state = INTEGER;
                        try
                        {
                            MUL_ZM_Z(first);
                            std::cout << "result: " << first << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 4:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = BigInteger(ABS_Z_N(first));
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 5:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = BigInteger(TRANS_Z_N(first));
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 6:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = ADD_ZZ_Z(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 7:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = SUB_ZZ_Z(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 8:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = MUL_ZZ_Z(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 9:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = DIV_ZZ_Z(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 10:
                    {
                        state = INTEGER;
                        try
                        {
                            BigInteger result = MOD_ZZ_Z(first, second);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                }


                break;
            }
            case OPERATION_RATIONAL:
            {
                BigRational first, second;
                try
                {
                    first = getFirst<BigRational>();
                }
                catch(...)
                {
                    state = POLINOM;
                    continue;
                }

                if (numberOfOperation == 5 || numberOfOperation == 6 || numberOfOperation == 7 ||
                    numberOfOperation == 8)
                    try
                    {
                        second = getSecond<BigRational>();
                    }
                    catch(...)
                    {
                        state = RATIONAL;
                        continue;
                    }

                switch(numberOfOperation)
                {
                    case 1:
                    {
                        state = RATIONAL;
                        try
                        {
                            BigRational result = RED_Q_Q(left);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 2:
                    {
                        state = RATIONAL;
                        try
                        {
                            bool result = INT_Q_B(left);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 3:
                    {
                        state = RATIONAL;
                        std::cout << "result: no visual result"
                        break;
                    }
                    case 4:
                    {
                        state = RATIONAL;
                        std::cout << "result: no visual result"
                        break;
                    }
                    case 5:
                    {
                        state = RATIONAL;
                        try
                        {
                            BigRational result = ADD_QQ_Q(left, right);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 6:
                    {
                        state = RATIONAL;
                        try
                        {
                            BigRational result = SUB_QQ_Q(left, right);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 7:
                    {
                        state = RATIONAL;
                        try
                        {
                            BigRational result = MUL_QQ_Q(left, right);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                    case 8:
                    {
                        state = RATIONAL;
                        try
                        {
                            BigRational result = DIV_QQ_Q(left, right);
                            std::cout << "result: " << result << "\n\n";
                        }
                        catch(std::exception& e)
                        {
                            std::cout << e.what() << "\n";
                            continue;
                        }
                        break;
                    }
                break;
            }
            case OPERATION_POLINOM:
            {
                Polinom first, second;
                try
                {
                    first = getFirst<Polinom>();
                }
                catch(...)
                {
                    state = POLINOM;
                    continue;
                }

                if (numberOfOperation == 1 || numberOfOperation == 2 || numberOfOperation == 7 ||
                    numberOfOperation == 8)
                    try
                    {
                        second = getSecond<Polinom>();
                    }
                    catch(...)
                    {
                        state = POLINOM;
                        continue;
                    }

                case 1:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = ADD_PP_P(left, right);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 2:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = SUB_PP_P(left, right);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 3:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = MUL_PQ_P(left);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 4:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = MUL_Pxk_P(left);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 5:
                {
                    throw std::runtime_error("feature not realized");
                }
                case 6:
                {
                    throw std::runtime_error("feature not realized");
                }
                case 8:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = MUL_PP_P(left,right);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 9:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = DIV_PP_P(left,right);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 11:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = GCF_PP_P(left,right);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 12:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = DER_P_P(left,right);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                case 13:
                {
                    state = POLINOM;
                    try
                    {
                        Polinom result = NMR_P_P(left,right);
                        std::cout << "result: " << result << "\n\n";
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << "\n";
                        continue;
                    }
                    break;
                }
                break;
            }

        }
    }
}

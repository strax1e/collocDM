#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include "BigInteger.h"
#include "standart_functions.h"

struct LogCell
{
    LogCell() = default;
    LogCell(const LogCell&) = default;
    LogCell(LogCell&&) = default;
    LogCell& operator =(const LogCell&) = default;
    LogCell& operator =(LogCell&&) = default;

    LogCell(std::string&& left, std::string&& right, std::string&& operation,
        std::string&& result, std::string&& must, std::string&& test): left(left), right(right),
            operation(operation), result(result), must(must), test(test){}

    std::string left;
    std::string right;
    std::string operation;
    std::string result;
    std::string must;
    std::string test;
};

typedef std::vector<LogCell> logBook;

template < typename T >
void test(logBook& logBook, T&& left, T&& right, T&& must,
          const std::string& operation, const std::string& testNumber = "-")
{
    std::stringstream leftSS;
    std::stringstream rightSS;
    std::stringstream resultSS;
    std::stringstream mustSS;

    std::string leftS;
    std::string rightS;
    std::string resultS;
    std::string mustS;

    leftSS << left;
    leftSS >> leftS;
    rightSS << right;
    rightSS >> rightS;
    mustSS << must;
    mustSS >> mustS;

    try
    {
        if (operation == "+=")
            left += right;
        else if (operation == "-=")
            left -= right;
        else if (operation == "*=")
            left *= right;
        else if (operation == "/=")
            left /= right;

        else if (operation == "+")
            left = left + right;
        else if (operation == "-")
            left = left - right;
        else if (operation == "*")
            left = left * right;
        else if (operation == "/")
            left = left / right;
        else if (operation == "%")
            left = left % right;

        else if (operation == "==")
            left = BigInteger(left == right);
        else if (operation == "!=")
            left = BigInteger(left != right);
        else if (operation == ">")
            left = BigInteger(left > right);
        else if (operation == "<")
            left = BigInteger(left < right);
        else if (operation == ">=")
            left = BigInteger(left >= right);
        else if (operation == "<=")
            left = BigInteger(left <= right);

        else
        {
            logBook.push_back( LogCell(std::move(leftS), std::move(rightS), std::string(operation),
                                "undefined operation", std::move(mustS), std::string(testNumber)) );
            return;
        }

        resultSS << left;
        resultSS >> resultS;

        logBook.push_back( LogCell(std::move(leftS), std::move(rightS), std::string(operation),
                            std::move(resultS), std::move(mustS), std::string(testNumber)) );
    }
    catch(std::exception& ex)
    {
        logBook.push_back( LogCell(std::move(leftS), std::move(rightS), std::string(operation),
                            std::string(ex.what()), std::move(mustS), std::string(testNumber)) );
    }
}

template < typename T >
void test(logBook& logBook, T&& left, T&& must,
          const std::string& operation, const std::string& testNumber = "-")
{
    std::stringstream leftSS;
    std::stringstream resultSS;
    std::stringstream mustSS;

    std::string leftS;
    std::string resultS;
    std::string mustS;

    leftSS << left;
    leftSS >> leftS;
    mustSS << must;
    mustSS >> mustS;

    try
    {
        if (operation == "()++")
            left++;
        else if (operation == "()--")
            left--;
        else if (operation == "++()")
            ++left;
        else if (operation == "--()")
            --left;

        else
        {
            logBook.push_back( LogCell(std::move(leftS), "-", std::string(operation),
                                "undefined operation", std::move(mustS), std::string(testNumber)) );
            return;
        }

        resultSS << left;
        resultSS >> resultS;

        logBook.push_back( LogCell(std::move(leftS), "-", std::string(operation),
                            std::move(resultS), std::move(mustS), std::string(testNumber)) );
    }
    catch(std::exception& ex)
    {
        logBook.push_back( LogCell(std::move(leftS), "-", std::string(operation),
                            std::string(ex.what()), std::move(mustS), std::string(testNumber)) );
    }
}


typedef BigInteger num;

int main()
{
    BigInteger a(123), b("321"), c(a);
    std::cout << a << " " << b << " " << c << "\n";
    a = a + b + c;
    std::cout << a << " " << b << " " << c << "\n";
    a += b += c;
    std::cout << a << " " << b << " " << c << "\n";
    bool d = a == c;
    std::cout << a << " " << b << " " << c << d << "\n";

    MUL_ZM_Z(a);
    std::cout << a << "\n";

    logBook logBook;
    test(logBook, num("17"),  num("5"),  num("3"),  "/", "1");
    test(logBook, num("-17"), num("5"),  num("-4"), "/", "2");
    test(logBook, num("17"),  num("-5"), num("-3"), "/", "3");
    test(logBook, num("-17"), num("-5"), num("4"),  "/", "4");
    test(logBook, num("17"),  num("5"),  num("2"), "%", "5");
    test(logBook, num("-17"), num("5"),  num("3"), "%", "6");
    test(logBook, num("17"),  num("-5"), num("2"), "%", "7");
    test(logBook, num("-17"), num("-5"), num("3"), "%", "8");
    test(logBook, num("-1"), num("5"), num("0"), "==", "9");
    test(logBook, num("-1"), num("5"), num("1"), "!=", "10");
    test(logBook, num("-1"), num("5"), num("0"), ">",  "11");
    test(logBook, num("-1"), num("5"), num("1"), "<",  "12");
    test(logBook, num("-1"), num("5"), num("0"), ">=", "13");
    test(logBook, num("-1"), num("5"), num("1"), "<=", "14");
    test(logBook, num("2"), num("3"), "()++", "15");
    test(logBook, num("-1"), num("0"), "++()", "16");
    test(logBook, num("5"), num("5"), num("1"), "==", "17");
    test(logBook, num("5"), num("5"), num("0"), "!=", "18");
    test(logBook, num("5"), num("5"), num("0"), ">",  "19");
    test(logBook, num("5"), num("5"), num("0"), "<",  "20");
    test(logBook, num("5"), num("5"), num("1"), ">=", "21");
    test(logBook, num("5"), num("5"), num("1"), "<=", "22");
    test(logBook, num("-1"), num("1"), num("-1"), "/", "23");
    test(logBook, num("-1"), num("1"), num("0"), "%", "24");
    test(logBook, num("-15"), num("5"), num("-3"), "/", "25");
    test(logBook, num("-15"), num("5"), num("0"),  "%", "26");
    test(logBook, num("-1"), num("3"), num("-1"), "/", "27");
    test(logBook, num("-1"), num("3"), num("2"), "%", "28");
    test(logBook, num("-1"), num("1"), num("0"), "+", "29");
    test(logBook, num("1"), num("-1"), num("0"), "+", "30");
    test(logBook, num("1"), num("1"), num("0"), "-", "31");
    test(logBook, num("0"), num("-1"), num("-1"), "+", "32");
    test(logBook, num("0"), num("1"), num("-1"), "-", "33");
    test(logBook, num("5"), num("5"), num("0"), "-", "34");
    test(logBook, num("0"), num("-5"), num("0"), "*", "35");
    test(logBook, num("-5"), num("0"), num("0"), "*", "36");
    test(logBook, num("1"), num("3"), num("0"), "/", "37");
    test(logBook, num("1"), num("3"), num("1"), "%", "38");
    test(logBook, num("-1"), num("-3"), num("3"), "*", "39");
    test(logBook, num("-1"), num("0"), "()++", "40");
    test(logBook, num("0"), num("-1"), "()--", "41");



    for (auto&& i : logBook)
    {
        std::cout << "test: ";
        std::cout.width(4);
        std::cout.setf(std::ios::left);
        std::cout << i.test;
        if (i.result == i.must)
            std::cout << " -  ok\n";
        else
        {
            std::cout << ": " << i.left << " " << i.operation << " ";
            i.right != "-" ? std::cout << i.right : std::cout << "";
            std::cout  << ";  result: " << i.result << ";   must be: " << i.must << "\n";
        }
    }

//    std::cout << "\n----------------\n";
//
//    BigInteger a(14);
//    BigNatural b = a.getNatural();
//    BigNatural c = std::move(a).getNatural();
//    std::cout << "----\n";
//    ++b;
//    ++c;
//    std::cout << a << " " << b << " " << c << "\n";
}

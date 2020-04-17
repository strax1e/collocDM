#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include "Big_Integer.h"

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
        else
        {
            logBook.push_back( LogCell(std::move(leftS), std::move(rightS), std::string(operation),
                                "undefined operation", std::move(mustS), std::string(testNumber)) );
            return;
        }

        resultSS << left;
        resultSS >> resultS;

        if (resultS == mustS)
            return;

        logBook.push_back( LogCell(std::move(leftS), std::move(rightS), std::string(operation),
                            std::move(resultS), std::move(mustS), std::string(testNumber)) );
    }
    catch(std::exception& ex)
    {
        logBook.push_back( LogCell(std::move(leftS), std::move(rightS), std::string(operation),
                            std::string(ex.what()), std::move(mustS), std::string(testNumber)) );
    }
}

typedef BigInteger<unsigned long long> num;

int main()
{
//    num a(1LL);
//    num b(0LL);
//    num c(2LL);
//    c = a + b + c + c;
//    std::cout << c << "\n";

    logBook logBook;
//    test(logBook, a, b, c, "+=", "23");
//    test(logBook, a, b, c, "+=", "1");
//    test(logBook, a, b, c, "/=", "2");
//    test(logBook, a, b, c, "-=");
//    test(logBook, num(2LL), num(4LL), num(13LL), "*=", "3");
//    test(logBook, num(12858LL), num(4LL), num(7LL), "+", "4");
    test(logBook, num(17LL),  num(5LL),  num(3LL),  "/", "1/");
    test(logBook, num(-17LL), num(5LL),  num(-4LL), "/", "2/");
    test(logBook, num(17LL),  num(-5LL), num(-3LL), "/", "3/");
    test(logBook, num(-17LL), num(-5LL), num(4LL),  "/", "4/");

    test(logBook, num(17LL),  num(5LL),  num(2LL), "%", "1%");
    test(logBook, num(-17LL), num(5LL),  num(3LL), "%", "2%");
    test(logBook, num(17LL),  num(-5LL), num(2LL), "%", "3%");
    test(logBook, num(-17LL), num(-5LL), num(3LL), "%", "4%");

    for (auto&& i : logBook)
    {
        std::cout << "test: ";
        std::cout.width(4);
        std::cout.setf(std::ios::left);
        std::cout << i.test;
        std::cout << ": " << i.left << " " << i.operation << " " << i.right;
        std::cout  << ";  result: " << i.result << ";   must be: " << i.must << "\n";
    }
}

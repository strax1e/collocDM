#include <iostream>
#include "Big_Integer.hpp"

int main()
{
    Big_Integer a(1);
    Big_Integer b(2);
std::cout << "1----------\n";
    Big_Integer c(a+b);
//std::cout << c << "\n";
std::cout << "2----------\n";
/*
    Big_Integer d(std::move(b));
    a += std::move(c);
std::cout << "----------\n";
    c = a + (b + c);
std::cout << "----------\n";
    c = (a + b) + c;
    std::cout << "============\n";
    c = a + std::move(b);
    */
}

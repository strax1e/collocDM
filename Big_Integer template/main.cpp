#include <iostream>
#include "Big_Integer.hpp"

int main()
{
    Big_Integer<unsigned short> a(1);
    Big_Integer<unsigned short> b(2);
    Big_Integer<unsigned short> c(a-b);
    std::cout << c << "\n";
    c += a + b * (++a);
    std::cout << c << "\n";
}

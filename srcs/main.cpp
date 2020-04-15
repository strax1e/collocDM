#include "../libs/main.h"
#include "../libs/BigNatural.h"

using namespace std;

int main()
{
    int h = 5;
    int& g = h;
    bign::BigNatural num1 = (string)"000021", num2 = 4, num3 = 3;
    num2 = (num1 += 5) += num3;
    cout << num1 << ' ' << num2 << '\n'; 
    return 0;
}
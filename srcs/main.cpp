#include "../libs/main.h"
#include "../libs/biginteger.h"

using namespace std;

int main()
{
    vector<int> i(5, 5);
    i[0] = 1;
    i.resize(6);
    for (auto g = i.begin(); g != i.end(); g++)
        cout << *g << ' ';
    return 0;
}
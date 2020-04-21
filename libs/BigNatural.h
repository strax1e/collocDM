/* Natural numbers source code module
 * Authors:
 * - Afanasyev Andrey 9373
 * - Arutiunian Vladimir 9373
 */
#include <vector>
#include <string>
#include <assert.h>
#include <fstream>
#include <algorithm>

namespace bign
{
class BigNatural
{
private:
    std::vector<int> nums;

    // compares
    // !=
    friend const bool operator!=(const BigNatural &left, const BigNatural &right);
    friend const bool operator!=(const BigNatural &left, const long long &right);
    friend const bool operator!=(const long long &left, const BigNatural &right);

    // ==
    friend const bool operator==(const BigNatural &left, const BigNatural &right);
    friend const bool operator==(const BigNatural &left, const long long &right);
    friend const bool operator==(const long long &left, const BigNatural &right);

    // >=
    friend const bool operator>=(const BigNatural &left, const BigNatural &right);
    friend const bool operator>=(const BigNatural &left, const long long &right);
    friend const bool operator>=(const long long &left, const BigNatural &right);

    // >
    friend const bool operator>(const BigNatural &left, const BigNatural &right);
    friend const bool operator>(const BigNatural &left, const long long &right);
    friend const bool operator>(const long long &left, const BigNatural &right);

    // <=
    friend const bool operator<=(const BigNatural &left, const BigNatural &right);
    friend const bool operator<=(const BigNatural &left, const long long &right);
    friend const bool operator<=(const long long &left, const BigNatural &right);

    // <
    friend const bool operator<(const BigNatural &left, const BigNatural &right);
    friend const bool operator<(const BigNatural &left, const long long &right);
    friend const bool operator<(const long long &left, const BigNatural &right);

    // --
    friend const BigNatural operator--(BigNatural &left, int);
    friend BigNatural &operator--(BigNatural &left);

    // ++
    friend const BigNatural operator++(BigNatural &left, int);
    friend BigNatural &operator++(BigNatural &left);

    // -=
    friend BigNatural &operator-=(BigNatural &left, const BigNatural &right);
    friend BigNatural &bign::operator-=(BigNatural &left, const long long &right);

    // +=
    friend BigNatural &operator+=(BigNatural &left, const BigNatural &right);
    friend BigNatural &operator+=(BigNatural &left, const long long &right);

    // *=
    friend BigNatural &operator*=(BigNatural &left, const BigNatural &right);
    friend BigNatural &operator*=(BigNatural &left, const long long &right);

    // -
    friend const BigNatural operator-(const BigNatural &left, const BigNatural &right);
    friend const BigNatural operator-(const BigNatural &left, const long long &right);
    friend const BigNatural operator-(const long long &left, const BigNatural &right);

    // +
    friend const BigNatural operator+(const BigNatural &left, const BigNatural &right);
    friend const BigNatural operator+(const BigNatural &left, const long long &right);
    friend const BigNatural operator+(const long long &left, const BigNatural &right);

    // *
    friend const BigNatural operator*(const BigNatural &left, const BigNatural &right);
    friend const BigNatural operator*(const BigNatural &left, const long long &right);
    friend const BigNatural operator*(const long long &left, const BigNatural &right);

    // output
    friend std::ostream &operator<<(std::ostream &out, const BigNatural &obj);

public:
    operator bool();
    BigNatural(const std::string &inum);
    BigNatural(long long inum);
    BigNatural(const BigNatural &inum);
    BigNatural(void)
    {
        nums.push_back(0);
    }
    ~BigNatural(void);
    BigNatural &pow10(const long long &k);
};

const BigNatural GCD(const BigNatural &left, BigNatural &right);
const BigNatural GCD(const BigNatural &left, long long &right);
const BigNatural GCD(const long long &left, BigNatural &right);
const BigNatural LCM(const BigNatural &left, BigNatural &right);
const BigNatural LCM(const BigNatural &left, long long &right);
const BigNatural LCM(const long long &left, BigNatural &right);
} // namespace bign
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
    friend BigNatural &operator-=(BigNatural &left, const long long &right);

    // +=
    friend BigNatural &operator+=(BigNatural &left, const BigNatural &right);
    friend BigNatural &operator+=(BigNatural &left, const long long &right);

    // *=
    friend BigNatural &operator*=(BigNatural &left, const BigNatural &right);
    friend BigNatural &operator*=(BigNatural &left, const long long &right);

    // /=
    friend BigNatural &operator/=(BigNatural &left, const BigNatural &right);
    friend BigNatural &operator/=(BigNatural &left, const long long &right);

    // %=
    friend BigNatural &operator%=(BigNatural &left, const BigNatural &right);
    friend BigNatural &operator%=(BigNatural &left, const long long &right);

    // -
    friend const BigNatural operator-(BigNatural left, const BigNatural &right);
    friend const BigNatural operator-(BigNatural left, const long long &right);
    friend const BigNatural operator-(const long long &left, const BigNatural &right);

    // +
    friend const BigNatural operator+(BigNatural left, const BigNatural &right);
    friend const BigNatural operator+(BigNatural left, const long long &right);
    friend const BigNatural operator+(const long long &left, const BigNatural &right);

    // *
    friend const BigNatural operator*(BigNatural left, const BigNatural &right);
    friend const BigNatural operator*(BigNatural left, const long long &right);
    friend const BigNatural operator*(const long long &left, const BigNatural &right);

    // /
    friend const BigNatural operator/(BigNatural left, const BigNatural &right);
    friend const BigNatural operator/(BigNatural left, const long long &right);
    friend const BigNatural operator/(const long long &left, const BigNatural &right);

    // %
    friend const BigNatural operator%(BigNatural left, const BigNatural &right);
    friend const BigNatural operator%(BigNatural left, const long long &right);
    friend const BigNatural operator%(const long long &left, const BigNatural &right);

    // output
    friend std::ostream &operator<<(std::ostream &out, const BigNatural &obj);

    // input
    friend std::istream &operator>>(std::istream &in, BigNatural &obj);

public:
    BigNatural &pow10(const long long &k);
    BigNatural &pow10(const BigNatural &k);
    const size_t getSize() const;
    explicit operator bool() const;
    BigNatural(const std::string &inum);
    BigNatural(long long inum);
    BigNatural(const BigNatural &inum);
    BigNatural(void);
    ~BigNatural(void);
};

// GCD
const BigNatural GCD(const BigNatural &left, const BigNatural &right);
const BigNatural GCD(const BigNatural &left, const long long &right);
const BigNatural GCD(const long long &left, const BigNatural &right);

// LCM
const BigNatural LCM(const BigNatural &left, const BigNatural &right);
const BigNatural LCM(const BigNatural &left, const long long &right);
const BigNatural LCM(const long long &left, const BigNatural &right);
} // namespace bign
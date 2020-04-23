#include "../libs/BigNatural.h"

// compares
const bool operator!=(const BigNatural &left, const BigNatural &right)
{
    return !(left == right);
}

const bool operator!=(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left != newRight;
}

const bool operator!=(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft != right;
}

// ==
const bool operator==(const BigNatural &left, const BigNatural &right)
{
    if (left.nums.size() != right.nums.size())
        return false;
    else
        for (size_t i = left.nums.size(); i > 0; --i)
            if (left.nums[i - 1] != right.nums[i - 1])
                return false;
    return true;
}

const bool operator==(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left == newRight;
}

const bool operator==(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft == right;
}

// >=
const bool operator>=(const BigNatural &left, const BigNatural &right)
{
    return !(left < right);
}

const bool operator>=(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left >= newRight;
}

const bool operator>=(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft >= right;
}

// >
const bool operator>(const BigNatural &left, const BigNatural &right)
{
    return right < left;
}

const bool operator>(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left > newRight;
}

const bool operator>(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft > right;
}

// <=
const bool operator<=(const BigNatural &left, const BigNatural &right)
{
    return !(left > right);
}

const bool operator<=(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left <= newRight;
}

const bool operator<=(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft <= right;
}

// <
const bool operator<(const BigNatural &left, const BigNatural &right)
{
    if (left.nums.size() > right.nums.size())
        return false;
    else if (left.nums.size() < right.nums.size())
        return true;
    else
        for (size_t i = left.nums.size(); i > 0; --i)
            if (left.nums[i- 1] > right.nums[i-1])
                return false;
            else if (left.nums[i-1] < right.nums[i-1])
                return true;
    return false;
}

const bool operator<(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left < newRight;
}

const bool operator<(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft < right;
}

// --
const BigNatural operator--(BigNatural &left, int)
{
    BigNatural old = left;
    left -= 1;
    return old;
}

BigNatural &operator--(BigNatural &left)
{
    return left -= 1;
}

// ++
const BigNatural operator++(BigNatural &left, int)
{
    BigNatural old = left;
    left += 1;
    return old;
}

BigNatural &operator++(BigNatural &left)
{
    return left += 1;
}

// -=
BigNatural &operator-=(BigNatural &left, const long long &right)
{
    BigNatural newright = right;
    return left -= newright;
}

BigNatural &operator-=(BigNatural &left, const BigNatural &right)
{
    if (left >= right)
    {
        int overflow = 0;
        for (size_t i = 0; i < left.nums.size() || overflow; ++i)
        {
            left.nums[i] -= overflow + (i < right.nums.size() ? right.nums[i] : 0);
            overflow = left.nums[i] < 0;
            if (overflow)
                left.nums[i] += 10;
        }
        while (left.nums.size() > 1 && left.nums.back() == 0)
            left.nums.pop_back();
        return left;
    }
    else
        throw(std::runtime_error("[Exception] negative result. Right > Left"));
}

// +=
BigNatural &operator+=(BigNatural &left, const BigNatural &right)
{
    int overflow = 0;
    for (size_t i = 0; i < std::max(left.nums.size(), right.nums.size()) || overflow; ++i)
    {
        if (left.nums.size() == i)
            left.nums.push_back(0);
        left.nums[i] += overflow + ((right.nums.size() > i) ? right.nums[i] : 0);
        overflow = left.nums[i] >= 10;
        if (overflow)
            left.nums[i] -= 10;
    }
    return left;
}

BigNatural &operator+=(BigNatural &left, const long long &right)
{
    BigNatural newright = right;
    return left += newright;
}

// *=
BigNatural &operator*=(BigNatural &left, const BigNatural &right)
{
    int overflow = 0;
    BigNatural result = 0;
    result.nums.resize(left.nums.size() + right.nums.size() + 1);
    for (size_t i = 0; i < left.nums.size(); ++i)
        for (size_t j = 0; j < right.nums.size() || overflow; ++j)
        {
            int tmp = result.nums[i + j] + left.nums[i] * ((j < (int)right.nums.size()) ? right.nums[j] : 0) + overflow;
            result.nums[i + j] = tmp % 10;
            overflow = tmp / 10;
        }
    while (result.nums.size() > 1 && result.nums.back() == 0)
        result.nums.pop_back();
    left.nums = result.nums;
    return left;
}

BigNatural &operator*=(BigNatural &left, const long long &right)
{
    BigNatural bigright = right;
    return left *= bigright;
}

// /=
BigNatural &operator/=(BigNatural &left, const BigNatural &right)
{
    if (!right)
        throw(std::runtime_error("division by zero"));
    else if (left < right)
        return left = 0;
    std::vector<int> result;                       // stores the result
    BigNatural partLeft;                           //
    partLeft.nums.pop_back();                      // reset the size
    size_t sizeRemainder = 0; // max long long
    while (left >= right)
    {
        partLeft.nums.reserve(right.getSize() + 3);
        for (size_t g = left.getSize() - right.getSize(); g < left.getSize(); ++g)                     // getting part of the left number to divide by the right
            partLeft.nums.push_back(left.nums[g]);                                                        //
        if (partLeft < right)                                                                             // adding the extra digit if the number is too small to divide
            partLeft.nums.insert(partLeft.nums.begin(), left.nums[left.getSize() - right.getSize() - 1]); //
        if (result.size() && partLeft.getSize() > sizeRemainder + 1)                                                       // adding zeros to the result
            for (size_t g = 0, end = partLeft.getSize() - sizeRemainder - 1; g < end; ++g)             //
                result.push_back(0);                                                                      //
        long long partRes = 1;                                                                                  // finding part of the result
        while (partRes * right <= partLeft)
            ++partRes;
        --partRes;
        for (size_t i = 0; i < partLeft.getSize(); ++i)    // deleting used digits
            left.nums.pop_back();                       //
        partLeft -= partRes * right;                    // calculating the remainder of the number
        if (partLeft == 0)                              // delete zero
            partLeft.nums.pop_back();                   //
        sizeRemainder = partLeft.getSize();             // calculating the remainder size
        for (size_t i = 0; i < sizeRemainder; ++i)         // adding digits to the original number for a new iteration
            left.nums.push_back(partLeft.nums[i]);      //
        partLeft.nums.clear();                          // deleting all elements
        result.push_back(partRes);                      // adding part of the result
        while (left.getSize() && left.nums.back() == 0) // adding zeros to the result (xxx00)
        {
            left.nums.pop_back();
            result.push_back(0);
        }
    }
    size_t currSizeLeft = left.getSize();
    left.nums.clear();
    if (left != 0 && currSizeLeft > sizeRemainder)                              // adding zeros to the result (left)
        for (size_t g = 0, end = currSizeLeft - sizeRemainder; g < end; ++g) //
            left.nums.push_back(0);                                             //
    for (auto it = result.rbegin(); it != result.rend(); ++it)                  // coping from the result to the left
        left.nums.push_back(*it);
    return left;
}

BigNatural &operator/=(BigNatural &left, const long long &right)
{
    BigNatural newright = right;
    return left /= newright;
}

// %=
BigNatural &operator%=(BigNatural &left, const BigNatural &right)
{
    if (right == 0)
        throw(std::runtime_error("division by zero"));
    else if (left < right)
        return left;
    BigNatural partLeft;
    partLeft.nums.pop_back();                      // reset the size
    size_t sizeRemainder = 0; // max long long
    while (left >= right)
    {
        partLeft.nums.reserve(right.getSize() + 3);
        for (size_t g = left.getSize() - right.getSize(); g < left.getSize(); ++g)                     // getting part of the left number to divide by the right
            partLeft.nums.push_back(left.nums[g]);                                                        //
        if (partLeft < right)                                                                             // adding the extra digit if the number is too small to divide
            partLeft.nums.insert(partLeft.nums.begin(), left.nums[left.getSize() - right.getSize() - 1]); // finding part of the result
        long long partRes = 1;
        while (partRes * right <= partLeft)
            ++partRes;
        --partRes;
        for (size_t i = 0; i < partLeft.getSize(); ++i)    // deleting used digits
            left.nums.pop_back();                       //
        partLeft -= partRes * right;                    // calculating the remainder of the number
        if (partLeft == 0)                              // delete zero
            partLeft.nums.pop_back();                   //
        sizeRemainder = partLeft.getSize();             // calculating the remainder size
        for (size_t i = 0; i < sizeRemainder; ++i)         // adding digits to the original number for a new iteration
            left.nums.push_back(partLeft.nums[i]);      //
        partLeft.nums.clear();                          // deleting all elements
        while (left.getSize() && left.nums.back() == 0) // deleting leading zeros
            left.nums.pop_back();
    }
    if (!left.getSize()) // adding a zero when the vector is empty
        left.nums.push_back(0);
    return left;
}

BigNatural &operator%=(BigNatural &left, const long long &right)
{
    return left %= (BigNatural)right;
}

// -
const BigNatural operator-(BigNatural left, const BigNatural &right)
{
    return left -= right;
}

const BigNatural operator-(BigNatural left, const long long &right)
{
    return left -= right;
}

const BigNatural operator-(const long long &left, const BigNatural &right)
{
    BigNatural newleft = left;
    return newleft -= right;
}

// +
const BigNatural operator+(BigNatural left, const BigNatural &right)
{
    return left += right;
}

const BigNatural operator+(BigNatural left, const long long &right)
{
    return left += right;
}

const BigNatural operator+(const long long &left, const BigNatural &right)
{
    BigNatural newleft = left;
    return newleft += right;
}

// *
const BigNatural operator*(BigNatural left, const BigNatural &right)
{
    return left *= right;
}

const BigNatural operator*(BigNatural left, const long long &right)
{
    return left *= right;
}

const BigNatural operator*(const long long &left, const BigNatural &right)
{
    BigNatural newleft = left;
    return newleft *= right;
}

// /
const BigNatural operator/(BigNatural left, const BigNatural &right)
{
    return left /= right;
}

const BigNatural operator/(BigNatural left, const long long &right)
{
    return left /= right;
}

const BigNatural operator/(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft /= right;
}

// %
const BigNatural operator%(BigNatural left, const BigNatural &right)
{
    return left %= right;
}

const BigNatural operator%(BigNatural left, const long long &right)
{
    return left %= right;
}

const BigNatural operator%(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft %= right;
}

// output
std::ostream &operator<<(std::ostream &out, const BigNatural &obj)
{
    for (auto g = obj.nums.rbegin(); g != obj.nums.rend(); ++g)
        out << *g;
    return out;
}

// input
std::istream &operator>>(std::istream &in, BigNatural &obj)
{
    std::string t;
    in >> t;
    obj = t;
    return in;
}

// pow10
BigNatural &BigNatural::pow10(const BigNatural &k)
{
    for (BigNatural i = 0; i < k; ++i)
        nums.insert(nums.begin(), 0);
    return *this;
}

BigNatural &BigNatural::pow10(const long long &k)
{
    if (k < 0)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (k + i < nums.size())
            {
                nums[i] ^= nums[k + i];
                nums[i + k] ^= nums[i];
                nums[i] ^= nums[k + i];
            }
            else
                nums[i] = 0;
        while (nums.size() > 1 && nums.back() == 0)
            nums.pop_back();
    }
    else
    {
        unsigned long long szvec = nums.size();
        nums.resize(nums.size() + k);
        for (unsigned long long i = szvec - 1; i >= 0; --i)
        {
            nums[i + k] ^= nums[i];
            nums[i] ^= nums[i + k];
            nums[i + k] ^= nums[i];
            if (!i)
                break;
        }
    }
    return *this;
}

const size_t BigNatural::getSize() const
{
    return nums.size();
}

BigNatural::operator bool() const
{
    return *this != 0;
}

// constructors
BigNatural::BigNatural(const std::string &inum)
{
    if (inum.size())
    {
        nums.reserve(2 * inum.size());
        for (int i = inum.size() - 1; i >= 0; --i)
            if (inum[i] >= '0' && inum[i] <= '9')
                nums.push_back(inum[i] - '0');
            else
                throw(std::runtime_error("[Exception] invalid input"));
        while (nums.size() > 1 && nums.back() == 0)
            nums.pop_back();
    }
    else
        throw(std::runtime_error("[Exception] invalid input"));
}

BigNatural::BigNatural(long long inum)
{
    if (inum > 0)
        while (inum)
        {
            nums.push_back((inum % 10));
            inum /= 10;
        }
    else if (!inum)
        nums.push_back(0);
    else
        throw(std::runtime_error("[Exception] negative number"));
}

BigNatural::BigNatural(const BigNatural &inum)
{
    nums = inum.nums;
}

BigNatural::BigNatural()
{
    nums.push_back(0);
}

// destructor
BigNatural::~BigNatural(void)
{
}

const BigNatural GCD(const BigNatural &left, const BigNatural &right)
{
    if (left == 0)
        return right;
    else if (right == 0)
        return left;
    BigNatural newLeft, newRight, tmp;
    if (right < left)
    {
        newLeft = left;
        newRight = right;
    }
    else
    {
        newLeft = right;
        newRight = left;
    }
    while (newLeft % newRight)
    {
        tmp = newLeft;
        newLeft = newRight;
        newRight = tmp % newRight;
    }
    return newRight;
}

const BigNatural GCD(const BigNatural &left, const long long &right)
{
    BigNatural castRight = right;
    return GCD(left, castRight);
}

const BigNatural GCD(const long long &left, const BigNatural &right)
{
    BigNatural castLeft = left;
    return GCD(castLeft, right);
}

const BigNatural LCM(const BigNatural &left, const BigNatural &right)
{
    return (left * right) / GCD(left, right);
}

const BigNatural LCM(const BigNatural &left, const long long &right)
{
    return (left * right) / GCD(left, right);
}

const BigNatural LCM(const long long &left, const BigNatural &right)
{
    return (left * right) / GCD(left, right);
}
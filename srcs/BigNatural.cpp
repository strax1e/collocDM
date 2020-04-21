#include "../libs/BigNatural.h"

// compares
const bool bign::operator!=(const BigNatural &left, const BigNatural &right)
{
    return !(left == right);
}

const bool bign::operator==(const BigNatural &left, const BigNatural &right)
{
    if (left.nums.size() != right.nums.size())
        return false;
    else
    {
        for (int i = left.nums.size() - 1; i >= 0; --i)
            if (left.nums[i] != right.nums[i])
                return false;
    }
    return true;
}

const bool bign::operator>=(const BigNatural &left, const BigNatural &right)
{
    return !(left < right);
}

const bool bign::operator>(const BigNatural &left, const BigNatural &right)
{
    return right < left;
}

const bool bign::operator<=(const BigNatural &left, const BigNatural &right)
{
    return !(left > right);
}

const bool bign::operator<(const BigNatural &left, const BigNatural &right)
{
    if (left.nums.size() > right.nums.size())
        return false;
    else if (left.nums.size() < right.nums.size())
        return true;
    else
    {
        for (int i = left.nums.size() - 1; i >= 0; --i)
        {
            if (left.nums[i] > right.nums[i])
                return false;
            else if (left.nums[i] < right.nums[i])
                return true;
        }
    }
    return false;
}

// --
const bign::BigNatural bign::operator--(BigNatural &left, int)
{
    bign::BigNatural old = left;
    left -= 1;
    return old;
}

bign::BigNatural& bign::operator--(BigNatural &left)
{
    return left -= 1;
}

// ++
const bign::BigNatural bign::operator++(BigNatural &left, int)
{
    BigNatural old = left;
    left += 1;
    return old;
}

bign::BigNatural &bign::operator++(BigNatural &left)
{
    return left += 1;
}

// -=
bign::BigNatural &bign::operator-=(BigNatural &left, const long long &right)
{
    bign::BigNatural newright = right;
    return left -= newright;
}

bign::BigNatural &bign::operator-=(BigNatural &left, const BigNatural &right)
{
    if (left >= right)
    {
        int overflow = 0;
        for (int i = 0; i < left.nums.size() || overflow; ++i)
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
        return left = 0;
}

// +=
bign::BigNatural &bign::operator+=(BigNatural &left, const BigNatural &right)
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

bign::BigNatural &bign::operator+=(BigNatural &left, const long long &right)
{
    bign::BigNatural newright = right;
    return left += newright;
}

// *=
bign::BigNatural &bign::operator*=(BigNatural &left, const BigNatural &right)
{
    int overflow = 0;
    bign::BigNatural result = 0;
    result.nums.resize(left.nums.size() + right.nums.size() + 1);
    for (int i = 0; i < (int)left.nums.size(); ++i)
    {
        for (int j = 0; j < (int)right.nums.size() || overflow; ++j)
        {
            int tmp = result.nums[i + j] + left.nums[i] * ((j < (int)right.nums.size()) ? right.nums[j] : 0) + overflow;
            result.nums[i + j] = tmp % 10;
            overflow = tmp / 10;
        }
    }
    while (result.nums.size() > 1 && result.nums.back() == 0)
        result.nums.pop_back();
    left.nums = result.nums;
    return left;
}

bign::BigNatural &bign::operator*=(BigNatural &left, const long long &right)
{
    bign::BigNatural bigright = right;
    return left *= bigright;
}


// -
const bign::BigNatural bign::operator-(const BigNatural &left, const BigNatural &right)
{
    bign::BigNatural newleft = left;
    return newleft -= right;
}

const bign::BigNatural bign::operator-(const BigNatural &left, const long long &right)
{
    bign::BigNatural newright = right, newleft = left;
    return newleft -= newright;
}

const bign::BigNatural bign::operator-(const long long &left, const BigNatural &right)
{
    bign::BigNatural newleft = left;
    return newleft -= right;
}

// +
const bign::BigNatural bign::operator+(const BigNatural &left, const BigNatural &right)
{
    bign::BigNatural newleft = left;
    return newleft += right;
}

const bign::BigNatural bign::operator+(const BigNatural &left, const long long &right)
{
    bign::BigNatural newright = right;
    return newright += left;
}

const bign::BigNatural bign::operator+(const long long &left, const BigNatural &right)
{
    bign::BigNatural newleft = left;
    return newleft += right;
}

// *
const bign::BigNatural bign::operator*(const BigNatural &left, const BigNatural &right)
{
    bign::BigNatural newleft = left;
    return newleft *= right;
}

const bign::BigNatural bign::operator*(const BigNatural &left, const long long &right)
{
    bign::BigNatural newright = right;
    return newright *= left;
}

const bign::BigNatural bign::operator*(const long long &left, const BigNatural &right)
{
    bign::BigNatural newleft = left;
    return newleft *= right;
}

// output
std::ostream &bign::operator<<(std::ostream &out, const BigNatural &obj)
{
    for (auto g = obj.nums.end() - 1; g != obj.nums.begin() - 1; --g)
        out << *g;
    return out;
}

// constructors
bign::BigNatural::BigNatural(const std::string &inum)
{
    if (inum.size() != 0)
    {
        nums.reserve(2 * inum.size());
        for (int i = inum.size() - 1; i >= 0; --i)
            if (inum[i] >= '0' && inum[i] <= '9')
                nums.push_back(inum[i] - '0');
            else
                assert(0);
        while (nums.size() > 1 && nums.back() == 0)
            nums.pop_back();
    }
    else
        assert(0);
}

bign::BigNatural::BigNatural(long long inum)
{
    if (inum > 0)
    {
        while (inum)
        {
            nums.push_back((inum % 10));
            inum /= 10;
        }
    }
    else if (inum == 0)
        nums.push_back(0);
    else
        assert(0);
}

bign::BigNatural::BigNatural(const BigNatural &inum)
{
    nums = inum.nums;
}

// destructor
bign::BigNatural::~BigNatural(void)
{
}
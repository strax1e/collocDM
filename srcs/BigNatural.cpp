#include "../libs/BigNatural.h"

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

bign::BigNatural::BigNatural(const bign::BigNatural &inum)
{
    nums = inum.nums;
}

bign::BigNatural &bign::operator+=(bign::BigNatural &left, const long long &right)
{
    bign::BigNatural bigright = right;
    return left += bigright;
}

bign::BigNatural &bign::operator+=(bign::BigNatural &left, const bign::BigNatural &right)
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

bign::BigNatural &bign::operator*=(bign::BigNatural &left, const bign::BigNatural &right)
{
    int overflow = 0;
    bign::BigNatural result = 0;
    for (int i = 0; i < left.nums.size(); ++i)
    {
        for (int j = 0; j < right.nums.size(); ++j)
        {}
    }
}

const bign::BigNatural bign::operator+(const bign::BigNatural &left, const bign::BigNatural &right)
{
    bign::BigNatural newnum = left;
    return newnum += right;
}

std::ostream &bign::operator<< (std::ostream& out, const bign::BigNatural &obj)
{
    for (auto g = obj.nums.end() - 1; g != obj.nums.begin() - 1; --g)
        out << *g << ' ';
    return out;
}
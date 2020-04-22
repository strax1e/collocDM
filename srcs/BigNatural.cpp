#include "../libs/BigNatural.h"

// compares
const bool bign::operator!=(const BigNatural &left, const BigNatural &right)
{
    return !(left == right);
}

const bool bign::operator!=(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left != newRight;
}

const bool bign::operator!=(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft != right;
}

// ==
const bool bign::operator==(const BigNatural &left, const BigNatural &right)
{
    if (left.nums.size() != right.nums.size())
        return false;
    else {
        for (int i = left.nums.size() - 1; i >= 0; --i)
            if (left.nums[i] != right.nums[i])
                return false;
    }
    return true;
}

const bool bign::operator==(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left == newRight;
}

const bool bign::operator==(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft == right;
}

// >=
const bool bign::operator>=(const BigNatural &left, const BigNatural &right)
{
    return !(left < right);
}

const bool bign::operator>=(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left >= newRight;
}

const bool bign::operator>=(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft >= right;
}

// >
const bool bign::operator>(const BigNatural &left, const BigNatural &right)
{
    return right < left;
}

const bool bign::operator>(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left > newRight;
}

const bool bign::operator>(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft > right;
}

// <=
const bool bign::operator<=(const BigNatural &left, const BigNatural &right)
{
    return !(left > right);
}

const bool bign::operator<=(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left <= newRight;
}

const bool bign::operator<=(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft <= right;
}

// <
const bool bign::operator<(const BigNatural &left, const BigNatural &right)
{
    if (left.nums.size() > right.nums.size())
        return false;
    else if (left.nums.size() < right.nums.size())
        return true;
    else {
        for (int i = left.nums.size() - 1; i >= 0; --i) {
            if (left.nums[i] > right.nums[i])
                return false;
            else if (left.nums[i] < right.nums[i])
                return true;
        }
    }
    return false;
}

const bool bign::operator<(const BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left < newRight;
}

const bool bign::operator<(const long long &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft < right;
}

// --
const bign::BigNatural bign::operator--(BigNatural &left, int)
{
    bign::BigNatural old = left;
    left -= 1;
    return old;
}

bign::BigNatural &bign::operator--(BigNatural &left)
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
    if (left >= right) {
        int overflow = 0;
        for (int i = 0; i < left.nums.size() || overflow; ++i) {
            left.nums[i] -= overflow + (i < right.nums.size() ? right.nums[i] : 0);
            overflow = left.nums[i] < 0;
            if (overflow) {
                left.nums[i] += 10;
            }
        }
        while (left.nums.size() > 1 && left.nums.back() == 0) {
            left.nums.pop_back();
        }
        return left;
    } else {
        throw(std::runtime_error("[Exception] negative result. Right > Left"));
    }
}

// +=
bign::BigNatural &bign::operator+=(BigNatural &left, const BigNatural &right)
{
    int overflow = 0;
    for (size_t i = 0; i < std::max(left.nums.size(), right.nums.size()) || overflow; ++i) {
        if (left.nums.size() == i) {
            left.nums.push_back(0);
        }
        left.nums[i] += overflow + ((right.nums.size() > i) ? right.nums[i] : 0);
        overflow = left.nums[i] >= 10;
        if (overflow) {
            left.nums[i] -= 10;
        }
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
    for (int i = 0; i < (int)left.nums.size(); ++i) {
        for (int j = 0; j < (int)right.nums.size() || overflow; ++j) {
            int tmp = result.nums[i + j] + left.nums[i] * ((j < (int)right.nums.size()) ? right.nums[j] : 0) + overflow;
            result.nums[i + j] = tmp % 10;
            overflow = tmp / 10;
        }
    }
    while (result.nums.size() > 1 && result.nums.back() == 0) {
        result.nums.pop_back();
    }
    left.nums = result.nums;
    return left;
}

bign::BigNatural &bign::operator*=(BigNatural &left, const long long &right)
{
    bign::BigNatural bigright = right;
    return left *= bigright;
}

// /=
bign::BigNatural &bign::operator/=(BigNatural &left, const BigNatural &right)
{
    if (right == 0)
        throw(std::runtime_error("division by zero"));
    else if (left < right)
        return left = 0;
    BigNatural vLeft = left, result, partLeft;
    std::string part;
    long long sizeOst = 9223372036854775807;
    while (vLeft >= right) {
        part.reserve(right.nums.size() + 3);
        long long len = right.nums.size();
        do {
            part.clear();
            for (int g = vLeft.nums.size() - 1, end = vLeft.nums.size() - 1 - len; g > end && g >= 0; --g) {
                part.push_back(vLeft.nums[g] + '0');
            }
            partLeft = part;
            ++len;
        } while (partLeft < right);
        if (len > sizeOst) {
            long long oldSizeRes = result.nums.size();
            long long sizeZero = len - sizeOst - 2;
            long long cou = oldSizeRes + sizeZero;
            result.nums.resize(cou);
            for (int g = result.nums.size() - 1; g != result.nums.size() - 1 - oldSizeRes; --g)
                result.nums[g] = result.nums[g - sizeZero];
            for (int i = 0; i < sizeZero; ++i)
                result.nums[i] = 0;
        }
        int partRes = 0;
        while (partRes * right <= partLeft)
            ++partRes;
        --partRes;
        if (vLeft != 0)
            for (int i = 0; i < partLeft.nums.size(); ++i)
                vLeft.nums.pop_back();
        partLeft -= partRes * right;
        sizeOst = partLeft.nums.size() - (long long)(partLeft == 0);
        if (partLeft != 0) {
            for (int i = 0; i < partLeft.nums.size(); ++i)
                vLeft.nums.push_back(partLeft.nums[i]);
        }
        result.nums.insert(result.nums.begin(), partRes);
        if (result.nums[(int)result.nums.size() - 1] == 0)
            result.nums.pop_back();

        while (vLeft.nums.size() && *(vLeft.nums.rbegin()) == 0) {
            vLeft.nums.pop_back();
            result.nums.insert(result.nums.begin(), 0);
        }
    }
    if (vLeft != 0 && (long long)vLeft.nums.size() > sizeOst) {
        long long oldSizeRes = result.nums.size();
        long long sizeZero = vLeft.nums.size() - sizeOst;
        long long cou = oldSizeRes + sizeZero;
        result.nums.resize(cou);
        for (int g = result.nums.size() - 1; g != result.nums.size() - 1 - oldSizeRes; --g)
            result.nums[g] = result.nums[g - sizeZero];
        for (int i = 0; i < vLeft.nums.size() - sizeOst; ++i)
            result.nums[i] = 0;
    }
    return left = result;
}

bign::BigNatural &bign::operator/=(BigNatural &left, const long long &right)
{
    bign::BigNatural newright = right;
    return left /= newright;
}

// %=
bign::BigNatural &bign::operator%=(BigNatural &left, const BigNatural &right)
{
    if (right == 0)
        throw(std::runtime_error("division by zero"));
    else if (left < right)
        return left = 0;
    BigNatural vLeft = left, partLeft;
    std::string part;
    long long sizeOst = 9223372036854775807;
    while (vLeft >= right) {
        part.reserve(right.nums.size() + 3);
        long long len = right.nums.size();
        do {
            part.clear();
            for (int g = vLeft.nums.size() - 1, end = vLeft.nums.size() - 1 - len; g > end && g >= 0; --g) {
                part.push_back(vLeft.nums[g] + '0');
            }
            partLeft = part;
            ++len;
        } while (partLeft < right);
        int partRes = 0;
        while (partRes * right <= partLeft)
            ++partRes;
        --partRes;
        if (vLeft != 0) {
            for (int i = 0; i < partLeft.nums.size(); ++i)
                vLeft.nums.pop_back();
        }
        partLeft -= partRes * right;
        sizeOst = partLeft.nums.size() - (long long)(partLeft == 0);
        if (partLeft != 0) {
            for (int i = 0; i < partLeft.nums.size(); ++i)
                vLeft.nums.push_back(partLeft.nums[i]);
        }
        while (vLeft.nums.size() && *(vLeft.nums.rbegin()) == 0)
            vLeft.nums.pop_back();
    }
    if (!vLeft.nums.size())
        vLeft.nums.push_back(0);
    return vLeft;
}

bign::BigNatural &bign::operator%=(BigNatural &left, const long long &right)
{
    BigNatural newRight = right;
    return left %= newRight;
}

// -
const bign::BigNatural bign::operator-(const BigNatural &left, const BigNatural &right)
{
    bign::BigNatural newleft = left;
    return newleft -= right;
}

const bign::BigNatural bign::operator-(const BigNatural &left, const long long &right)
{
    bign::BigNatural newleft = left;
    return newleft -= right;
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

// /
const bign::BigNatural bign::operator/(const BigNatural &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft /= right;
}

const bign::BigNatural bign::operator/(const BigNatural &left, const long long &right)
{
    bign::BigNatural newLeft = right;
    return newLeft /= right;
}

const bign::BigNatural bign::operator/(const long long &left, const BigNatural &right)
{
    bign::BigNatural newLeft = right;
    return newLeft /= right;
}

// %
const bign::BigNatural bign::operator%(const BigNatural &left, const BigNatural &right)
{
    BigNatural newLeft = left;
    return newLeft %= right;
}

const bign::BigNatural bign::operator%(const BigNatural &left, const long long &right)
{
    bign::BigNatural newLeft = right;
    return newLeft %= right;
}

const bign::BigNatural bign::operator%(const long long &left, const BigNatural &right)
{
    bign::BigNatural newLeft = right;
    return newLeft %= right;
}

// output
std::ostream &bign::operator<<(std::ostream &out, const BigNatural &obj)
{
    for (auto g = obj.nums.rbegin(); g != obj.nums.rend(); ++g) {
        out << *g;
    }
    return out;
}

// input
std::istream &bign::operator>>(std::istream &in, bign::BigNatural &obj)
{
    std::string t;
    in >> t;
    obj = t;
    return in;
}

// pow10
bign::BigNatural &bign::BigNatural::pow10(const BigNatural &k)
{
    for (BigNatural i = 0; i < k; ++i)
        nums.insert(nums.begin(), 0);
    return *this;
}

bign::BigNatural &bign::BigNatural::pow10(const long long &k)
{
    if (k < 0) {
        for (int i = 0; i < nums.size(); ++i) {
            if (k + i < nums.size()) {
                nums[i] ^= nums[k + i];
                nums[i + k] ^= nums[i];
                nums[i] ^= nums[k + i];
            } else
                nums[i] = 0;
        }
        while (nums.size() > 1 && nums.back() == 0)
            nums.pop_back();
    } else {
        unsigned long long szvec = nums.size();
        nums.resize(nums.size() + k);
        for (unsigned long long i = szvec - 1; i >= 0; --i) {
            nums[i + k] ^= nums[i];
            nums[i] ^= nums[i + k];
            nums[i + k] ^= nums[i];
            if (!i)
                break;
        }
    }
    return *this;
}

const bign::BigNatural bign::BigNatural::getSize() const
{
    return nums.size();
}

bign::BigNatural::operator bool() const
{
    return *this != 0;
}

// constructors
bign::BigNatural::BigNatural(const std::string &inum)
{
    if (inum.size() != 0) {
        nums.reserve(2 * inum.size());
        for (int i = inum.size() - 1; i >= 0; --i)
            if (inum[i] >= '0' && inum[i] <= '9') {
                nums.push_back(inum[i] - '0');
            } else {
                throw(std::runtime_error("[Exception] invalid input"));
            }
        while (nums.size() > 1 && nums.back() == 0) {
            nums.pop_back();
        }
    } else {
        throw(std::runtime_error("[Exception] invalid input"));
    }
}

bign::BigNatural::BigNatural(long long inum)
{
    if (inum > 0) {
        while (inum) {
            nums.push_back((inum % 10));
            inum /= 10;
        }
    } else if (inum == 0) {
        nums.push_back(0);
    } else {
        throw(std::runtime_error("[Exception] negative number"));
    }
}

bign::BigNatural::BigNatural(const BigNatural &inum)
{
    nums = inum.nums;
}

// destructor
bign::BigNatural::~BigNatural(void)
{
    ; // hello
}

const bign::BigNatural bign::GCD(const bign::BigNatural &left, bign::BigNatural &right)
{
    if (left == 0)
        return right;
    else if (right == 0)
        return left;
    bign::BigNatural newLeft, newRight, tmp;
    if (right < left) {
        newLeft = left;
        newRight = right;
    } else {
        newLeft = right;
        newRight = left;
    }
    while (newLeft % newRight) {
        tmp = newLeft;
        newLeft = newRight;
        newRight = tmp % newRight;
    }
    return newRight;
}

const bign::BigNatural bign::GCD(const bign::BigNatural &left, long long &right)
{
    bign::BigNatural castRight = right;
    return bign::GCD(left, castRight);
}

const bign::BigNatural bign::GCD(const long long &left, bign::BigNatural &right)
{
    bign::BigNatural castLeft = left;
    return bign::GCD(castLeft, right);
}

const bign::BigNatural bign::LCM(const BigNatural &left, BigNatural &right)
{
    return (left * right) / bign::GCD(left, right);
}

const bign::BigNatural bign::LCM(const BigNatural &left, long long &right)
{
    return (left * right) / bign::GCD(left, right);
}

const bign::BigNatural bign::LCM(const long long &left, BigNatural &right)
{
    return (left * right) / bign::GCD(left, right);
}

#include "BigNum.h"

BigNum::BigNum()
{
    initialize();
}

BigNum::BigNum(const BigNum &object)
{
    initialize();
    for (size_t i = 0; i < 32; i++)
    {
        data[i] = object.data[i];
    }
}
BigNum::~BigNum() {}

bool BigNum::areCoPrime(unsigned int a, unsigned int b)
{
    return __gcd(a, b) == 1;
}

bool BigNum::isPrime(long long int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (long long int i = 2; i < 10; i++)
        if (n % i == 0)
            return false;

    return true;
}

void BigNum::initialize()
{
    for (size_t i = 0; i < 32; i++)
    {
        m[i] = 1;
    }
    long long int currentNumber = INT_MAX;

    for (size_t i = 0; i < 32; i++)
    {
        bool isRelativelyPrimeWithAll = currentNumber % 2 != 0;
        for (size_t j = 0; isRelativelyPrimeWithAll && j < 32; j++)
        {
            if (!areCoPrime(currentNumber, m[j]) || !isPrime(currentNumber))
                isRelativelyPrimeWithAll = false;
        }
        if (isRelativelyPrimeWithAll)
        {
            m[i] = currentNumber;
        }
        else
        {
            i--;
        }
        currentNumber--;
    }

    for (size_t i = 0; i < 32; i++)
    {
        data[i] = 0;
    }
}

void BigNum::set(unsigned int v)
{
    for (size_t i = 0; i < 32; i++)
    {
        data[i] = v % m[i];
    }
}

void BigNum::add3(const BigNum &a, const BigNum &b)
{
    for (size_t i = 0; i < 32; i++)
    {

        data[i] = (a.data[i] + b.data[i]) % m[i];
    }
}

void BigNum::add2(const BigNum &a)
{
    for (size_t i = 0; i < 32; i++)
    {
        data[i] = (data[i] + a.data[i]) % m[i];
    }
}

void BigNum::sub3(const BigNum &a, const BigNum &b)
{
    for (size_t i = 0; i < 32; i++)
    {

        data[i] = (a.data[i] - b.data[i]) % m[i];
    }
}

void BigNum::sub2(const BigNum &a)
{
    for (size_t i = 0; i < 32; i++)
    {
        data[i] = (data[i] - a.data[i]) % m[i];
    }
}

void BigNum::mul3(const BigNum &a, const BigNum &b)
{
    for (size_t i = 0; i < 32; i++)
    {

        data[i] = (a.data[i] * b.data[i]) % m[i];
    }
}

void BigNum::mul2(const BigNum &a)
{
    for (size_t i = 0; i < 32; i++)
    {
        data[i] = (data[i] * a.data[i]) % m[i];
    }
}

void BigNum::divide(unsigned int v)
{

    long long int inverse[32];

    for (size_t i = 0; i < 32; i++)
    {
        inverse[i] = findInverse(v, m[i]);
    }

    for (size_t i = 0; i < 32; i++)
    {
        data[i] = (data[i] * inverse[i]) % m[i];
    }
}

string BigNum::toString()
{
    return rnsToString(data, m, 32);
}
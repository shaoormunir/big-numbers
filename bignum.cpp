using namespace std;
#include <cstddef>
#include <algorithm>
#include <bits/stdc++.h>
#include "rns.h"

class BigNum
{
private:
    long long int m[32];

    bool areCoPrime(unsigned int a, unsigned int b)
    {
        return __gcd(a, b) == 1;
    }

    bool isPrime(long long int n)
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

    void initialize()
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

public:
    long long int data[32];
    BigNum()
    {
        initialize();
    }

    BigNum(const BigNum &object)
    {
        initialize();
        for (size_t i = 0; i < 32; i++)
        {
            data[i] = object.data[i];
        }
    }
    void set(unsigned int v)
    {
        for (size_t i = 0; i < 32; i++)
        {
            data[i] = v % m[i];
        }
    }

    void add3(const BigNum &a, const BigNum &b)
    {
        for (size_t i = 0; i < 32; i++)
        {

            data[i] = (a.data[i] + b.data[i]) % m[i];
        }
    }

    void add2(const BigNum &a)
    {
        for (size_t i = 0; i < 32; i++)
        {
            data[i] = (data[i] + a.data[i]) % m[i];
        }
    }

    void sub3(const BigNum &a, const BigNum &b)
    {
        for (size_t i = 0; i < 32; i++)
        {

            data[i] = (a.data[i] - b.data[i]) % m[i];
        }
    }

    void sub2(const BigNum &a)
    {
        for (size_t i = 0; i < 32; i++)
        {
            data[i] = (data[i] - a.data[i]) % m[i];
        }
    }

    void mul3(const BigNum &a, const BigNum &b)
    {
        for (size_t i = 0; i < 32; i++)
        {

            data[i] = (a.data[i] * b.data[i]) % m[i];
        }
    }

    void mul2(const BigNum &a)
    {
        for (size_t i = 0; i < 32; i++)
        {
            data[i] = (data[i] * a.data[i]) % m[i];
        }
    }

    void divide(unsigned int v)
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

    string toString()
    {
        return rnsToString(data, m, 32);
    }
    ~BigNum() {}
};

using namespace std;
#include <cstddef>
#include <algorithm>
#include <bits/stdc++.h>
#include "rns.h"

class BigNum
{
private:
    long long int m[32];
    bool areCoPrime(unsigned int, unsigned int);
    bool isPrime(long long int);
    void initialize();

public:
    long long int data[32];
    BigNum();
    BigNum(const BigNum &);
    void set(unsigned int);
    void add3(const BigNum &, const BigNum &);
    void add2(const BigNum &);
    void sub3(const BigNum &, const BigNum &);
    void sub2(const BigNum &);
    void mul3(const BigNum &, const BigNum &);
    void mul2(const BigNum &);
    void divide(unsigned int);
    string toString();
    ~BigNum();
};
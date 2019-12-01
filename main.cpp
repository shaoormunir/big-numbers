using namespace std;

#include "BigNum.h"

void computeFactorial(BigNum &a)
{
    BigNum b(a);
    BigNum unit;
    unit.set(1);
    b.sub2(unit);

    while (b.toString() != "0")
    {
        a.mul2(b);
        b.sub2(unit);
    }
}

void computePower(BigNum &a, int power)
{
    BigNum b(a);

    for (size_t i = 1; i < power; i++)
    {
        a.mul2(b);
    }
}
int main(int argc, char const *argv[])
{
    BigNum a, b, c, d, e;
    // c.set(320);
    // c.divide(16);
    // cout << c.toString() << endl;
    // a.set(10);
    // b.set(20);
    // c.add3(a, b);
    // cout << c.toString() << endl;
    // c.add2(a);
    // cout << c.toString() << endl;
    // c.sub2(a);
    // cout << c.toString() << endl;
    // c.sub3(b, a);
    // cout << c.toString() << endl;

    // c.set(3);
    // computeFactorial(c);
    // cout << c.toString() << endl;

    // c.set(2);
    // computePower(c, 3);
    // cout << c.toString() << endl;

    a.set(8);
    b.set(3);
    c.set(12);
    d.set(2);

    computeFactorial(a);
    computeFactorial(c);
    computePower(b, 7);
    computePower(d, 10);

    e.mul3(a, b);
    e.mul2(c);
    e.mul2(d);
    cout << "Result of first operation is: " << e.toString() << endl;

    a.set(22);
    b.set(4);
    c.set(1);
    computePower(a, 35);
    d.mul3(a, b);
    d.sub2(c);
    d.divide(3);

    cout << "Result of fourth operation is: " << d.toString() << endl;
    return 0;
}

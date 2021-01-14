/*
 * @Author: seenli
 * @Date: 2021-01-14 19:25:41
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-14 19:40:30
 * @FilePath: \Tools_Code\operator_overloading.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    参考《C++程序设计 原理与实践》
    Chapter09 ex13
*/

#include "std_lib_facilities.h"

// 求两个数的最大公约数
int gcd(int a, int b)
{
    while (b != 0) {
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}

// 有理数的类
class Rational {
    public:
        // 构造函数
        Rational() :numer(0), denom(1) { }
        Rational(int n) :numer(n), denom(1) { }
        Rational(int n, int d) :numer(n), denom(d) { normalise(); }

        // 非修改 操作
        int get_numer() const { return numer; }
        int get_denom() const { return denom; }
        double conv_double() const { return double(numer)/denom; } // convert to double

        // 修改 操作
        void normalise()    // 分母为正且最小
        {
            if (denom == 0) error("denominator is zero");
            if (denom < 0) { denom = -denom; numer = -numer; }
            int n = gcd(numer,denom);
            if (n > 1) { numer /= n; denom /= n; }
        }

    private:
        int numer;  // 分子
        int denom;  // 分母
};

// 运算符
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);
ostream& operator<<(ostream& os, const Rational& r);

// ------------------------------------------------------------
// 实现

// 运算符
Rational operator+(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer()*r2.get_denom() + r1.get_denom()*r2.get_numer(),
        r1.get_denom()*r2.get_denom());
    r.normalise();
    return r;
}

Rational operator-(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer()*r2.get_denom() - r1.get_denom()*r2.get_numer(),
        r1.get_denom()*r2.get_denom());
    r.normalise();
    return r;
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer()*r2.get_numer(),r1.get_denom()*r2.get_denom());
    r.normalise();
    return r;
}


Rational operator/(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer()*r2.get_denom(),r1.get_denom()*r2.get_numer());
    r.normalise();
    return r;
}

bool operator==(const Rational& r1, const Rational& r2)
{
    return r1.get_numer()*r2.get_denom() == r1.get_denom()*r2.get_numer();
}

bool operator!=(const Rational& r1, const Rational& r2)
{
    return !(r1==r2);
}

ostream& operator<<(ostream& os, const Rational& r)
{
    return cout << '(' << r.get_numer() << '/' << r.get_denom() << ')';
}

int main()
try {
    // constructors
    Rational r1;
    Rational r2(5);
    Rational r3(7,3);
    cout << "r1: " << r1 << endl
        << "r2: " << r2 << endl
        << "r3: " << r3 << endl;

    // operators
    cout << "5/3 + 7/2 = " << Rational(5,3) + Rational(7/2) <<
        " = " << (Rational(5,3) + Rational(7/2)).conv_double() << endl;
    cout << "8/5 - 40/7 = " << Rational(8,5) - Rational(40,7) <<
        " = " << (Rational(8,5) - Rational(40,7)).conv_double() << endl;
    cout << "10/11 * 17/18 = " << Rational(10,11) * Rational(17,18) <<
        " = " << (Rational(10,11) * Rational(17,18)).conv_double() << endl;
    //cout << "5 / (0/3) = " << Rational(5) / Rational(0,3) << endl;
    cout << "(5/7) / (1/3) = " << Rational(5,7) / Rational(1,3) <<
        " = " << (Rational(5,7) / Rational(1,3)).conv_double() << endl;

    if (r1 == Rational(0,1)) cout << "r1 == 0/1" << endl;
    if (Rational(1,2) == Rational(2,4)) cout << "1/2 == 2/4" << endl;
    if (r2 != r2) cout << "r2 != r2" << endl;

    cout << r3 << " = " << r3.conv_double() << endl;
    system("pause");
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception" << endl;
}

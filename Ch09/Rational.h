/*
 * @Author: seenli
 * @Date: 2021-01-09 00:12:05
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-09 00:29:20
 * @FilePath: \Ch09\Rational.h
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
    public:
        Rational();
        Rational(int n, int d);

        // ��������غ���
        Rational& operator=(const Rational& a);

        // ��ʽת��
        operator double() const {return static_cast<double>(m_numerator) / m_denominator; }

        // ��������
        int get_numerator() const {return m_numerator; }
        int get_denominator() const {return m_denominator; }

    private:
        int m_numerator;
        int m_denominator;
        int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
};


// ���غ���
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);

#endif

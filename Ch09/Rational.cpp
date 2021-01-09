/*
 * @Author: seenli
 * @Date: 2021-01-09 00:11:49
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-09 13:11:45
 * @FilePath: \Ch09\Rational.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include "Rational.h"
#include <stdexcept>

Rational::Rational()
    : m_numerator{0}, m_denominator{1}
{}

Rational::Rational(int n, int d)
    : m_numerator{n}, m_denominator{d} {
        if (m_denominator == 0) {
            throw std::invalid_argument("denominator = 0");
        }
        int g{gcd(std::abs(n), std::abs(d))};
        if (g != 1) {
            m_numerator /= g;
            m_denominator /= g;
        }
}

Rational& Rational::operator=(const Rational& a) {
    // TODO self-assignment guard 是什么意思?
    if (this == &a) {
        return *this;
    }

    // copy
    m_numerator = a.m_numerator;
    m_denominator = a.m_denominator;

    // 返回现有的对象，这样就可以将这个操作符链接起来
    return *this;
}

Rational operator+(const Rational& a, const Rational& b) {
    // 通分
    int numerator = a.get_numerator() * b.get_denominator() + a.get_denominator() * b.get_numerator();
    int denominator = a.get_denominator() * b.get_denominator();
    return Rational(numerator, denominator);
}

Rational operator-(const Rational& a, const Rational& b) {
    int numerator = a.get_numerator() * b.get_denominator() - a.get_denominator() * b.get_numerator();
    int denominator = a.get_denominator() * b.get_denominator();
    return Rational(numerator, denominator);
}

Rational operator*(const Rational& a, const Rational& b) {
    int numerator = a.get_numerator() * b.get_numerator();
    int denominator = a.get_denominator() * b.get_denominator();
    return Rational(numerator, denominator);
}

Rational operator/(const Rational& a, const Rational& b) {
    if (b.get_numerator() == 0) throw std::invalid_argument("denominator=0");
    int numerator = a.get_numerator() * b.get_denominator();
    int denominator = a.get_denominator() * b.get_numerator();
    return Rational(numerator, denominator);
}

bool operator==(const Rational& a, const Rational& b) {
    if (a.get_numerator() == b.get_numerator() && a.get_denominator() == b.get_denominator()) {
        return true;
    }
    return false;
}


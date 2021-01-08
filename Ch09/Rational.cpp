/*
 * @Author: seenli
 * @Date: 2021-01-09 00:11:49
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-09 00:33:56
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



/*
 * @Author: seenli
 * @Date: 2021-01-28 11:52:00
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 11:52:23
 * @FilePath: \Ch15\ch15_try6.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 15, Try This 6: rewrite advance() so that it will "go backward" when
// you give it a negative argument

template<class Iter> void advance(Iter& p, int n)
{
    if (n>0) {
        while (n>0) { ++p; --n; }
    }
    else if (n<0) {
        while (n<0) { --p; ++n; }
    }
}

// That's right. Untested.
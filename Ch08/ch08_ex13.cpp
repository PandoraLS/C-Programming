/*
 * @Author: seenli
 * @Date: 2021-01-05 18:21:28
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-05 18:23:23
 * @FilePath: \Ch08\ch08_ex13.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Section 8 Exercise 13
	Can we declare a non-reference function const (e.g., void f(const int);)?
	- yes.
	What might that mean?
	- read only argument.  functional will not modify the argument is a compiler error if you try.
	Why don't people do that often?
	- not sure but should always assign as const if function is not modifying an argument.
*/

#include "ppp.h"

void f(const int n) {
    // n = 25;

    std::cout << n << std::endl;
}

int main() {
    int arg{15};
    f(arg);

    arg = 69;
    f(arg);

    system("pause");
    return 0;
}
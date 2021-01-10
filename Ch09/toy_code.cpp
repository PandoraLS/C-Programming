/*
 * @Author: seenli
 * @Date: 2021-01-06 13:39:36
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-09 17:05:58
 * @FilePath: \Ch09\hello.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


#include <iostream>
#include <cstdlib>
#include <tuple>
#include <array>

int main() {
    int n{27};
    int add_months{n / 12};
    std::cout << add_months << std::endl;
    n -= add_months * 12;
    std::cout << n << std::endl;

    if (!(2000 % 400)) {
        std::cout << "ÈòÄê" << std::endl;
    }
    system("pause");
    return 0;
}
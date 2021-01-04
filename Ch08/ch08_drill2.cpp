/*
 * @Author: seenli
 * @Date: 2021-01-03 23:15:46
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-04 13:55:56
 * @FilePath: \Ch08\ch08_drill2.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include <iostream>

void swap_v(int a, int b) {
    int temp{};
    temp = a;
    a = b;
    b = temp;
    std::cout << "*** In function swap_v() a: " << a << " b: " << b << std::endl;
}

void swap_r(int& a, int& b) {
    int temp{};
    temp = a;
    a = b;
    b = temp;
    std::cout << "*** In function swap_r() a: " << a << " b: " << b << std::endl;
}

int main() {
    int x{7}, y{9};
    std::cout << "x: " << x << " y: " << y << std::endl;
    swap_v(x, y);
    std::cout << "after swap_v() x: " << x << " y: " << y << "\n";
    swap_r(x, y);
	std::cout << "after swap_r() x: " << x << " y: " << y << "\n";
    std::cout << "-------------------------------------------------\n";

    system("pause");            // 最后保留住窗口
    return 0;
}
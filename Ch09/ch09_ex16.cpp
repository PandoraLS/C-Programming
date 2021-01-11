/*
 * @Author: seenli
 * @Date: 2021-01-11 13:42:34
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-11 13:47:06
 * @FilePath: \Ch09\ch09_ex16.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	Section 9 Exercise 16
	this is the test program Money class.
*/

#include "../includes/ppp.h"
#include "Money.h"

int main()
try {
    std::cout << "输入以货币代码(USD或DKK)为前缀的金额\n";

    Money m1, m2;
    std::cin >> m1 >> m2;
    std::cout << "m1 = " << m1 << '\n';
    std::cout << "m2 = " << m2 << '\n';
    std::cout << "m1 + m2 = " << m1 + m2 << '\n';

    system("pause");
    return 0;
}
catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
	ppp::keep_window_open();
	return 1;
}
catch (...) {
	std::cerr << "exception\n";
	ppp::keep_window_open();
	return 2;
}
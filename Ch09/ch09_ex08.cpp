/*
 * @Author: seenli
 * @Date: 2021-01-08 13:26:28
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-08 13:33:01
 * @FilePath: \Ch09\ch09_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	Section 9 Exercise 8
	Design and implement a Patron class under library namespace
*/

#include "ppp.h"
#include "Patron.h"

int main()
try {
    library::Patron patron{"John Doe", 123456};
    if (!patron.is_outstanding_fee()) {
        std::cout << patron.get_name() << " outstanding fees $" << patron.get_fees() << std::endl;
    }

    patron.set_fees(0.01);
    std::cout << patron.get_name() << " outstanding fee of $" << patron.get_fees() << std::endl;

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
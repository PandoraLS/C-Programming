/*
 * @Author: seenli
 * @Date: 2021-01-05 14:43:43
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-05 14:54:09
 * @FilePath: \Ch08\ch08_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Section 8 Exercise 9
	- Write a function maxv().
	- Return largest argument of the vectors elements
	- Check that vector is not empty.
*/

#include "ppp.h"

template <typename T>
T maxv(const std::vector<T>& v) {
    if (v.empty()) {
        ppp::error("Vector is empty!");
    }
    T largest{v.front()};
    for (auto elem : v) {
        if (largest < elem) {
            largest = elem;
        }
    }
    return largest;
}

int main()
try {
    std::vector<double> price{3.99, 4.5, 3.45};
    auto d{maxv(price)};
    std::cout << "Largest price: " << d << std::endl;
    std::vector<std::string> number{"one", "two", "three", "zero", "five"};
    auto str{maxv(number)};
    std::cout << "largest string: " << str << std::endl;
    system("pause");
    return 0;
}
catch(std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
	ppp::keep_window_open();
	return 1;
}
catch(...) {
	std::cerr << "exception\n";
	ppp::keep_window_open();
	return 2;
}

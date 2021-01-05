/*
 * @Author: seenli
 * @Date: 2021-01-05 14:09:06
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-05 14:42:40
 * @FilePath: \Ch08\ch08_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Section 8 Exercise 8
	- Write a function with 2 inputs of vector<double>s named price and weight.
	- Compute a value (an "index") that is the sum of all price[i] * weight[i].
	- Check the both vectors are of the same size.
*/

#include "ppp.h"

double compute_index(const std::vector<double>& price, const std::vector<double>& weight) {
    if (price.size() != weight.size()) {
        ppp::error("Vectors not the same size!");
    }
    double index{};
    for (std::vector<double>::size_type itr{}; itr != price.size(); ++itr) {
        index += price.at(itr) * weight.at(itr);
    }
    return index;
}

int main()
try {
    std::vector<double> price{3.99, 3.5, 3.45};
    std::vector<double> weight{4.99, 4.38, 4.31};
    auto idx{compute_index(price, weight)};
    std::cout << "index: " << idx << std::endl;

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

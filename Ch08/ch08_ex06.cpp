/*
 * @Author: seenli
 * @Date: 2021-01-04 20:13:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-04 20:16:45
 * @FilePath: \Ch08\ch08_ex06.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Section 8 Exercise 6
	Write 2 functions that reverse the element order in a vector<string>.
	One function should produce a new vector with the elements reversed, not affecting the original vector.
	The other should reverse the elements with out using a new vector.
*/

#include<iostream>
#include<string>
#include<vector>


using vect_values = std::vector<std::string>;

/**
 * @description: 将v逆序后放到rv中
 * @param {const} vect_values
 */
void reverse(const vect_values& v, vect_values& rv) {
    rv.clear();
    if (!v.empty()) {
        for (auto iv{v.crbegin()}; iv != v.crend(); ++iv) {
            rv.push_back(*iv);
        }
    }
}

/**
 * @description: 在原数组上倒序vector(使用临时vector)
 */
void reverse(vect_values& v) {
    if (!v.empty()) {
        auto rv{v};
        rv.clear();
        for (auto iv{v.crbegin()}; iv != v.crend(); ++iv) {
            rv.push_back(*iv);
        }
        v.swap(rv);     // 交换两个vector
    }
}


int main() {
    vect_values a{"zero", "one", "two", "three", "four", "five"};
    vect_values b;

    reverse(a, b);
    for (auto n : b) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    reverse(b);
    for (auto n : b) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}


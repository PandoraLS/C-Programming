/*
 * @Author: seenli
 * @Date: 2021-01-04 16:34:17
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-04 16:41:36
 * @FilePath: \Ch08\ch08_ex02.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/**
    Section 8 Exercise 2
	Write a function print() that prints a vector of ints to cout.
	Inputs: string for labeling
			vector
	Outputs: void
*/

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

void print(const std::string& label, const std::vector<int>& v) {
    std::cout << label << std::endl;
    for (auto i : v) {
        std::cout << i << std::endl;
    }
}

int main() {
    std::string label{"Printing some integers from a vector."};
    std::vector<int> vi{1, 2, 3, 4, 5};
    print(label, vi);

    system("pause");
    return 0;
}

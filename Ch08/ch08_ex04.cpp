/*
 * @Author: seenli
 * @Date: 2021-01-04 18:58:55
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-04 19:35:35
 * @FilePath: \Ch08\ch08_ex04.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


/**
    Section 8 Exercise 4
	using previous exercise to approximate the max limit of int type.
*/



#include<iostream>
#include<vector>
#include<string>
#include<sstream>

void print(const std::string& label, const std::vector<int>& v) {
    std::cout << label << std::endl;
    for (auto i : v) {
        std::cout << i << std::endl;
    }
}

int fibonacci(const int x, const int y, std::vector<int>& v, const int n) {
    int max{};
    v.push_back(x);
    v.push_back(y);
    for (int i{}; i < (n - 2); ++i) {
        auto num{v.at(i) + v.at(i + 1)};
        if (num < v.at(i + 1)) {
            max = v.at(i + 1);
            break;
        }
        v.push_back(num);
    }
    return max;
}

//TODO 这种近似方法，不是特别懂
int main() {
    int max_found{};
    std::vector<int> vi;
    std::vector<int> winner;
    for (int x{1}; x < 10000; ++x) {
        int y{x * 2};
        auto returned_value{fibonacci(x, y, vi, 100)};
        if (returned_value > max_found) {
            winner.clear();
            winner = vi;
            max_found = returned_value;
        }
        vi.clear();
    }
    std::stringstream ss;
    ss << "Print a Fibonacci sequence of length equal to " << winner.size() 
       << " and starting with " << winner.at(0) << " and " << winner.at(1) << '.';

    print(ss.str(), winner);
    std::cout << "\nThe approximate maximum limit on an \"int\" type is " << max_found << std::endl;

    system("pause");
    return 0;
}

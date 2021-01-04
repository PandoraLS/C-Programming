/*
 * @Author: seenli
 * @Date: 2021-01-04 16:38:43
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-04 16:56:23
 * @FilePath: \Ch08\ch08_ex03.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/**
    Section 8 Exercise 3
	Create a vector of Fibonacci numbers and print them using the function from exercise 2.
	To create the vector, write a function, fibonacci ( x , y , v , n ),
	where x and y are ints,
	v is an empty vector < int >,
	and n is the number of elements to put into v;
	v[0] will be x and v[1] will be y.
	A fibonacci number is one that is part of a sequence where each element is the sum of the two previous ones.
	For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . .
	Your Fibonacci( ) function should make such a sequence starting with its x and y arguments.
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

void fibonacci(const int x, const int y, std::vector<int>& v, const int n) {
    v.push_back(x);
    v.push_back(y);
    for (int i{}; i < (n - 2); ++i) {
        v.push_back(v.at(i) + v.at(i + 1));
    }
}

int main() {
    int x{1};
    int y{2};
    int how_many{10};
    std::stringstream ss;
    ss << "Print a Fibonacci sequence of length equal to " << how_many << " and starting with " << x << " and " << y << '.';

    std::vector<int> vi;
    fibonacci(x, y, vi, how_many);
    print(ss.str(), vi);

    system("pause");
    return 0;
}

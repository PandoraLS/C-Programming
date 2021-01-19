/*
 * @Author: seenli
 * @Date: 2021-01-19 18:57:19
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 20:05:47
 * @FilePath: \Ch11\ch11_ex16.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 16: read file of whitespace-separated numbers, output
// them in order, one value per line. if a value occurs more than once, write
// the count of its occurrences on its line.
//
// example: "7 5 5 7 3 117 5" should give
//  3
//  5   3
//  7   2
//  117
//
// Use ex16_in.txt for input


#include "../includes/std_lib_facilities.h"

int main()
try {
    string iname{"ex16_in.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    // 读取数字
    int n{};
    vector<int> numbers;
    while (ifs >> n) {
        numbers.push_back(n);
    }

    // 排序和输出
    sort(numbers.begin(), numbers.end());
    int counter = 1;

    for (int i{}; i < numbers.size(); ++i) {
        if (i == 0 || numbers[i] != numbers[i-1]) {
            if (counter > 1) {
                cout << "\t" << counter;
            }
            cout << endl;
            counter = 1;
            cout << numbers[i];
        } else {
            ++counter;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
	return 2;
}
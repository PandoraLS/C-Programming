/*
 * @Author: seenli
 * @Date: 2020-12-10 12:24:23
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-11 21:53:49
 * @FilePath: \Ch05\ch05_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 5 exercise 9
A program that reads and stores a series of integers.
Ask user to enter number(N) of integers want to sum.
Create a vector of the first N integers.
From that vector calculate the sum of those N integers.
Instruct user to terminate series with '|' when finished entering numbers.
Handle all inputs and provide and error N is larger than input vector

Added overflow error when summing
*/

#include "std_lib_facilities.h"

using vType = vector<int>;
vType::value_type add(vType::value_type n1, vType::value_type n2);

int main()
try{
    constexpr char termination{'|'};

    cout << "Enter how many numbers that you would like to sum:" << endl;
    int sumHowMany{};
    if (!(cin >> sumHowMany)) {
        error("number expected!");
    }

    // 存放输入数据的vector
    vType numbers;
    
    cout << "输入一些 number (通过 '" << termination << "' 结束输入)" << endl;
    while (true) {
        vType:: value_type number{};

        if (cin >> number) {
            numbers.push_back(number);
        } else if (cin.fail()) {
            cin.clear();        // 清除错误标志位

            // 检查输入的数字是否overflowed
            if (((number > 0) && (number > numeric_limits<vType::value_type>::max())) ||
                ((number < 0) && (-1.0 * number > numeric_limits<vType::value_type>::max()))) {
                error("Entered number overflowed number type!");
            }
            
            // 是否终止
            char c;
            cin >> c;
            if (c == termination) {
                break;
            }
            error("Invalid number or termination!");
        } else {
            error("Invalid fatal error caused termination!");
        }
    }

    // 检查number总数是否大于sumHowMany
    if (numbers.size() >= sumHowMany) {
        auto stop{numbers.begin() + sumHowMany};
        vType::value_type sum{};

        // 求和
        for (auto i{numbers.begin()}; i < stop; ++i) {
            sum = add(sum, *i);
        }

        // 输出结果
        cout << "The sum of the first " << sumHowMany << " numbers. " << endl;
        for (auto i = numbers.begin(); i < stop; ++i) {
            if (i == (stop - 1)) {
                cout << *i << " = " << sum << endl;
            } else {
                cout << *i << " + ";
            }
        }
    } else {
        cout << "Container was empty!" << endl;
    }

    keep_window_open();
    return 0;
}

catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}

catch (...) {
    cerr << "Oops: unknown exception" << endl;
    keep_window_open();
    return 2;
}


/**
 * @description: add function
 * @param {two number} 
 * @return {sum of two number}
 * @error: element overflow
 */
vType::value_type add(vType::value_type n1, vType::value_type n2) {
    vType::value_type sum{};
    if (((n2 > 0) && (n1 > (numeric_limits<vType::value_type>::max() - n2))) ||
        ((n2 < 0) && (n1 < (numeric_limits<vType::value_type>::min() - n2)))) {
            error("overflow error");
    }
    return n1 + n2;
}


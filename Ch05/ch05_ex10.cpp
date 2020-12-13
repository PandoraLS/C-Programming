/*
 * @Author: seenli
 * @Date: 2020-12-11 13:34:40
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-13 15:28:28
 * @FilePath: \Ch05\ch05_ex10.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 5 exercise 10
A program that reads and stores a series of doubles.
Ask user to enter number(N) of doubles want to sum.
Create a vector of the first N doubles.
From that vector calculate the sum of those N doubles.
Also  provide a vector of the delta between delta[1] - delta[0], ..., delta[N] - delta[N-1].
Instruct user to terminate series with '|' when finished entering numbers.
Handle all inputs and provide and error N is larger than input vector
*/

#include "std_lib_facilities.h"

using vType = vector<double>;
vType::value_type add(vType::value_type si_a, vType::value_type si_b);
vType::value_type subtract(vType::value_type si_a, vType::value_type si_b);

int main()
try {
    constexpr char termination{'|'};

    cout << "Enter how many numbers that you would like to sum: " << endl;
    int sumHowMany{};
    if (!(cin >> sumHowMany)) {
        error("number expected");
    }

    // vector to hold the entered numbers
    vType numbers;
    cout << "Enter some numbers. (use '" << termination << "' to stop)" << endl;

    while (true) {
        vType::value_type number{};

        if (cin >> number) {
            numbers.push_back(number);
        } else {
            cin.clear();        // 清除错误标志位

            // 检查输入的数字是否overflowed
            if (((number > 0) && (number > numeric_limits<vType::value_type>::max())) ||
                ((number < 0) && (-1.0 * number > numeric_limits<vType::value_type>::max()))) {
                error("Entered number overflowed number type!");
            }
            
            // 检查终止符
            char c;
            cin >> c;
            if (c == termination) {
                break;
            }
            error("Invalid number or termination!");
        }
    }

    // do we have some numbers?
    if (numbers.size() >= sumHowMany) {
        vType::iterator stop{numbers.begin() + sumHowMany};
        vType::value_type sum{};

        // sum and check for overflows
        for (auto i{numbers.begin()}; i < stop; ++i) {
            sum = add(sum, *i);
        }

        // 输出结果
        cout << "The sum of the first " << sumHowMany << " numbers." << endl;
        for (auto i{numbers.begin()}; i < stop; ++i) {
            if (i == (stop - 1)) {
                cout << *i << " = " << sum << endl;
            } else {
                cout << *i << " + ";
            }
        }

        if (numbers.size() > 1) {
            cout << "相邻元素差为" << endl;
            for (auto i{numbers.begin() + 1}; i < numbers.end(); ++i) {
                cout << *i << " - " << *(i - 1) << " = " << subtract(*i, *(i - 1)) << endl;
            }
        }
    } else {
        cout << "Container was empty." << endl;
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
    cerr << "Oops: unknown exception!" << endl;
    keep_window_open();
    return 2;
}


//TODO double的overflow条件与INT不一样(double的max()和min()均是正数)
// 所以这里没有进一步处理
/**
 * @description: addition function.
 * @param {two numbers}
 * @return {sum of inputs}
 * @error: element overflow
 */
vType::value_type add(vType::value_type si_a, vType::value_type si_b) {
    return si_a + si_b;
}


/**
 * @description: subtraction
 * @param {two numbers}
 * @return {diff of inputs}
 * @error: element overflow
 */
vType::value_type subtract(vType::value_type si_a, vType::value_type si_b) {
    return si_a - si_b;
}

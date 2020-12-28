/*
 * @Author: seenli
 * @Date: 2020-12-28 12:50:31
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-28 13:28:22
 * @FilePath: \Ch06\ch06_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 6 exercise 9
read digits and compose them into integers. For example, 123 is read as the characters 1, 2, and 3.
Output of 123 is 1 hundred and 2 tens and 3 ones.
The numbers is output as int value.
Handle up to 4 digits.
terminate program with '|'.
*/

#include "std_lib_facilities.h"

void print_number(const string& num, const vector<string>& den);

int main()
try {
    constexpr char termination = '|';
    const vector<string> denomination{"ones", "tens", "hundreds", "thousands"};

    bool LoopAgain{true};
    do {
        cout << "Enter a number up to " << denomination.size() << " digits long. Enter " << termination << " to exit" << endl;
        string number;
        size_t itr{};

        char digit{};
        while (cin.get(digit)) {
            if (digit == '\n') {
                print_number(number, denomination);
                break;
            } else if (!isdigit(digit)) {
                if (digit == termination) {
                    LoopAgain = false;
                    break;
                }
                error("found a non number character");
            } else {
                if (itr > denomination.size()) {
                    error("entered number is to large");
                }
                number.push_back(digit);
                ++itr;
            }
        }
    } while (LoopAgain && cin);
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Unknown error" << endl;
    keep_window_open();
    return 2;
}

/**
 * @description: 
 * @param {const} string num: 字符串组成的num
 * @param {const} vector den: 对应数值的面值(个十百千)
 */
void print_number(const string& num, const vector<string>& den) {
    if (num.empty()) {
        cout << "no number was entered" << endl;
    } else {
        cout << num << " is ";
        for(size_t i{}, j{num.size() - 1}; i < num.size(); ++i, --j) {
            cout << num.at(i) << " " << den.at(j) << ((i < num.size() - 1) ? " and " : ".\n");
        }
    }
}

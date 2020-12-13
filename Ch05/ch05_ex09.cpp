/*
 * @Author: seenli
 * @Date: 2020-12-10 12:24:23
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-13 14:57:57
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
vType::value_type add(vType::value_type si_a, vType::value_type si_b);

int main()
try{
    constexpr char termination{'|'};

    cout << "Enter how many numbers that you would like to sum:" << endl;
    int sumHowMany{};
    if (!(cin >> sumHowMany)) {
        error("number expected!");
    }

    // ����������ݵ�vector
    vType numbers;
    
    cout << "����һЩ number (ͨ�� '" << termination << "' ��������)" << endl;
    while (true) {
        vType:: value_type number{};

        if (cin >> number) {
            numbers.push_back(number);
        } else if (cin.fail()) {
            cin.clear();        // ��������־λ

            // �������������Ƿ�overflowed
            if (((number > 0) && (number > numeric_limits<vType::value_type>::max())) ||
                ((number < 0) && (-1.0 * number > numeric_limits<vType::value_type>::max()))) {
                error("Entered number overflowed number type!");
            }
            
            // �Ƿ���ֹ
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

    // ���number�����Ƿ����sumHowMany
    if (numbers.size() >= sumHowMany) {
        auto stop{numbers.begin() + sumHowMany};
        vType::value_type sum{};

        // ���
        for (auto i{numbers.begin()}; i < stop; ++i) {
            sum = add(sum, *i);
        }

        // ������
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


// ���������Խ���ж�(�з�������)
// https://wiki.sei.cmu.edu/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow
/**
 * @description: add function
 * @param {two number} 
 * @return {sum of two number}
 * @error: element overflow
 */
vType::value_type add(vType::value_type si_a, vType::value_type si_b) {
    vType::value_type sum{};
    if (((si_b > 0) && (si_a > (numeric_limits<vType::value_type>::max() - si_b))) ||
        ((si_b < 0) && (si_a < (numeric_limits<vType::value_type>::min() - si_b)))) {
            error("overflow error");
    } else {
        sum = si_a + si_b;
    }
    return sum;
}


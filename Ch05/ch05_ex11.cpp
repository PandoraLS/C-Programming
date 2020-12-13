/*
 * @Author: seenli
 * @Date: 2020-12-11 21:57:54
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-13 16:29:14
 * @FilePath: \Ch05\ch05_ex11.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


/*
Section 5 exercise 11
A program that writes out the Fibonacci series up to largest to fit in an int type
*/


#include "std_lib_facilities.h"

// using vType = vector<unsigned>;
using vType = vector<int>;
vType::value_type add(vType::value_type si_a, vType::value_type si_b);

int main()
try{
    vType fibonacci{1, 1};
    for(vType::difference_type i{};/*故意没有条件*/; i++) {
        cout << fibonacci[i] << endl;
        fibonacci.push_back(add(fibonacci[i],fibonacci[i+1]));
    }

    keep_window_open(); // yes I know will never get to this point
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


/**
 * @description: unsigned add
 * @param {*}
 * @return {*}
 */
vType::value_type add(vType::value_type si_a, vType::value_type si_b) {
    if ((si_a <= 0) || (si_b <= 0)) {
        error("overflow error");
    }
    if (si_a > numeric_limits<vType::value_type>::max() - si_b) {
        error("overflow error");
    }
    return si_a + si_b;
}

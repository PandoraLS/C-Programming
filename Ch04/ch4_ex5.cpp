/*
 * @Author: seenli 
 * @Date: 2020-12-01 13:24:53 
 * @Last Modified by:   seenli 
 * @Last Modified time: 2020-12-01 13:24:53 
 */

/*
    Section 4 exercise 5.
    Write a program that performs as a very simple calculator.
    Your calculator should be able to handle the four basic math operations — add, subtract, multiply, and divide — on two input values.
    Your program should prompt the user to enter three arguments: two double values and a character to represent an operation.
    If the entry arguments are 35.6, 24.1, and '+', the program output should be The sum of 35.6 and 24.1 is 59.7.
*/


#include "std_lib_facilities.h"

double add(double arg1, double arg2) {
    return arg1 + arg2;
}

double subtract (double arg1, double arg2) {
    return arg1 - arg2;
}

double multiply (double arg1, double arg2) {
    return arg1 * arg2;
}

double divide (double arg1, double arg2) {
    if (arg2 == 0) {
        simple_error("division by zero is not allowed. \n");
    }
    return arg1 / arg2;
}

using opt = double(*) (double, double);        // 

unordered_map<char, opt> calculate {
    {'+', add}, 
    {'-', subtract},
    {'*', multiply},
    {'/', divide}
};

int main() {
    cout << "输入2个数和一个字符(+, -, *, /). :\n";
    double arg1{}, arg2{};
    if (!(cin >> arg1 >> arg2)) {
        simple_error("输入错误\n");
    }
    char op{};
    cin >> op;
    auto itr{calculate.find(op)};
    if (itr == calculate.end()) {
        simple_error("输入错误\n");
    }
    // cout << arg1 << " " << op << " " << arg2 << " = " << itr->second(arg1, arg2) << endl;
    cout << arg1 << " " << itr->first << " " << arg2 << " = " << itr->second(arg1, arg2) << endl;
    // itr->first对应的就是操作符，itr->second对应的就是具体操作函数

    keep_window_open();
    return 0;
}


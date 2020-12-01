/*
 * @Author: seenli 
 * @Date: 2020-10-10 12:48:40 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-01 15:45:24
 */


/*
Section 4 exercise 7.
Modify the "mini calculator from exercise 5 to accept (just) single-digit numbers written as either digits
or spelled out.
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

// 检查输入是否为阿拉伯数字, 如果是拼写则转化为阿拉伯数字 
bool getNumber(double& arg, const vector<string>& spelledNumbers) {
    if (cin >> arg) {
        return true;
    }

    // 检查number是否为拼写
    cin.clear();        // 清除错误标志位
    string spelledNumber;
    cin >> spelledNumber;

    // convert to lower
    transform(spelledNumber.begin(), spelledNumber.end(), spelledNumber.begin(), [](char c){
       return static_cast<unsigned char>(tolower(c)); 
    });

    // 检查是否是spelled out number (有可能输入的字符串是不是spelledNumbers中的那些)
    auto spelledIndex = find(spelledNumbers.begin(), spelledNumbers.end(), spelledNumber);
    if (spelledIndex == spelledNumbers.end()) {
        return false;
    }

    arg = static_cast<int>(spelledIndex - spelledNumbers.begin());
    return true;
}

using opt = double(*) (double, double);

unordered_map<char, opt> calculate {
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/',divide}
};

const vector<string> spelledNumbers {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int main() {
    cout << "输入2个数和一个字符(+, -, *, /). :\n";
    cout << "Number entered must be between 0 and 9 either spelled out or as the number.\n\n";
    double arg1{}, arg2{};
    if (!getNumber(arg1, spelledNumbers) || !getNumber(arg2, spelledNumbers)) {
        simple_error("incorrect numbers entered. \n");
    }
    char op{};
    cin >> op;
    auto itr{calculate.find(op)};
    if(itr == calculate.end()) {
        simple_error("incorrect numbers entered. \n");
    }
    cout << arg1 << " " << op << " " << arg2 << " = " << itr->second(arg1, arg2) << endl;
    keep_window_open();
    return 0;
}


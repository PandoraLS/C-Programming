/*
 * @Author: seenli 
 * @Date: 2020-12-09 19:47:31 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-09 20:20:56
 */

#include "std_lib_facilities.h"

int main()
try {
    constexpr char termination{'|'};
    using vType = vector<int>;

    cout << "Enter how many numbers that you would like to sum:" << endl;

    int sumHowMany{};
    if (!(cin >> sumHowMany)) {
        error("number expected!");
    }

    vType numbers;
    cout << "Enter some numbers (press '" << termination << "' to stop)" << endl;
    // 循环读入数据, '|'用于退出
    while (true) {
        vType::value_type number{};
        // vector载入数据
        if (cin >> number) {
            numbers.push_back(number);
        } else {
            cin.clear();        // 清除标志位
            char c{};
            cin >> c;
            if (c == termination) {
                break;
            }
            error("Invalid number of termination!");
        }
    }

    if (numbers.size() >= sumHowMany) {
        vType::iterator stop{numbers.begin() + sumHowMany};
        // 
    }
}

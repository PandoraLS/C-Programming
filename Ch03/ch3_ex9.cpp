/*
 * @Author: seenli 
 * @Date: 2020-10-04 14:53:20 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 15:10:11
 */


#include "std_lib_facilities.h"

int main() {
    cout << "请输入一个数字的字符串 (example \"two\" for 2) type \"quit\" to exit: \n";
    string str;
    while (cin >> str) {
        int val {INT8_MIN};     // (-128)
        if (str == "zero") {
            val = 0;
        } else if (str == "one") {
            val = 1;
        } else if (str == "two") {
            val = 2;
        } else if (str == "three") {
            val = 3;
        } else if (str == "four") {
            val = 4;
        } else if (str == "quit") {
            break;
        } else {
            cout << "输入字符串无法转换, 请重试!\n";
        }

        if (val >= 0) {
            cout << "输入数字英文 " << str << " 对应阿拉伯数字 " << val << endl;
        }
    }
    keep_window_open();
    return 0;
}


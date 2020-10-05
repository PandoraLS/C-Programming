/*
 * @Author: seenli 
 * @Date: 2020-10-05 21:37:33 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 00:13:05
 */

#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // 终止符
    const string instructions{"输入两个数字或输入 " + string{terminationChar} + " 终止输入."};
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);
        static int val1{};
        static int val2{};
        if (cin >> val1 >> val2) {
            cout << "输入数字: " << val1 << " " << val2 << '\n';
        } else {
            cin.clear();
            cin.get(c);
            if (c == terminationChar) {
                break;
            }
            cout << "Entry was an invalid number or termination, please try again. \n";
        }
        cout << instructions << '\n';
    }

    keep_window_open();
    return 0;
}
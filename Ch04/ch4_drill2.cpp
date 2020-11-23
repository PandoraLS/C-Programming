/*
 * @Author: seenli 
 * @Date: 2020-10-06 14:18:06 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 19:14:25
 */



#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // 终止符
    const string instructions{"输入两个整型数字或输入 " + string{terminationChar} + " 终止输入."};
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);
        static int val1{};
        static int val2{};
        if (cin >> val1 >> val2) {
            if (val1 > val2) {
                swap(val1, val2);       // #include <algorithm>
            }
            cout << "smaller value is " << val1 << " and the larger value is " << val2 << '\n';
        } else {    // 如果输入的不是数字, 则用cin.clear()复原错误标志位，然后从缓存区获取输入的字符c
            cin.clear();
            cin.get(c);		// 从输入流中重新获取字符
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


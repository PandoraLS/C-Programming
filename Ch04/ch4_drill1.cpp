/*
 * @Author: seenli 
 * @Date: 2020-10-05 21:37:33 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 14:16:56
 */

/*
 * 程序依然存在一些bug, 当输入的是小数的时候, 由于cin.get()和cin.putback()的工作机制, 输入的小数点会被识别为非法字符,
 * 但是小数点后的数字确被保留下来成为了下一次输入的第一个数字, 然后就混乱了
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
            cout << "输入数字: " << val1 << " " << val2 << '\n';
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
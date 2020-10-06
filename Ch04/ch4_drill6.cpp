/*
 * @Author: seenli 
 * @Date: 2020-10-06 14:51:56 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 21:26:44
 */

#include <cfloat>
#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // 终止符
    const string instructions{"输入1个double型数字或输入 " + string{terminationChar} + " 终止输入."};
    constexpr double tolerance = 1.0 / 100;     // 误差精度
    cout << instructions << "\n";
    double val{};
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);     // 将c放回输入流
        static double min{DBL_MAX};
        static double max{DBL_MIN};

        if (cin >> val) {
            cout << val;
            if (val < min) {
                min = val;
                cout << " the smallest so far \n";
            }
            if (val > max) {
                max = val;
                cout << " the largest soo far \n";
            }
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

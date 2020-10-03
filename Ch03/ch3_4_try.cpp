/*
 * @Author: seenli 
 * @Date: 2020-10-03 15:07:32 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 15:34:56
 */

/*
 * Section 3.4 try this exercise
 */

#include "std_lib_facilities.h"

int main() {
    cout << "输入int数:";
    int n{}; // 初始化为0
    cin >> n;
    cout << "n == " << n << endl
        << "n+1 == " << n + 1 << endl
        << "3 * n == " << 3 * n << endl
        << "n + n == " << n + n << endl
        << "n * n == " << n * n << endl
        << "n / 2 == " << n / 2 << endl
        << "sqrt(n) == " << sqrt(n) << endl;
    keep_window_open();
    return 0;
}

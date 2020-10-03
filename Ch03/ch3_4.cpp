/*
 * @Author: seenli 
 * @Date: 2020-10-03 15:02:58 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 15:05:50
 */

#include "std_lib_facilities.h"
int main() {
    cout << "ÊäÈë¸¡µãÊý:";
    double n;
    cin >> n;
    cout << "n == " << n
        << "\nn+1 == " << n + 1
        << "\nthree times n == " << 3 * n
        << "\ntwice n == " << n + n
        << "\nn squared == " << n * n
        << "\nhalf of n == " << n / 2
        << "\nsquare root of n == " << sqrt(n)
        << "\n";
    keep_window_open();
    return 0;
}
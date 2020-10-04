/*
 * @Author: seenli 
 * @Date: 2020-10-04 10:36:31 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 11:37:06
 */

// 参考PPP2中的实现

#include "std_lib_facilities.h"

int main() {
    cout << "请输入两个数: \n";
    int val1{}, val2{};
    if(!(cin >> val1 >> val2))
        simple_error("Invalid entry!");
    
    if(val1 < val2){
        cout << val1 << " < " << val2 << endl;
    } else if(val1 > val2){
        cout << val2 << " < " << val1 << endl;
    } else if(val1 == val2){
        cout << val1 << " = " << val2 << endl;
    } else {
        simple_error("Not sure how I got here?");
    }

    cout << val1 << " + " << val2 << " = " << val1 + val2 << endl;
    cout << val1 << " - " << val2 << " = " << val1 - val2 << endl;
    cout << val1 << " * " << val2 << " * " << val1 * val2 << endl;
    if (val2 == 0) {
        simple_error("division by 0");
    } else {
        cout << "The ratio of " << val1 << " and " << val2 << " is " << static_cast<double>(val1) /
        static_cast<double>(val2) << endl;
    }
    
    keep_window_open();
    return 0;
}

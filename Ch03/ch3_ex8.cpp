/*
 * @Author: seenli 
 * @Date: 2020-10-04 14:44:10 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 14:53:12
 */


#include "std_lib_facilities.h"

int main() {
    cout << "请输入一个int数字:\n";
    int num{};
    if (!(cin >> num))
        simple_error("Invalid entry!");
    
    // if (num % 2 == 0)
    //     cout << "The value " << num << " is an even number. \n";
    // else
    //     cout << "The value " << num << " is an odd number. \n";

    // 换种写法
    cout << "The value " << num << " is an " << ((num % 2) ? "odd" : "even") << " number. \n";
    
    keep_window_open();
    return 0;
}

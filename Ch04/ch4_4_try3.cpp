/*
 * @Author: seenli 
 * @Date: 2020-10-05 20:20:39 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-05 20:26:40
 */

#include "std_lib_facilities.h"

int main() {
    int i {97};
    while (i < 123){
        // cout << char(i++) << " " << i-1 << endl;
        cout << static_cast<char>(i) << "\t" << i << endl;      // 比较安全的类型转换
        ++i;
    }
    keep_window_open();
    return 0;
}
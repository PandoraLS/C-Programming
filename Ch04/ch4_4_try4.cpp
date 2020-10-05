/*
 * @Author: seenli 
 * @Date: 2020-10-05 20:26:56 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-05 20:31:14
 */

#include "std_lib_facilities.h"

int main() {
    for (int i {97}; i < 123; i++){
        cout << static_cast<char>(i) << "\t" << i << endl;
    }
    keep_window_open();
    return 0;
}
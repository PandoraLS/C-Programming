/*
 * @Author: seenli 
 * @Date: 2020-10-03 20:27:21 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 20:44:30
 */

#include "std_lib_facilities.h"

int main(){
    cout << "输入英里：EOF 或 Ctrl-Z 退出 \n";
    double miles {};
    if (cin >> miles){
        cout << miles << " 英里 = " << miles * 1.609 << " 公里" << endl;
    } else {
        simple_error("Invalid entry");  // 这里直接就退出了
    }
    
    keep_window_open();
    return 0;
}
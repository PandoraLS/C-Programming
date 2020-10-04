/*
 * @Author: seenli 
 * @Date: 2020-10-04 15:10:58 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 15:28:19
 */


#include "std_lib_facilities.h"

int main() {
    cout << "输入字符串和两个操作数: ";
    string operation;
    double val1{}, val2{};
    cin >> operation;

    if (!(cin >> val1 >> val2))
        simple_error("Invalid entry!");
    
    if (operation == "+") {
        cout << "Result = " << val1 + val2 << endl;
    } else if (operation == "-") {
        cout << "Result = " << val1 - val2 << endl;
    } else if (operation == "*") {
        cout << "Result = " << val1 * val2 << endl;
    } else if (operation == "/") {
        if (val2 != 0){
            cout << "Result = " << val1 / val2 << endl;
        } else {
            simple_error("division by 0");
        }
    } else {
        simple_error("Unknown operation");
    }
    keep_window_open();
    return 0;
}


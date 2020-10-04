/*
 * @Author: seenli 
 * @Date: 2020-10-04 12:07:24 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 14:42:42
 */

// 把ch3_ex6.cpp稍微修改一下就ok了

#include "std_lib_facilities.h"

int main() {
    cout << "请输入3个字符串: \n";
    string val1, val2, val3;
    string minValue, midValue, maxValue;
    cin >> val1 >> val2 >> val3;
    if (val1 <= val2 && val1 <= val3) {
        if (val2 <= val3) {
            minValue = val1;
            midValue = val2;
            maxValue = val3;
        } else {
            minValue = val1;
            midValue = val3;
            maxValue = val2;
        }
    } else if (val2 <= val1 && val2 <= val3) {
        if (val1 <= val3) {
            minValue = val2;
            midValue = val1;
            maxValue = val3;
        } else {
            minValue = val2;
            midValue = val3;
            maxValue = val1;
        }
    } else {
        if (val1 <= val2) {
            minValue = val3;
            midValue = val1;
            maxValue = val2;
        } else {
            minValue = val3;
            midValue = val2;
            maxValue = val1;
        }
    }
    cout << minValue << "," << midValue << "," << maxValue << endl;
    keep_window_open();
    
    return 0;
}
/*
 * @Author: seenli 
 * @Date: 2020-10-04 11:23:53 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 12:06:44
 */

/*
 * 总共6种可能性，先判断v1, v2, v3依次最小，全排列比较就ok了 
*/


#include "std_lib_facilities.h"

int main() {
    cout << "输入三个整形数字: \n";
    int val1{}, val2{}, val3{}; // 定以并初始化(为0)三个数
    int minValue{}, midValue{}, maxValue{}; // 用于存储大中小三个数
    if (!(cin >> val1 >> val2 >> val3))
        simple_error("Invalid entry!");
    
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


/*
 * @Author: seenli 
 * @Date: 2020-10-04 11:23:53 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 12:06:44
 */

/*
 * �ܹ�6�ֿ����ԣ����ж�v1, v2, v3������С��ȫ���бȽϾ�ok�� 
*/


#include "std_lib_facilities.h"

int main() {
    cout << "����������������: \n";
    int val1{}, val2{}, val3{}; // ���Բ���ʼ��(Ϊ0)������
    int minValue{}, midValue{}, maxValue{}; // ���ڴ洢����С������
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


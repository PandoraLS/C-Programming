/*
 * @Author: seenli 
 * @Date: 2020-10-04 14:53:20 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 15:10:11
 */


#include "std_lib_facilities.h"

int main() {
    cout << "������һ�����ֵ��ַ��� (example \"two\" for 2) type \"quit\" to exit: \n";
    string str;
    while (cin >> str) {
        int val {INT8_MIN};     // (-128)
        if (str == "zero") {
            val = 0;
        } else if (str == "one") {
            val = 1;
        } else if (str == "two") {
            val = 2;
        } else if (str == "three") {
            val = 3;
        } else if (str == "four") {
            val = 4;
        } else if (str == "quit") {
            break;
        } else {
            cout << "�����ַ����޷�ת��, ������!\n";
        }

        if (val >= 0) {
            cout << "��������Ӣ�� " << str << " ��Ӧ���������� " << val << endl;
        }
    }
    keep_window_open();
    return 0;
}


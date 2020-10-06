/*
 * @Author: seenli 
 * @Date: 2020-10-06 14:51:56 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 21:26:44
 */

#include <cfloat>
#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // ��ֹ��
    const string instructions{"����1��double�����ֻ����� " + string{terminationChar} + " ��ֹ����."};
    constexpr double tolerance = 1.0 / 100;     // ����
    cout << instructions << "\n";
    double val{};
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);     // ��c�Ż�������
        static double min{DBL_MAX};
        static double max{DBL_MIN};

        if (cin >> val) {
            cout << val;
            if (val < min) {
                min = val;
                cout << " the smallest so far \n";
            }
            if (val > max) {
                max = val;
                cout << " the largest soo far \n";
            }
        } else {    // �������Ĳ�������, ����cin.clear()��ԭ�����־λ��Ȼ��ӻ�������ȡ������ַ�c
            cin.clear();
            cin.get(c);		// �������������»�ȡ�ַ�
            if (c == terminationChar) {
                break;
            }
            cout << "Entry was an invalid number or termination, please try again. \n";
        }
        cout << instructions << '\n';
    }
    
    keep_window_open();
    return 0;
}

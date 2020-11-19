/*
 * @Author: seenli 
 * @Date: 2020-10-05 21:37:33 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 14:16:56
 */

/*
 * ������Ȼ����һЩbug, ���������С����ʱ��, ����cin.get()��cin.putback()�Ĺ�������, �����С����ᱻʶ��Ϊ�Ƿ��ַ�,
 * ����С����������ȷ������������Ϊ����һ������ĵ�һ������, Ȼ��ͻ�����
 */


#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // ��ֹ��
    const string instructions{"���������������ֻ����� " + string{terminationChar} + " ��ֹ����."};
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);
        static int val1{};
        static int val2{};
        if (cin >> val1 >> val2) {
            cout << "��������: " << val1 << " " << val2 << '\n';
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
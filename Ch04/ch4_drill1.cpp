/*
 * @Author: seenli 
 * @Date: 2020-10-05 21:37:33 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 19:11:36
 */

/*
 * ������Ȼ����һЩbug, ���������С����ʱ��(��Ȼ��ĿֻҪ������int��ʽ���ַ���), ����cin.get()��cin.putback()�Ĺ�������, �����С����ᱻʶ��Ϊ�Ƿ��ַ�,
 * ����С����������ȷ������������Ϊ����һ������ĵ�һ������, Ȼ��ͻ�����
 */


#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // ��ֹ��
    const string instructions{"���������������ֻ����� " + string{terminationChar} + " ��ֹ����."};
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        // ����� c != terminationChar ���ڵ�һ�ξ�������ֹ��"|"�������������
        cin.putback(c);     // ��ǰ����get())���������ж�ȡ���ַ�c���ص�������
        static int val1{};  // ����Ϊ static ��Ŀ���Ǳ���ÿ��while�����¿���
        static int val2{};
        if (cin >> val1 >> val2) {
            cout << "��������: " << val1 << " " << val2 << '\n';
        } else {    
            // �������Ĳ�������, ����cin.clear()��ԭ�����־λ��Ȼ��ӻ�������ȡ������ַ�c
            // �������ַ�Ϊ "|"���˳�������Ϊ�Ƿ��ַ�
            cin.clear();    // �������־λ�޸�Ϊ0
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

/*
 * @Author: seenli 
 * @Date: 2020-10-04 15:29:16 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 16:22:06
 */


// PPP2 �е�ʵ��

#include "std_lib_facilities.h"

int main() {
    const vector<string> op{"+", "-", "*", "/"};
    cout << "������ 1�� operation �� 2 ����������\n";

    string operation;
    cin >> operation;

    // ����operation�Ƿ���op�г��ֹ���
    if (find(op.cbegin(), op.cend(), operation) == op.cend()){
        simple_error("Bad operator");   // Bad �����
    }

    double val1{}, val2{};
    if (!(cin >> val1 >> val2)){
        simple_error("Bad operands");   // Bad ������
    }

    double result{};
    if (operation == "+") {
        result = val1 +val2;
        operation = "+";
    } else if (operation == "-") {
        result = val1 - val2;
        operation = "-";
    } else if (operation == "*") {
        result = val1 * val2;
        operation = "*";
    } else if (operation == "/") {
        if (val2 == 0) {
            simple_error("divide by zero");
        }
        result = val1 / val2;
        operation = "/";
    } else {
        simple_error("Unknown operator!");
    }

    cout << val1 << " " << operation << " " << val2 << " = " << result << endl; 

    keep_window_open();
    return 0;
}
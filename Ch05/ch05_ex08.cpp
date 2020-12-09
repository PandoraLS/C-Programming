/*
 * @Author: seenli 
 * @Date: 2020-12-09 19:47:31 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-09 20:20:56
 */

#include "std_lib_facilities.h"

int main()
try {
    constexpr char termination{'|'};
    using vType = vector<int>;

    cout << "Enter how many numbers that you would like to sum:" << endl;

    int sumHowMany{};
    if (!(cin >> sumHowMany)) {
        error("number expected!");
    }

    vType numbers;
    cout << "Enter some numbers (press '" << termination << "' to stop)" << endl;
    // ѭ����������, '|'�����˳�
    while (true) {
        vType::value_type number{};
        // vector��������
        if (cin >> number) {
            numbers.push_back(number);
        } else {
            cin.clear();        // �����־λ
            char c{};
            cin >> c;
            if (c == termination) {
                break;
            }
            error("Invalid number of termination!");
        }
    }

    if (numbers.size() >= sumHowMany) {
        vType::iterator stop{numbers.begin() + sumHowMany};
        // 
    }
}

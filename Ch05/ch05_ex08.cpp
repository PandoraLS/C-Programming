/*
 * @Author: seenli 
 * @Date: 2020-12-09 19:47:31 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-10 12:22:55
 */

/*
Section 5 exercise 8
A program that reads and stores a series of integers.
Ask user to enter number(N) of integers want to sum.
Create a vector of the first N integers.
From that vector calculate the sum of those N integers.
Instruct user to terminate series with '|' when finished entering numbers.
Handle all inputs and provide and error N is larger than input vector
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
        // ���,��ʼ��vector value Ϊ 0
        vType::value_type sum{accumulate(numbers.begin(), stop, vType::value_type{})};
        cout << "The sum of the first " << sumHowMany << " numbers." << endl;
        for (auto i = numbers.begin(); i != stop; i++) {
            if (i == (stop - 1)) {
                cout << *i << " = " << sum << endl;
            } else {
                cout << *i << " + ";
            }
        }
    } else {
        error("not enough numbers entered to sum!");
    }

    keep_window_open();
    return 0;
}

catch(exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}

catch (...) {
    cerr << "Oops: unknown exception!" << endl;
    keep_window_open();
    return 2;
}

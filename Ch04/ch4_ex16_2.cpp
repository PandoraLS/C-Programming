/*
 * @Author: seenli 
 * @Date: 2020-12-01 20:49:11 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-02 13:49:01
 */

/*
    Section 4 exercise 16.
    A program that finds the mode of a set of positive integers
    The "mode" is the value that occurs most often.
    If no number is repeated, then there is no mode for the list.
    Refer to drill 3
*/

// �ο�ppp2�е�����

#include "std_lib_facilities.h"

int main() {
    constexpr char termination{'|'};

    using vType = vector<int>;
    cout << "���һ������, �ҳ�����. (ʹ�� | ��������)" << endl;

    vType sequence;     // vector to hold input sequence
    char c{};
    do {
        static vType::value_type enteredValue{};
        if (cin >> enteredValue) {
            sequence.push_back(enteredValue);
            continue;
        }
        cin.clear();
        cin.get(c);
    } while(c != termination);

    if (!sequence.empty()) {
        sort(sequence.begin(), sequence.end());
        vType::value_type mode{};               // ���ֵ������
        vType::difference_type count{};         // ��ʾ������֮��ľ���
        
        // ���������������е�����
        for (auto i{sequence.cbegin()}, next{sequence.cbegin()}; i != sequence.cend(); i = next) {
            next = find_if_not(i, sequence.cend(), [i](vType::value_type comp) {return *i == comp; });
            auto temp_count{next - i};
            if (temp_count >= count) {
                count = temp_count;
                mode = *i;
            }
        }

        // ��� mode
        if (count > 1) {
            cout << "The MODE of entered sequence is " << mode << ". \n";
            cout << mode << " wav found " << count << " times. \n";
        } else {
            cout << "There is no MODE from this set. \n";
        }
    } else {
        cout << "nothing entred \n";
    }

    keep_window_open();
    return 0;
}

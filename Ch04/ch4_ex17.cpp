/*
 * @Author: seenli 
 * @Date: 2020-10-14 00:38:59 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-14 01:55:44
 */

/*
Section 4 exercise 17.
finds the min, max and mode of a sequence of strings
*/

#include "std_lib_facilities.h"

int main() {
    using vType = vector<string>;
    cout << "����һϵ��strings ��max��min��mode. �� �س� + Ctrl-Z ������������ \n";

    vType sequence;     //�洢��������� 
    for(vType::value_type enteredValue{}; cin >> enteredValue; ) {
        transform(enteredValue.begin(), enteredValue.end(), enteredValue.begin(), 
            [](char c){return static_cast<unsigned char>(tolower(c));});
        sequence.push_back(enteredValue);
    }

    if (!sequence.empty()) {
        sort(sequence.begin(), sequence.end());
        vType::value_type mode{};           // ͨ��ȡ���Ե����������ã����Ի��ֵ������
        vType::difference_type count{};     // ��ʶ������֮��ľ����һ������

        // �����ظ�����vectorԪ��
        for (auto i{sequence.cbegin()}, next{sequence.cbegin()}; i != sequence.end(); i = next) {
            // ֱ��������� *i��ͬ
            next = find_if_not(i, sequence.cend(), [i](vType::value_type comp){return *i == comp;});    
            
            auto temp_count{next - i};  // temp_count Ϊ���ַ������ظ�����
            if (temp_count >= count){
                count = temp_count;
                mode = *i;
            }
        }

        // print out the MODE
        if (count > 1) {
            cout << "sequence�е�����Ϊ: " << mode << ".\n";
            cout << mode << " was found " << count << " times.\n";
        } else {
            cout << "There is no MODE from this set. \n";
        }

        cout << "���������ַ���Ϊ " << sequence.back() << "\n";
        cout << "��С�������ַ���Ϊ " << sequence.front() << "\n";
    } else {
        cout << "nothing entered\n";
    }

    keep_window_open();
    return 0;
}
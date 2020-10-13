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
    cout << "输入一系列strings 的max、min、mode. 以 回车 + Ctrl-Z 结束输入序列 \n";

    vType sequence;     //存储输入的序列 
    for(vType::value_type enteredValue{}; cin >> enteredValue; ) {
        transform(enteredValue.begin(), enteredValue.end(), enteredValue.begin(), 
            [](char c){return static_cast<unsigned char>(tolower(c));});
        sequence.push_back(enteredValue);
    }

    if (!sequence.empty()) {
        sort(sequence.begin(), sequence.end());
        vType::value_type mode{};           // 通过取消对迭代器的引用，可以获得值的类型
        vType::difference_type count{};     // 标识迭代器之间的距离的一种类型

        // 搜索重复最多的vector元素
        for (auto i{sequence.cbegin()}, next{sequence.cbegin()}; i != sequence.end(); i = next) {
            // 直到后面的与 *i不同
            next = find_if_not(i, sequence.cend(), [i](vType::value_type comp){return *i == comp;});    
            
            auto temp_count{next - i};  // temp_count 为该字符串的重复次数
            if (temp_count >= count){
                count = temp_count;
                mode = *i;
            }
        }

        // print out the MODE
        if (count > 1) {
            cout << "sequence中的众数为: " << mode << ".\n";
            cout << mode << " was found " << count << " times.\n";
        } else {
            cout << "There is no MODE from this set. \n";
        }

        cout << "最大的输入字符串为 " << sequence.back() << "\n";
        cout << "最小的输入字符串为 " << sequence.front() << "\n";
    } else {
        cout << "nothing entered\n";
    }

    keep_window_open();
    return 0;
}
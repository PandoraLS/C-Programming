/*
 * @Author: seenli 
 * @Date: 2020-10-09 14:56:14 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 21:57:36
 */

/*
Section 4 exercise 2.
If we define the median of a sequence as "a number so that exactly as many elements come before
it in the sequence as come after it," fix the program in ??4.6.3 so that it always prints out a median.
Hint: A median need not be an element of the sequence.
*/

#include "std_lib_facilities.h"

int main() {
    cout << "输入一组数据, 以 回车 + Ctrl + Z 结束 \n";
    vector<double> numbers;
    for (double num; cin >> num;)
        numbers.push_back(num);
    
    sort(numbers);
    if (numbers.size() & 1) {
        cout << "中值为：" << numbers[numbers.size() / 2] << endl;
    } else {
        cout << "中值为：" << (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2.0 << endl;
    }
    keep_window_open();
    return 0;
}


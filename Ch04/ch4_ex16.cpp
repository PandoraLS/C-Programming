/*
 * @Author: seenli 
 * @Date: 2020-10-13 16:11:03 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-01 20:47:56
 */

/*
    Section 4 exercise 16.
    A program that finds the mode of a set of positive integers
    The "mode" is the value that occurs most often.
    If no number is repeated, then there is no mode for the list.
    Refer to drill 3
*/

// 以下程序基于下标和元素之间的映射关系，所以当元素为负数的时候无法使用，属于bug

#include "std_lib_facilities.h"

int main() {
    cout << "请输入一组数据, 以 回车 + Ctrl+Z 结束 : \n";
    vector<int> numbers;
    for (int num; cin >> num;)
        numbers.push_back(num);
    sort(numbers);
    cout << "min: " << numbers.front() << endl;
    cout << "max: " << numbers.back() << endl;
    vector<int> histogram(numbers.size(), 0);       // 大小为 numbers.size(), 均值为0
    
    vector<int>::iterator it = numbers.begin();     // iterator为指针
    while (it != numbers.end())                     // 统计各元素的数量
        histogram[*it++]++;
    vector<int>::iterator ite = histogram.begin();
    cout << "每种元素的数量：\n";                    // 数量无的为0
    for (; ite != histogram.end(); ite++) {
        cout << *ite << " ";
    }
    cout << endl;
    // 找到的是最高柱状图所在的位置，该下标减去起始下标及为对应的元素
    int mode = max_element(histogram.begin(), histogram.end()) - histogram.begin(); 
    cout << "mode = " << mode << endl;
    
    keep_window_open();
    return 0;
}


/*
 * @Author: seenli 
 * @Date: 2020-10-13 16:11:03 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-14 00:24:51
 */

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
    while (it != numbers.end())
        histogram[*it++]++;
    vector<int>::iterator ite = histogram.begin();
    cout << "每种元素的数量：\n";
    for (; ite != histogram.end(); ite++) {
        cout << *ite << " ";
    }
    cout << endl;
    int mode = max_element(histogram.begin(), histogram.end()) - histogram.begin();     // 找到的是最大值的位置, 这里直接对应到元素
    cout << "mode = " << mode << endl;
    
    keep_window_open();
    return 0;
}


/*
 * @Author: seenli 
 * @Date: 2020-10-13 16:11:03 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-14 00:24:51
 */

#include "std_lib_facilities.h"

int main() {
    cout << "������һ������, �� �س� + Ctrl+Z ���� : \n";
    vector<int> numbers;
    for (int num; cin >> num;)
        numbers.push_back(num);
    sort(numbers);
    cout << "min: " << numbers.front() << endl;
    cout << "max: " << numbers.back() << endl;
    vector<int> histogram(numbers.size(), 0);       // ��СΪ numbers.size(), ��ֵΪ0
    vector<int>::iterator it = numbers.begin();     // iteratorΪָ��
    while (it != numbers.end())
        histogram[*it++]++;
    vector<int>::iterator ite = histogram.begin();
    cout << "ÿ��Ԫ�ص�������\n";
    for (; ite != histogram.end(); ite++) {
        cout << *ite << " ";
    }
    cout << endl;
    int mode = max_element(histogram.begin(), histogram.end()) - histogram.begin();     // �ҵ��������ֵ��λ��, ����ֱ�Ӷ�Ӧ��Ԫ��
    cout << "mode = " << mode << endl;
    
    keep_window_open();
    return 0;
}


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

// ���³�������±��Ԫ��֮���ӳ���ϵ�����Ե�Ԫ��Ϊ������ʱ���޷�ʹ�ã�����bug

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
    while (it != numbers.end())                     // ͳ�Ƹ�Ԫ�ص�����
        histogram[*it++]++;
    vector<int>::iterator ite = histogram.begin();
    cout << "ÿ��Ԫ�ص�������\n";                    // �����޵�Ϊ0
    for (; ite != histogram.end(); ite++) {
        cout << *ite << " ";
    }
    cout << endl;
    // �ҵ����������״ͼ���ڵ�λ�ã����±��ȥ��ʼ�±꼰Ϊ��Ӧ��Ԫ��
    int mode = max_element(histogram.begin(), histogram.end()) - histogram.begin(); 
    cout << "mode = " << mode << endl;
    
    keep_window_open();
    return 0;
}


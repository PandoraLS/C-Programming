/*
 * @Author: seenli 
 * @Date: 2020-10-06 21:14:03 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 21:14:49
 */

/* �ο����ӣ�����C++��map��unordered_map���÷�
 * https://blog.csdn.net/jingyi130705008/article/details/82633778
*/

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> dict; // ����unordered_map����

    // �������ݵ����ַ�ʽ
    dict.insert(pair<string, int>("apple", 2));
    dict.insert(unordered_map<string, int>::value_type("orange", 3));
    dict["banana"] = 6;

    // �ж��Ƿ���Ԫ��
    if (dict.empty())
        cout << "���ֵ���Ԫ��" << endl;
    else
        cout << "���ֵ乲��" << dict.size() << "��Ԫ��" << endl;

    // ����
    unordered_map<string, int>::iterator iter;
    for (iter = dict.begin(); iter != dict.end(); iter++)
        cout << iter->first << ends << iter->second << endl;

    // ����
    if (dict.count("boluo") == 0)
        cout << "can't find boluo!" << endl;
    else
        cout << "find boluo!" << endl;

    if ((iter = dict.find("banana")) != dict.end())
        cout << "banana=" << iter->second << endl;
    else
        cout << "can't find boluo!" << endl;

    system("pause");
    return 0;
}

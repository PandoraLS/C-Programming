/*
 * @Author: seenli 
 * @Date: 2020-11-23 21:12:10 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 21:53:09
 */


#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
int main()
{
    static string str;
    cin >> str;
    if (str.find("|") != string::npos) { // ��ʾ�ҵ� "|"������
        cout << str.find("|") << endl;
    } else {
        cout << "not found" << endl;
    }
    system("pause");
    return 0;
}


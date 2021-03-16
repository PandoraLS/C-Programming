/*
 * @Author: seenli
 * @Date: 2021-03-16 21:59:27
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-16 22:06:24
 * @FilePath: \C-posix\test.cpp
 */



#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    char* message;
    string ss = "this is message";
    int i = 1;
    ss += to_string(i);
    const char* c = ss.c_str();
    cout << ss << endl;
    printf("%s\n", c);
    system("pause");
    return 0;
}
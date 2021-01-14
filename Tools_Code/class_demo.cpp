/*
 * @Author: seenli
 * @Date: 2021-01-14 18:19:46
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-14 19:14:10
 * @FilePath: \Tools_Code\class_demo.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// 自定义类
struct Reading
{
    int hour;
    double temperature;
    Reading(): hour(0), temperature(0) {}
    Reading(int h, double t): hour(h), temperature(t) {}
};

// 输出重载
ostream& operator<<(ostream& os, const Reading& r) {
    return os << r.hour << ' ' << r.temperature;
}

int main()
try {
    Reading read{};                             // 默认值
    cout << read << endl;
    Reading read2{1, 2};                        // 用户设置值
    cout << read2 << endl;
    system("pause");
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

/*
 * @Author: seenli
 * @Date: 2021-01-24 11:43:17
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-24 12:06:00
 * @FilePath: \Ch13\ch13_ex07.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 13, exercise 07: write functions from exercises 5 and 6 for C-style
// strings, no stdlib functions and types allowed


#include "../includes/std_lib_facilities.h"

char* cat_dot(const char* s1, const char* s2) {
    // 获取s1和s2的长度
    const char* p = s1;
    int ctr = 0;
    while (*p) {++ctr; ++p;}
    p = s2;
    while (*p) {++ctr; ++p;}

    // 在自由空间分配一个新数组, 保留'.'和结尾0的空间
    char* res = new char[ctr + 2];

    // 复制数组
    p = s1;
    char* res_ptr = res;
    while (*p) *res_ptr++ = *p++;
    *res_ptr++ = '.';
    p = s2;
    while (*p) *res_ptr++ = *p++;
    *res_ptr = 0;

    return res;
}

char* cat_dot2(const char* s1, const char* s2, const char* s3) {
    // 获取s1, s2, s3的长度
    const char* p = s1;
    int ctr = 0;
    while (*p) {++ctr; ++p;}
    p = s2;
    while (*p) {++ctr; ++p;}
    p = s3;
    while (*p) {++ctr; ++p;}

    // 在自由空间分配一个新数组, 保留结尾0的空间
    char* res = new char[ctr + 1];

    // 复制数组
    p = s1;
    char* res_ptr = res;
    while (*p) *res_ptr++ = *p++;
    p = s3;
    while (*p) *res_ptr++ = *p++;
    p = s2;
    while (*p) *res_ptr++ = *p++;
    *res_ptr = 0;

    return res;
}

int main()
try {
    char* res = cat_dot("Niels", "Bohr");
    cout << res << endl;
    delete[] res;

    res = cat_dot2("Niels", "Bohr", " dot ");
    cout << res << endl;
    delete[] res;

    char a[] = "Niels";
    char b[] = "Bohr";
    res = cat_dot(a, b);
    cout << res << endl;
    delete[] res;

    char* ap = "Niels";
    char* bp = "Bohr";
    res = cat_dot(a, b);
    cout << res << endl;
    delete[] res;

    char* as = new char[6];
    for (int i = 0; i < 6; ++i) as[i] = ap[i];
    char* bs = new char[5];
    for (int i = 0; i < 5; ++i) bs[i] = bp[i];
    res = cat_dot(as, bs);
    cout << res << endl;
    delete[] res;
    delete[] bs;
    delete[] as;
    
    system("pause");
    return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
	return 2;
}
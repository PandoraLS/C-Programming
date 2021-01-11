/*
 * @Author: seenli
 * @Date: 2021-01-11 19:26:07
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-11 21:40:48
 * @FilePath: \Ch10\ch10_drill.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


#include "../includes/std_lib_facilities.h"

// type for points
struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int xx, int yy): x(xx), y(yy) {}
};



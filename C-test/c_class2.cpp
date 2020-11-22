/*
 * @Author: seenli 
 * @Date: 2020-11-22 21:43:21 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-22 22:01:48
 */

/**
 * c++类成员函数：https://www.runoob.com/cplusplus/cpp-class-member-functions.html
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Box{
    public:
        double length;
        double breadth;
        double height;
        
        // 成员函数声明
        double getVolume(void);
        void setLength(double len);
        void setBreadth(double bre);
        void setHeight(double hei);
};

double Box::getVolume(void) {
    return length * breadth * height;
}

void Box::setLength(double len) {
    length = len;
}

void Box::setBreadth(double bre) {
    breadth = bre;
}

void Box::setHeight(double hei) {
    height = hei;
}

// 程序的主函数
int main() {
    Box Box1;
    Box Box2;
    double volume = 0.0;

    // box1 详述
    Box1.setLength(6.0);
    Box1.setLength(7.0);
    Box1.setHeight(5.0);
    
    // box2 详述
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // box1 体积
    volume  = Box1.getVolume();
    cout << "volume of Box1: " << volume << endl;

    // box2 体积
    volume = Box2.getVolume();
    cout << "volume of Box2: " << volume << endl;

    system("pause");
    return 0;
}
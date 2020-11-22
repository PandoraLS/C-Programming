/*
 * @Author: seenli 
 * @Date: 2020-11-22 21:20:27 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-22 22:02:47
 */

/**
 * 参考链接：https://www.runoob.com/cplusplus/cpp-classes-objects.html
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Box {
    public:
        double length;
        double breadth;
        double height;
};

int main() {
    Box Box1;
    Box Box2;
    double volume = 0.0;

    // box1
    Box1.height = 5.0;
    Box2.length = 6.0;
    Box1.breadth = 7.0;

    // box2
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    // box1 体积
    volume =  Box1.height * Box1.length * Box1.breadth;
    cout << "volume of Box1: " << volume << endl;
    
    // box2 体积
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "volume of Box2: " << volume << endl;

    system("pause");
    return 0;
}


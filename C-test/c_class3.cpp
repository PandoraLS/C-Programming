/*
 * @Author: seenli 
 * @Date: 2020-11-22 22:03:02 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-22 22:07:42
 */

/**
 * reference: https://www.runoob.com/cplusplus/cpp-class-access-modifiers.html
*/

#include <iostream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

class A {
    public:
        int a;
        A() {
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void fun() {
            cout << a << endl;
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
        }
    
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};

class B: public A{
    public:
        int a;
    B(int i) {
        A();
        a = i;
    }
    void fun() {
        cout << a << endl;
        cout << a1 << endl;
        cout << a2 << endl;
        // cout << a3 << endl;
    }
};

int main() {
    B b(10);
    cout << b.a << endl;
    cout << b.a1 << endl;
    // cout << b.a2 << endl;
    // cout << b.a3 << endl;
    system("pause");
    return 0;
}


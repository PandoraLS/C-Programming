#include "std_lib_facilities.h"
// 8.5.4节 传引用的例子

int main(){
    int i = 7;
    int& r = i;
    r = 9;
    cout << r << "   " << i << '\n';
    i = 10;
    cout << r << "   " << i << '\n';
    system("pause");
    return 0;
}


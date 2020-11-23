#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
    double mile = 0.0;
    cout << "英里转为公里, 请输入英里数： ";
    while (cin >> mile) {
        cout << mile << " mile = " << mile * 1.609 << " km\n";
    }
    system("pause");
    return 0;
}
/*
 * @Author: seenli 
 * @Date: 2020-10-05 20:31:54 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-05 20:46:43
 */


#include "std_lib_facilities.h"

int square(int);

int main() {
    cout << "Program to find the squared results as the first program did in 1949.\n";
    for (int i{}; i < 100; i++){
        cout << i << "\tsuqare = " << square(i) << endl;
    }
    keep_window_open();
    return 0;
}


int square(int v){
    int sum {};
    for (int i {}; i < v; i++){
        sum += v;
    }
    return sum;
}
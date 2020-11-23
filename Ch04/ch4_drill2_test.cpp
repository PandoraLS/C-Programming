/*
 * @Author: seenli 
 * @Date: 2020-11-23 16:59:41 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 17:03:38
 */


#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {

    printf("test swap() function. \n");
    int val1 = 0, val2 = 1;
    printf("%d  %d\n", val1, val2);
    swap(val1, val2);
    printf("%d      %d\n", val1, val2);
    system("pause");
    return 0;
}
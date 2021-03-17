/*
 * @Author: seenli
 * @Date: 2021-03-17 21:01:04
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 22:19:36
 * @FilePath: \C-posix\test7.c
 */


/*
    对数组进行操作
*/


#include <stdio.h>
#include <stdlib.h>

void printf_arr(int *a) {
    int *pointer = a;
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(pointer + i));
    }
    printf("\n");
}

void process_func(int *a) {
    int *p = a;
    for (int i = 0; i < 4; i++) {
        *p += 1;
        p += 1;
    }
}

int main() {
    int num = 111;
    int *num_p = &num;
    printf("%d\n", *num_p);

    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    printf_arr(a);
    process_func(a);
    printf_arr(a);
    printf("\n");
    system("pause");
    return 0;
}

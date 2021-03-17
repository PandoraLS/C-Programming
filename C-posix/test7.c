/*
 * @Author: seenli
 * @Date: 2021-03-17 18:05:20
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 18:06:16
 * @FilePath: \C-posix\test7.c
 */



/*
    https://blog.csdn.net/weixin_43815275/article/details/106019315
    https://blog.csdn.net/hanbingfengying/article/details/26067281
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int *p = a;
    int *q = b;
    for (int i = 0; i < 4; i++){
        printf("%d ", *(p + i));
    }
    printf("\n------------------\n");
    for (int i = 0; i < 4; i++){
        printf("%d ", *(q + i));
    }

    printf("\n交换两个数组的指针后\n");
    p = b;
    q = a;

    for (int i = 0; i < 4; i++){
        printf("%d ", *(p + i));
    }
    printf("\n------------------\n");
    for (int i = 0; i < 4; i++){
        printf("%d ", *(q + i));
    }


    printf("\n");
    system("pause");
    return 0;
}

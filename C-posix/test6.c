/*
 * @Author: seenli
 * @Date: 2021-03-17 17:19:50
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 21:03:49
 * @FilePath: \C-posix\test6.c
 */

/*
    https://blog.csdn.net/weixin_43815275/article/details/106019315
    https://blog.csdn.net/hanbingfengying/article/details/26067281
*/

#include <stdio.h>
#include <stdlib.h>

// 交换指向两个数组的指针
void Change(int **a, int **b)
{
	int *t = *a;
	*a = *b;
	*b = t;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int *p = a;
    int *q = b;
    int **x = &p;
    int **y = &q;
    for (int i = 0; i < 4; i++){
        printf("%d ", *(p + i));
    }
    printf("\n------------------\n");
    for (int i = 0; i < 4; i++){
        printf("%d ", *(q + i));
    }

    printf("\n交换两个数组的指针后，第1次交换\n");
    Change(x, y); // 方法一
    // 方法二
    // int *tmp = p;
    // p = q;
    // q = tmp;

    // 方法三
    // p = b;
    // q = a;

    for (int i = 0; i < 4; i++){
        printf("%d ", *(p + i));
    }
    printf("\n------------------\n");
    for (int i = 0; i < 4; i++){
        printf("%d ", *(q + i));
    }


    printf("\n第2次交换\n");
    Change(x, y); 
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

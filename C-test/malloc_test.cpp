/*
 * @Author: seenli 
 * @Date: 2020-11-11 16:04:54 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-11 16:07:03
 */

// 测试malloc相关代码

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    char *str;
    int i = 15;

    /* 最初的内存分配 */
    str = (char *) malloc(i);
    strcpy(str, "runoob");
    printf("String = %s,  Address = %u\n", str, str);

    /* 重新分配内存 */
    str = (char *) realloc(str, i+10);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    str = (char *) realloc(str, i+10);
    strcat(str, ".cccccc");
    printf("String = %s,  Address = %u\n", str, str);

    free(str);
    system("pause");
    return(0);
}
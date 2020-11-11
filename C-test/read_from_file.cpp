/*
 * @Author: seenli 
 * @Date: 2020-11-11 12:38:13 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-11 12:45:29
 */

/**
 * 读取文件，读取到定长
*/

// #include <stdio.h>
#include <iostream>
int main(int argc, char *argv[])
{
    int a[3];
    int i,j;
    FILE* fp = fopen("read_data.txt","r");
    if(fp == NULL)
    {
        printf("文件无效");
        return -1;
    }
    for (i = 0; i < 3; i++){
        fscanf(fp, "%d", &a[i]);
    }

    fclose(fp);

    for (i = 0; i < 3; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    free(fp);       // 释放指针
    system("pause");
    return 0;
}
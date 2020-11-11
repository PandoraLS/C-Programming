/*
 * @Author: seenli 
 * @Date: 2020-11-11 14:28:10 
 * @Last Modified by:   seenli 
 * @Last Modified time: 2020-11-11 14:28:10 
 */

/**
 * 读取文件到结束
*/

#include <iostream>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int a[10];      // 先用一个较大的数组来存储
    int i = 0, j = 0;
    FILE* fp = fopen("read_data.txt","r");
    if(fp == NULL)
    {
        printf("文件无效");
        return -1;
    }

    while (!feof(fp)) {
        fscanf(fp, "%d", &a[i]);
        i++;
    }
    printf("end of file. \n");
    fclose(fp);

    for (j = 0; j < i-1; j++){
        // feof在真正文件读取结束之后还会再判断一遍才结束，所以会多读一行才结束
        // 这里i-1就不把多读的一行搞进来了
        printf("%d ", a[j]);
    }
    printf("\n");
    free(fp);       // 释放指针
    system("pause");
    return 0;
}
/*
 * @Author: seenli
 * @Date: 2021-03-18 19:29:53
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-18 19:31:31
 * @FilePath: \C-test\read_from_file4.c
 */


// 参考链接：http://ask.zol.com.cn/x/5148499.html

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int a[3][5];
    int i,j;
    //    FILE* fp = fopen("2.txt","r");
    FILE* fp = fopen("read_data2.txt","r");
    if(fp == NULL)
    {
        printf("文件无效");
        return -1;
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<5; j++)
        {
            fscanf(fp,"%d",&a[i][j]);
        }
        //fscanf(fp,"\n"); 不要也罢
    }

    fclose(fp);

    for(i=0; i<3; i++)
    {
        for(j=0; j<5; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    return 0;
}
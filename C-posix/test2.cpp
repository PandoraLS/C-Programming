/*
 * @Author: seenli
 * @Date: 2021-03-17 14:52:54
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 14:54:19
 * @FilePath: \C-posix\test2.cpp
 */

#include<stdio.h>
#include<stdlib.h>

void swap(int *p1,int *p2)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int main()
{
    int a=10;
    int b=20;
    printf("交换前a,b的值分别为:\n");
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    swap(&a,&b);
    printf("交换后a,b的值分别为:\n");
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    system("pause");
    return 0;
}
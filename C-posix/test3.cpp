/*
 * @Author: seenli
 * @Date: 2021-03-17 15:15:27
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 15:21:29
 * @FilePath: \C-posix\test3.cpp
 */


/*
    ≤‚ ‘while—≠ª∑µ»¥˝
*/


#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int flag = 0;
void swap(int *p1,int *p2)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

void wait() {
    sleep(3);
    flag = 1;
}

int main()
{
    int a=10;
    int b=20;
    while(flag==0);
    
    system("pause");
    return 0;
}
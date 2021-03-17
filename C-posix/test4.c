/*
 * @Author: seenli
 * @Date: 2021-03-17 17:02:48
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 17:04:37
 * @FilePath: \C-posix\test4.c
 */

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Change(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int A[5];
	int B[5];
	int i, j, k;
	printf("请输入A的5个数：");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("\n请输入B的5个数：");
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &B[j]);
	}
	for (k = 0; k < 5; k++)
	{
		Change(&A[k], &B[k]);
	}
	printf("\n输出交换后的A数组:");
	for (i = 0; i < 5; i++)
	{
        printf("%d  ",A[i]);
	}		
	printf("\n输出交换后的B数组:");
	for (j = 0; j < 5; j++)
	{
		printf("%d  ",B[j]);
	}
	printf("\n");
    system("pause");
	return 0;
}

/*
 * @Author: seenli
 * @Date: 2021-03-17 17:05:43
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 17:10:55
 * @FilePath: \C-posix\test5.c
 */


/*
    参考test4.c
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
	int A[] = {1,2,3,4};
	int B[] = {5,6,7,8};

	int i;
	printf("数组A:\t\t\t");
    for (i = 0; i < 4; i++)
        printf("%d  ",A[i]);
    
    printf("\n数组B:\t\t\t");
    for (i = 0; i < 4; i++)
        printf("%d  ", B[i]);
	
    for (i = 0; i < 4; i++)
	{
		Change(&A[i], &B[i]);
	}
	printf("\n输出交换后的A数组:\t");
	for (i = 0; i < 4; i++)
	{
        printf("%d  ",A[i]);
	}		
	printf("\n输出交换后的B数组:\t");
	for (i = 0; i < 4; i++)
	{
		printf("%d  ",B[i]);
	}
	printf("\n");
    system("pause");
	return 0;
}

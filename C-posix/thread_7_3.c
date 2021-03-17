/*
 * @Author: seenli
 * @Date: 2021-03-17 21:48:48
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 22:22:28
 * @FilePath: \C-posix\thread_7_3.c
 */



/*
	c多线程
    ref: https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_7_2.c -lpthread -o thread_7_2.exe
	.\thread_7_2.exe

    研究函数参数的传递
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

// Let us create a global variable to change it in threads 
int g = 0; 

// The function to be executed by all threads 
void *myThreadFun(void *vargp) 
{ 
	// Store the value argument passed to this thread 
	// int *num_p = (int *)vargp; 
	// int tmp = *num_p;

    int *p = (int *)vargp;

    for (int j = 0; j < 4; j++) {
        printf("%d ", *(p + j));
    }
    printf("\n");

	// Let us create a static variable to observe its changes 
	static int s = 0; 

	// Change static and global variables 
	++s; ++g; 

    printf("全局变量与静态变量:g: %d, s: %d\n", g, s);
} 

int main() 
{ 
	int i; 
	pthread_t tid1 = 1; 

    int num = 111;
    int *num_p = &num;
    // printf("num: %d\n", num);
    // printf("*num_p: %d\n", *num_p);


    int a[] = {1, 2, 3, 4};
    int *p = a;
	// Let us create three threads 
	// 参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
	pthread_create(&tid1, NULL, myThreadFun, (void *)p); // 输入p或a都是对的
	pthread_create(&tid1, NULL, myThreadFun, (void *)a); 
	// pthread_create(&tid1, NULL, myThreadFun, (void *)tidp); 
	printf("\n");

	pthread_join(tid1, NULL);
    system("pause");
	return 0; 
} 

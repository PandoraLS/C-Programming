/*
 * @Author: seenli
 * @Date: 2021-03-17 16:48:30
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 22:39:47
 * @FilePath: \C-posix\thread_pingpong_3.c
 */

/*
    c 语言 多线程 https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_pingpong_3.c -lpthread -o thread_pingpong_3.exe
    .\thread_pingpong_3.exe
    
    1 在本段程序中，get_data和process确实是同时开始的，但不是同时结束
    2 pthread_join等待两个线程结束后再重新创建共同开始的线程
    3 处理数据修改为数组形式，添加程序运行时间统计
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#include <time.h>

// 定义全局变量
int a[] = {1,2,3,4};
int b[] = {5,6,7,8};
int *pointer_a = a;     // pointer_a和pointer_b分别指向a和b
int *pointer_b = b;
int **p = &pointer_a;   // p和q分别指向pointer_a和pointer_b
int **q = &pointer_b;


// 打印输出两个
void printf_a() {
    printf("a data: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(pointer_a + i));
    }
    printf("\n");
}
void printf_b() {
    printf("b data: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(pointer_b + i));
    }
    printf("\n");
}

void *get_data(void *vargp) {
    printf("get data a...\n");
    printf_a();
    sleep(6);                      // 读数据需要10秒
    printf("get data a\n");
    return NULL;
}

void *process_data(void *vargp) {
    printf("process data b...\n");
    printf_b();
    sleep(3);                    // 处理数据只需要1秒
    printf("process data b\n");
    return NULL;
}

// 交换指向两个数组的指针
void change(int **a, int **b)
{
	int *t = *a;
	*a = *b;
	*b = t;
}

int main() 
{   
    // 统计程序运行的时间
    clock_t startTime, endTime;
    startTime = clock();

	pthread_t thread_id1=1; 
	pthread_t thread_id2=2; 
    // Epoch 0
    printf("start...\n");

    pthread_create(&thread_id1, NULL, get_data, NULL); 
    pthread_create(&thread_id2, NULL, process_data, NULL);
    // 等待两个线程结束
	pthread_join(thread_id1, NULL); 
	pthread_join(thread_id2, NULL);
    // 交换两个指向数组的指针
    change(p, q);
    printf("after change a[] and b[]\n");
    printf_a(); printf_b();
    endTime = clock();
    printf("Epoch0 Time %f second\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    for (int i = 1; i <= 4; i++) {
        startTime = clock();
        printf("----------------------------------\n");
        printf("epoch%d\n",i);
        pthread_create(&thread_id1, NULL, get_data, NULL); 
        pthread_create(&thread_id2, NULL, process_data, NULL);
        // 等待两个线程结束
        pthread_join(thread_id1, NULL); 
        pthread_join(thread_id2, NULL);
        // 交换两个指向数组的指针
        change(p, q);
        printf("after change a[] and b[]\n");
        printf_a(); printf_b();
        endTime = clock();
        printf("Epoch%d Time %f second\n", i, (double)(endTime - startTime) / CLOCKS_PER_SEC);
    }

    system("pause");
	exit(0); 
}

/*
start...
get data a...
a data: 1 2 3 4
process data b...
b data: 5 6 7 8
process data b
get data a
after change a[] and b[]
a data: 5 6 7 8
b data: 1 2 3 4
Epoch0 Time 6.015000 second
----------------------------------
epoch1
get data a...
a data: 5 6 7 8
process data b...
b data: 1 2 3 4
process data b
get data a
after change a[] and b[]
a data: 1 2 3 4
b data: 5 6 7 8
Epoch1 Time 6.016000 second
----------------------------------
epoch2
get data a...
a data: 1 2 3 4
process data b...
b data: 5 6 7 8
process data b
get data a
after change a[] and b[]
a data: 5 6 7 8
b data: 1 2 3 4
Epoch2 Time 6.025000 second
----------------------------------
epoch3
get data a...
a data: 5 6 7 8
process data b...
b data: 1 2 3 4
process data b
get data a
after change a[] and b[]
a data: 1 2 3 4
b data: 5 6 7 8
Epoch3 Time 6.022000 second
----------------------------------
epoch4
get data a...
a data: 1 2 3 4
process data b...
b data: 5 6 7 8
process data b
get data a
after change a[] and b[]
a data: 5 6 7 8
b data: 1 2 3 4
Epoch4 Time 6.041000 second
请按任意键继续. . .
*/

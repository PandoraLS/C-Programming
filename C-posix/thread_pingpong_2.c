/*
 * @Author: seenli
 * @Date: 2021-03-17 14:17:35
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 16:50:15
 * @FilePath: \C-posix\thread_pingpong_2.c
 */

/*
    c 语言 多线程 https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_pingpong_2.c -lpthread -o thread_pingpong_2.exe
    .\thread_pingpong_2.exe

    1 在本段程序中，get_data和process确实是同时开始的，但不是同时结束
    2 pthread_join等待两个线程结束后再重新创建共同开始的线程
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

// 定义全局变量, get_data直接作用与该全局变量
int d0 = 5, d1 = 10;

void *get_data(void *vargp) {
    printf("get data d0...\n");
    sleep(6);                      // 读数据需要10秒
    printf("get data d0:%d\n", d0);
    return NULL;
}

void *process_data(void *vargp) {
    printf("process data d1...\n");
    sleep(3);       // 处理数据只需要1秒
    printf("process data d1:%d\n", d1);
    return NULL;
}

void swap(int *p1,int *p2)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int main() 
{ 
	pthread_t thread_id1=1; 
	pthread_t thread_id2=2; 

    // Epoch 0
    printf("start d0=%d,d1=%d\n",d0, d1);
    pthread_create(&thread_id1, NULL, get_data, NULL); 
    pthread_create(&thread_id2, NULL, process_data, NULL);
    // 等待两个线程结束
	pthread_join(thread_id1, NULL); 
	pthread_join(thread_id2, NULL);
    // 交换两个数
    swap(&d0, &d1);
    printf("after swap d0=%d,d1=%d\n",d0, d1);

    for (int i = 1; i <= 5; i++) {
        printf("----------------------------------\n");
        printf("epoch%d: d0=%d,d1=%d\n",i, d0, d1);
        pthread_create(&thread_id1, NULL, get_data, NULL); 
        pthread_create(&thread_id2, NULL, process_data, NULL);
        // 等待两个线程结束
        pthread_join(thread_id1, NULL); 
        pthread_join(thread_id2, NULL);
        // 交换两个数
        swap(&d0, &d1);
        printf("after swap d0=%d,d1=%d\n",d0, d1);
    }

    system("pause");
	exit(0); 
}


/*
start d0=5,d1=10
get data d0...
process data d1...
process data d1:10
get data d0:5
after swap d0=10,d1=5
----------------------------------
epoch1: d0=10,d1=5
get data d0...
process data d1...
process data d1:5
get data d0:10
after swap d0=5,d1=10
----------------------------------
epoch2: d0=5,d1=10
get data d0...
process data d1...
process data d1:10
get data d0:5
after swap d0=10,d1=5
----------------------------------
epoch3: d0=10,d1=5
get data d0...
process data d1...
process data d1:5
get data d0:10
after swap d0=5,d1=10
----------------------------------
epoch4: d0=5,d1=10
get data d0...
process data d1...
process data d1:10
get data d0:5
after swap d0=10,d1=5
----------------------------------
epoch5: d0=10,d1=5
get data d0...
process data d1...
process data d1:5
get data d0:10
after swap d0=5,d1=10
请按任意键继续. . .
*/
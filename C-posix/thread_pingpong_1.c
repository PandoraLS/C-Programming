/*
 * @Author: seenli
 * @Date: 2021-03-16 22:31:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 14:19:55
 * @FilePath: \C-posix\thread_pingpong_1.c
 */

/*
    c 语言 多线程 https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_pingpong_1.c -lpthread -o thread_pingpong_1.exe
    .\thread_pingpong_1.exe

    1 在本段程序中，get_data和process确实是同时开始的，但不是同时结束
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

void *get_data(void *vargp) {
    printf("get data begin...\n");
    sleep(10);       // 读数据需要4秒
    printf("get data end\n");
    return NULL;
}

void *process_data(void *vargp) {
    printf("process data begin...\n");
    sleep(5);       // 处理数据只需要1秒
    printf("process data end\n");
    return NULL;
}

int main() 
{ 
	pthread_t thread_id; 
	printf("create get and process Thread\n"); 
	pthread_create(&thread_id, NULL, get_data, NULL); 
    pthread_create(&thread_id, NULL, process_data, NULL);
    
	pthread_exit(NULL); //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    // 这里如果直接使用 pthread_join(thread_id, NULL); 就会导致get_data没结束就被中断了

	printf("After Thread\n"); 
	exit(0); 
}

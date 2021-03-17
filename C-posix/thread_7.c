/*
 * @Author: seenli
 * @Date: 2021-03-17 12:41:08
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 13:30:46
 * @FilePath: \C-posix\thread_7.c
 */

/*
	c多线程
    ref: https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_7.c -lpthread -o thread_7.exe
	.\thread_7.exe
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
	int *myid = (int *)vargp; 

	// Let us create a static variable to observe its changes 
	static int s = 0; 

	// Change static and global variables 
	++s; ++g; 

	// Print the argument, static and global variables 
	printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); 
} 

int main() 
{ 
	int i; 
	pthread_t tid; 

	// Let us create three threads 
	for (i = 0; i < 3; i++) 
		pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 

	//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
	pthread_exit(NULL); 
    system("pause");
	return 0; 
} 

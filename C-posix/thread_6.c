/*
 * @Author: seenli
 * @Date: 2021-03-17 12:46:43
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 13:20:38
 * @FilePath: \C-posix\thread_6.c
 */

/*
    c ???
    ref: https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_6.c -lpthread -o thread_6.exe
	.\thread_6.exe
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{ 
	sleep(1); 
	printf("Printing GeeksQuiz from Thread \n"); 
	return NULL; 
} 

int main() 
{ 
	pthread_t thread_id; 
	printf("Before Thread\n"); 
	pthread_create(&thread_id, NULL, myThreadFun, NULL); 
	pthread_join(thread_id, NULL); 
	printf("After Thread\n"); 
	exit(0); 
}

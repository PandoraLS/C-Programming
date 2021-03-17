/*
 * @Author: seenli
 * @Date: 2021-03-17 13:20:52
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 16:16:34
 * @FilePath: \C-posix\thread_6_2.c
 */
/*
    c ∂‡œﬂ≥Ã
    ref: https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_6_2.c -lpthread -o thread_6_2.exe
	.\thread_6_2.exe
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{ 
	sleep(5); 
	printf("Printing GeeksQuiz from Thread \n"); 
	return NULL; 
} 

void *myThreadFun2(void *vargp) 
{ 
	sleep(10); 
	printf("Printing GeeksQuiz from Thread2 \n"); 
	return NULL; 
} 

int main() 
{ 
	pthread_t thread_id1=1; 
	pthread_t thread_id2=2; 
	printf("Before Thread\n"); 
	pthread_create(&thread_id1, NULL, myThreadFun, NULL); 
	pthread_create(&thread_id2, NULL, myThreadFun2, NULL); 

	pthread_join(thread_id1, NULL); 
	pthread_join(thread_id2, NULL);
	printf("After Thread\n"); 
	system("pause");
	return 0;
}

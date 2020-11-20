/*
 * @Author: seenli 
 * @Date: 2020-11-20 10:41:25 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-20 11:09:40
 */

/**
 * 参考链接：https://www.runoob.com/cplusplus/cpp-multithreading.html
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
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

    system("pause");
    exit(0); 
}
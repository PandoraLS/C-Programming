/*
 * @Author: seenli
 * @Date: 2021-03-17 16:09:52
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 16:14:28
 * @FilePath: \C-posix\thread_8_2.c
 */

/*
    ref: https://zhuanlan.zhihu.com/p/83948286
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void* thread_func1(void* arg) {
    // (void)arg;
    while(1) {
        printf("I am thread111\n");
        sleep(1);
    }
}

void* thread_func2(void* arg) {
    // (void)arg;
    while(1) {
        printf("I am thread222\n");
        sleep(2);
    }
}

int main() {
    pthread_t tid1 = 1;
    pthread_t tid2 = 2;

    // pthread_create(&tid1, NULL, thread_func1, NULL);
    if (pthread_create(&tid1,NULL,thread_func1,NULL) == -1) {
        perror("pthread_create");
        exit(1);
    }
    if (pthread_create(&tid2,NULL,thread_func2,NULL) == -1) {
        perror("pthread_create");
        exit(1);
    }
    system("pause");
    return 0;
}
/*
 * @Author: seenli
 * @Date: 2021-03-17 16:02:53
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 16:08:04
 * @FilePath: \C-posix\thread_8.cpp
 */


/*
    ref: https://zhuanlan.zhihu.com/p/83948286
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void* thread_func(void* arg) {
    // (void)arg;
    while(1) {
        printf("I am new thread\n");
        sleep(1);
    }
}

int main() {
    pthread_t tid;
    if (pthread_create(&tid,NULL,thread_func,NULL) == -1) {
        perror("pthread_create");
        exit(1);
    }

    while(1) {
        printf("I am main thread\n");
        sleep(1);
    }
    system("pause");
    return 0;
}
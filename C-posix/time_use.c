/*
 * @Author: seenli
 * @Date: 2021-03-17 13:46:37
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 13:57:58
 * @FilePath: \C-posix\time_use.c
 */
/*
    ref: https://blog.csdn.net/xiong452980729/article/details/51394036
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 

int main() {
    clock_t start, end;
    start = clock();
    printf("start %f \n", start/CLOCKS_PER_SEC); 

    for (int i = 0; i < 100000; i++);

    sleep(4);
    end = clock();
    printf("end %f \n", end/CLOCKS_PER_SEC);

    printf("¹²ÓÃÊ±: %f Ãë", (end - start)/CLOCKS_PER_SEC);

    system("pause");
    return 0;
}
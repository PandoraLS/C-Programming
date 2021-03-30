/*
 * @Author: seenli
 * @Date: 2021-03-17 16:48:30
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 22:39:47
 * @FilePath: \C-posix\thread_pingpong_3.c
 */

/*
    c ���� ���߳� https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_pingpong_3.c -lpthread -o thread_pingpong_3.exe
    .\thread_pingpong_3.exe
    
    1 �ڱ��γ����У�get_data��processȷʵ��ͬʱ��ʼ�ģ�������ͬʱ����
    2 pthread_join�ȴ������߳̽����������´�����ͬ��ʼ���߳�
    3 ���������޸�Ϊ������ʽ�����ӳ�������ʱ��ͳ��
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#include <time.h>

// ����ȫ�ֱ���
int a[] = {1,2,3,4};
int b[] = {5,6,7,8};
int *pointer_a = a;     // pointer_a��pointer_b�ֱ�ָ��a��b
int *pointer_b = b;
int **p = &pointer_a;   // p��q�ֱ�ָ��pointer_a��pointer_b
int **q = &pointer_b;


// ��ӡ�������
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
    sleep(6);                      // ��������Ҫ10��
    printf("get data a\n");
    return NULL;
}

void *process_data(void *vargp) {
    printf("process data b...\n");
    printf_b();
    sleep(3);                    // ��������ֻ��Ҫ1��
    printf("process data b\n");
    return NULL;
}

// ����ָ�����������ָ��
void change(int **a, int **b)
{
	int *t = *a;
	*a = *b;
	*b = t;
}

int main() 
{   
    // ͳ�Ƴ������е�ʱ��
    clock_t startTime, endTime;
    startTime = clock();

	pthread_t thread_id1=1; 
	pthread_t thread_id2=2; 
    // Epoch 0
    printf("start...\n");

    pthread_create(&thread_id1, NULL, get_data, NULL); 
    pthread_create(&thread_id2, NULL, process_data, NULL);
    // �ȴ������߳̽���
	pthread_join(thread_id1, NULL); 
	pthread_join(thread_id2, NULL);
    // ��������ָ�������ָ��
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
        // �ȴ������߳̽���
        pthread_join(thread_id1, NULL); 
        pthread_join(thread_id2, NULL);
        // ��������ָ�������ָ��
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
�밴���������. . .
*/
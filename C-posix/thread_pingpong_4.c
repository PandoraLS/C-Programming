/*
 * @Author: seenli
 * @Date: 2021-03-17 21:23:56
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 23:01:51
 * @FilePath: \C-posix\thread_pingpong_4.c
 */

/*
    c ���� ���߳� https://www.geeksforgeeks.org/multithreading-c-2/
    ���̴߳��ݶ������(û�õ�): https://blog.csdn.net/computerme/article/details/52421928
    gcc thread_pingpong_3.c -lpthread -o thread_pingpong_3.exe
    .\thread_pingpong_3.exe
    
    1 �ڱ��γ����У�get_data��processȷʵ��ͬʱ��ʼ�ģ�������ͬʱ����
    2 pthread_join�ȴ������߳̽����������´�����ͬ��ʼ���߳�
    3 ���������޸�Ϊ������ʽ����ӳ�������ʱ��ͳ��
    4 ���process_func()��������̲߳�������
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#include <time.h>

// ��ӡ����
void printf_arr(int *arr) {
    int *p = arr;
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

// �����鴦�������е�ÿ��������1
void process_arr(int arr[]) {
    int *p = arr;
    for (int i = 0; i < 4; i++) {
        *p += 1;
        p += 1;
    }
}

// ����ָ�����������ָ��
void change(int **a, int **b)
{
	int *t = *a;
	*a = *b;
	*b = t;
}

void *get_data(void *vargp) {
    int *p = (int *)vargp; // ���pointer_?
    printf("get data a...\n");

    // �����õ�����
    printf("a data: ");
    for (int j = 0; j < 4; j++) {
        printf("%d ", *(p + j));
    }
    printf("\n");
    sleep(6);                      // ��������Ҫ10��
    printf("get data a end\n");
    return NULL;
}

void *process_data(void *vargp) {
    int *p = (int *)vargp; // ���pointer_?
    printf("process data b...\n");
    process_arr(p);
    printf("b data processed: ");
    // �����õ�����
    for (int j = 0; j < 4; j++) {
        printf("%d ", *(p + j));
    }
    printf("\n");
    sleep(3);                    // ��������ֻ��Ҫ1��
    printf("process data b end\n");
    return NULL;
}

int main() 
{   

    // ����ȫ�ֱ���
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    int *pointer_a = a;     // pointer_a��pointer_b�ֱ�ָ��a��b
    int *pointer_b = b;
    int **p = &pointer_a;   // p��q�ֱ�ָ��pointer_a��pointer_b
    int **q = &pointer_b;
    
    
    // ͳ�Ƴ������е�ʱ��
    clock_t startTime, endTime;
    startTime = clock();
    
	pthread_t thread_id1=1; 
	pthread_t thread_id2=2; 
    // Epoch 0
    printf("start...\n");
    pthread_create(&thread_id1, NULL, get_data, (void *)pointer_a); 
    pthread_create(&thread_id2, NULL, process_data, (void *)pointer_b);
    // �ȴ������߳̽���
	pthread_join(thread_id1, NULL); 
	pthread_join(thread_id2, NULL);
    // ��������ָ�������ָ��
    change(p, q);
    printf("after change a[] and b[]\n");
    printf_arr(pointer_a); 
    printf_arr(pointer_b);
    endTime = clock();
    printf("Epoch0 Time %f second\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    for (int i = 1; i <= 4; i++) {
        startTime = clock();
        printf("----------------------------------\n");
        printf("epoch%d\n",i);
        pthread_create(&thread_id1, NULL, get_data, (void *)pointer_a); 
        pthread_create(&thread_id2, NULL, process_data, (void *)pointer_b);
        // �ȴ������߳̽���
        pthread_join(thread_id1, NULL); 
        pthread_join(thread_id2, NULL);
        // ��������ָ�������ָ��
        change(p, q);
        printf("after change a[] and b[]\n");
        printf_arr(pointer_a); 
        printf_arr(pointer_b);
        endTime = clock();
        printf("Epoch%d Time %f second\n", i, (double)(endTime - startTime) / CLOCKS_PER_SEC);
    }

    system("pause");
	return 0;
}


/*
start...
get data a...
a data: 1 2 3 4
process data b...
b data processed: 6 7 8 9
process data b end
get data a end
after change a[] and b[]
6 7 8 9
1 2 3 4
Epoch0 Time 6.010000 second
----------------------------------
epoch1
get data a...
a data: 6 7 8 9
process data b...
b data processed: 2 3 4 5
process data b end
get data a end
after change a[] and b[]
2 3 4 5
6 7 8 9
Epoch1 Time 6.016000 second
----------------------------------
epoch2
get data a...
a data: 2 3 4 5
process data b...
b data processed: 7 8 9 10
process data b end
get data a end
after change a[] and b[]
7 8 9 10
2 3 4 5
Epoch2 Time 6.030000 second
----------------------------------
epoch3
process data b...
b data processed: 3 4 5 6
get data a...
a data: 7 8 9 10
process data b end
get data a end
after change a[] and b[]
3 4 5 6
7 8 9 10
Epoch3 Time 6.039000 second
----------------------------------
epoch4
get data a...
a data: 3 4 5 6
process data b...
b data processed: 8 9 10 11
process data b end
get data a end
after change a[] and b[]
8 9 10 11
3 4 5 6
Epoch4 Time 6.026000 second
�밴���������. . .
*/
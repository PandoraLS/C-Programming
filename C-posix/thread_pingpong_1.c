/*
 * @Author: seenli
 * @Date: 2021-03-16 22:31:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 14:19:55
 * @FilePath: \C-posix\thread_pingpong_1.c
 */

/*
    c ���� ���߳� https://www.geeksforgeeks.org/multithreading-c-2/
    gcc thread_pingpong_1.c -lpthread -o thread_pingpong_1.exe
    .\thread_pingpong_1.exe

    1 �ڱ��γ����У�get_data��processȷʵ��ͬʱ��ʼ�ģ�������ͬʱ����
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

void *get_data(void *vargp) {
    printf("get data begin...\n");
    sleep(10);       // ��������Ҫ4��
    printf("get data end\n");
    return NULL;
}

void *process_data(void *vargp) {
    printf("process data begin...\n");
    sleep(5);       // ��������ֻ��Ҫ1��
    printf("process data end\n");
    return NULL;
}

int main() 
{ 
	pthread_t thread_id; 
	printf("create get and process Thread\n"); 
	pthread_create(&thread_id, NULL, get_data, NULL); 
    pthread_create(&thread_id, NULL, process_data, NULL);
    
	pthread_exit(NULL); //�ȸ����߳��˳��󣬽��̲Ž������������ǿ�ƽ����ˣ��߳̿��ܻ�û��Ӧ������
    // �������ֱ��ʹ�� pthread_join(thread_id, NULL); �ͻᵼ��get_dataû�����ͱ��ж���

	printf("After Thread\n"); 
	exit(0); 
}

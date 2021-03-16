/*
 * @Author: seenli
 * @Date: 2021-03-16 21:36:00
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-16 21:40:35
 * @FilePath: \C-posix\thread_2.cpp
 */

/*
    ref: https://www.runoob.com/cplusplus/cpp-multithreading.html
    �������g++ thread_2.cpp -lpthread -o thread_2.exe
    �������.\thread_2.exe
    ��Ҫʹ��F5һ������
*/


#include <iostream>
#include <pthread.h>// �����ͷ�ļ�
#include<windows.h>
 
using namespace std;

#define NUM_THREADS 5
 
// �̵߳����к���
void* say_hello(void* args)
{
    cout << "Hello Runoob start" << endl;
    Sleep(4000);        // ��ͣ4��
    cout << "Hello Runoob end" << endl;
    return 0;
}
 
int main()
{
    // �����̵߳� id �������������ʹ������
    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        //���������ǣ��������߳�id���̲߳��������õĺ���������ĺ�������
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //�ȸ����߳��˳��󣬽��̲Ž������������ǿ�ƽ����ˣ��߳̿��ܻ�û��Ӧ������
    pthread_exit(NULL);
    system("pause");
    return 0;
}


/*
 * @Author: seenli
 * @Date: 2021-03-16 21:48:03
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 13:07:43
 * @FilePath: \C-posix\thread_3.cpp
 */

/*
    ref: https://www.runoob.com/cplusplus/cpp-multithreading.html
*/

#include <iostream>
#include <cstdlib>
#include <pthread.h>
 
using namespace std;
 
#define NUM_THREADS     5
 
void *PrintHello(void *threadid)
{  
    // �Դ���Ĳ�������ǿ������ת������������ָ���Ϊ������ָ�룬Ȼ���ٶ�ȡ
    int tid = *((int*)threadid);
    cout << "Hello Runoob! �߳� ID, " << tid << endl;
    pthread_exit(NULL);
}
 
int main ()
{
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];// ������������i��ֵ
    int rc;
    int i;
    for( i=0; i < NUM_THREADS; i++ ){      
        cout << "main() : �����߳�, " << i << endl;
        indexes[i] = i; //�ȱ���i��ֵ
        // �����ʱ�����ǿ��ת��Ϊvoid* ���ͣ���������ָ��  
        // ���������ǣ��������߳�id���̲߳��������õĺ���������ĺ�������      
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&(indexes[i]));
        if (rc){
            cout << "Error:�޷������߳�," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    system("pause");
    return 0;
}
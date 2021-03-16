/*
 * @Author: seenli
 * @Date: 2021-03-16 21:36:00
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-16 21:40:35
 * @FilePath: \C-posix\thread_2.cpp
 */

/*
    ref: https://www.runoob.com/cplusplus/cpp-multithreading.html
    编译命令：g++ thread_2.cpp -lpthread -o thread_2.exe
    运行命令：.\thread_2.exe
    不要使用F5一键运行
*/


#include <iostream>
#include <pthread.h>// 必须的头文件
#include<windows.h>
 
using namespace std;

#define NUM_THREADS 5
 
// 线程的运行函数
void* say_hello(void* args)
{
    cout << "Hello Runoob start" << endl;
    Sleep(4000);        // 暂停4秒
    cout << "Hello Runoob end" << endl;
    return 0;
}
 
int main()
{
    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
    system("pause");
    return 0;
}


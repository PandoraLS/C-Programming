/*
 * @Author: seenli
 * @Date: 2021-03-16 21:32:19
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-16 21:35:04
 * @FilePath: \C-posix\win_sleep.cpp
 */

/*
    sleep()函数 
    linux:https://blog.csdn.net/chent86/article/details/76402708
    windows:https://blog.csdn.net/liuweiyuxiang/article/details/51674844
    标准库中无该函数
    linux中有，unsigned int sleep(unsigned int seconds)，传入挂起时间，成功返回0，不成功则返回余下的秒数。
    windows系统中有Sleep函数（注意大写），void Sleep(DWORD dwMilliseconds); 提供挂起的毫秒数。
*/

#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    cout << "start" << endl;
    Sleep(4000);//暂停4秒  S要大写
    cout << "end" << endl;
    system("pause");
    return 0;
}
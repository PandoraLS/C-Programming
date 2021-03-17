/*
 * @Author: seenli
 * @Date: 2021-03-16 21:32:19
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 13:00:08
 * @FilePath: \C-posix\win_sleep.cpp
 */

/*
    sleep()���� 
    linux:https://blog.csdn.net/chent86/article/details/76402708
    windows:https://blog.csdn.net/liuweiyuxiang/article/details/51674844
    ��׼�����޸ú���
    linux���У�unsigned int sleep(unsigned int seconds)���������ʱ�䣬�ɹ�����0�����ɹ��򷵻����µ�������
    windowsϵͳ����Sleep������ע���д��<windows.h>��void Sleep(DWORD dwMilliseconds); �ṩ����ĺ�������
*/

#include<iostream>
#include<windows.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
using namespace std;

int main()
{
    cout << "start...1" << endl;
    Sleep(4000);//��ͣ4��  SҪ��д  ȡ��ͷ�ļ�<windows.h>
    cout << "end...1" << endl;

    cout << "start...2" << endl;
    sleep(4);//��ͣ4��  SҪ��д ȡ��ͷ�ļ�<unistd.h>
    cout << "end...2" << endl;
    system("pause");
    return 0;
}
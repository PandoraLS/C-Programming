/*
 * @Author: seenli
 * @Date: 2021-03-16 21:32:19
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-16 21:35:04
 * @FilePath: \C-posix\win_sleep.cpp
 */

/*
    sleep()���� 
    linux:https://blog.csdn.net/chent86/article/details/76402708
    windows:https://blog.csdn.net/liuweiyuxiang/article/details/51674844
    ��׼�����޸ú���
    linux���У�unsigned int sleep(unsigned int seconds)���������ʱ�䣬�ɹ�����0�����ɹ��򷵻����µ�������
    windowsϵͳ����Sleep������ע���д����void Sleep(DWORD dwMilliseconds); �ṩ����ĺ�������
*/

#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    cout << "start" << endl;
    Sleep(4000);//��ͣ4��  SҪ��д
    cout << "end" << endl;
    system("pause");
    return 0;
}
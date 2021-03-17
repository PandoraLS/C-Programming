/*
 * @Author: seenli
 * @Date: 2021-03-17 13:54:13
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 13:56:54
 * @FilePath: \C-posix\time_use2.cpp
 */

/*
    ref: https://blog.csdn.net/xiong452980729/article/details/51394036
*/

#include<iostream>
#include<time.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
 
using namespace std;
 
int main()
{
	clock_t startTime,endTime;
	startTime = clock();
	for (int i = 0; i < 1000000; i++)
	{
		i++;
	}
    sleep(3);
	endTime = clock();
	cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
	return 0;
}


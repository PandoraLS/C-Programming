/*
 * @Author: seenli
 * @Date: 2021-03-17 13:57:34
 * @LastEditors: seenli
 * @LastEditTime: 2021-03-17 21:00:59
 * @FilePath: \C-posix\time_use3.c
 */


#include <stdio.h>
#include <time.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 


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
    printf("Totle Time %f second\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
	// cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
	return 0;
}


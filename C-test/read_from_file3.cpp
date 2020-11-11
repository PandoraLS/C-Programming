/*
 * @Author: seenli 
 * @Date: 2020-11-11 14:27:58 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-11 23:52:30
 */

/**
 * 读取文件到结束eof, 从文件中读取得到的数据放到动态内存分配中的数据中
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *lostFile; // 要读取的lost_flag.txt文件
    FILE *lost_file = NULL;   // 读取lost_flag.txt文件的指针
    int *lost_data = (int *)malloc(sizeof(int));  // 该指针用于动态内存分配，存储从lost_flag.txt文件中读取的数据
    int frame_count = 0, frame_i = 0;     // frame_count 用于统计 lost_flag.txt中数据的数目(帧数), frame_i单纯用于计数
    
    lost_file = fopen("read_data.txt", "r");
    if (lost_file == NULL) {
        printf("Could not open lost_flag file");
        return -1;
    }
    
    // 读取lost_flag.txt文件到lost_data中
    while (!feof(lost_file)) {
        fscanf(lost_file, "%d", &lost_data[frame_i]);
        // printf("%d\n", lost_data[frame_i]);  // 由于feof判断的时候会读入，所以会多输出一行
        frame_i++;
        lost_data = (int *)realloc(lost_data, sizeof(int)*(frame_i + 1));
    }
    
    frame_count = frame_i - 1;    // 最终lost_i会多读一行,所以这里减去1
    printf("frame_count: %d\n",frame_count);
    
    fclose(lost_file);        // 读取完之后关闭lost_flag.txt文件
    for (frame_i = 0; frame_i < frame_count; frame_i++) {
        printf("%d\n", lost_data[frame_i]);
    }
    printf("\n");
    free(lost_data);
    system("pause");
    return 0;
}


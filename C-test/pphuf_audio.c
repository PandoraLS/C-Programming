/*
 * @Author: seenli 
 * @Date: 2020-11-18 17:07:15 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-19 19:56:04
 */

//TODO 后面需要优化为[多线程]操作
/**
 * audio ping-pong buffer implement, 在实际引用过程中，ping pong两个寄存器应当开启一个多线程来并行操作
 * 这里只是单纯的假装并行(本质上依然是单线程实现的), 后面需要再优化为多线程并行操作
 * 参考链接：https://github.com/dnaco/MonkeyListen/blob/master/MonkeyListen/Sources/main.c
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>                             //system("pause");的头文件

volatile uint8_t RecordFlag = 0;                // record数据的标志位, 可能用不到
volatile uint8_t CurrentSample = 0;             // 统计ping-pong buffer已经record多少个数

volatile int16_t MicBuffer1[8];                 // 定义俩寄存器
volatile int16_t MicBuffer2[8];

volatile int16_t *Backbuffer;                   // record buffer
volatile int16_t *Activebuffer;                 // process buffer

/**
 * BufferPtr = 0: MicBuffer1处于processing状态, MicBuffer2处于record状态
 * BufferPtr = 1: MicBuffer2处于record状态, MicBuffer1处于processing状态
*/
volatile uint8_t BufferPtr = 0;                 // 表明不同的状态

uint16_t Pitch[8] = {60, 60, 60, 60, 61, 61, 61, 61}; // 两帧音频Pitch数据的模拟

int main(void)
{

    // 初始化MicBuffer1[8], 此时假设MicBuffer1是record好的
    for (int i = 0; i < 8; i++)
    {
        MicBuffer1[i] = Pitch[i];
    }

    //Initialize The Ping-pong Buffer.
    //back buffer will be fill up  while the processing(预测数据) is done on the foreground buffer
    BufferPtr = 0;
    Activebuffer = MicBuffer1;
    Backbuffer = MicBuffer2;

    //Start the Backbuffer Recording(初始化)
    RecordFlag = 1;

    int exe_num = 0; // 执行次数,真实情况这里应该是while(1)
    while (exe_num++ < 3)
    {
        printf("current execute times: %d\n", exe_num);
        
        // 如果准备好了用于process的buffer, 则执行processing
        // 假装process一下Active buffer, 将Active buffer中所有数据增加10
        for (int i = 0; i < 8; i++) {
            Activebuffer[i] += 10;
        }

        // Back buffer record 数据操作(这个操作应该和process并行操作的，不过这里并没有并行)
        // 假装是并行操作的, 假设新Record的数据为 Activebuffer[i] + 3
        for (CurrentSample = 0; CurrentSample < 8; CurrentSample++) {
            Backbuffer[CurrentSample] = Activebuffer[CurrentSample] + 3;
        }
        CurrentSample = 0; // CurrentSample 计数完毕，重置为0
        RecordFlag = 0;    // Recording 标志位也要置0

        // 输出结果
        printf("MicBuffer1: \t\t");
        for (int i = 0; i < 8; i++) {
            printf("%d, ",MicBuffer1[i]);
        }
        printf("         ");

        printf("MicBuffer2: \t\t");
        for (int i = 0; i < 8; i++) {
            printf("%d, ",MicBuffer2[i]);
        }
        printf("\n");

        // Swap the Active/Background Buffer ---> Ping Pong!
        if (BufferPtr == 0)
        {
            BufferPtr = 1;
            Activebuffer = MicBuffer2;
            Backbuffer = MicBuffer1;
        }
        else
        {
            BufferPtr = 0;
            Activebuffer = MicBuffer1;
            Backbuffer = MicBuffer2;
        }

        // 交换完两个内存之后，将Recording 标志位置为1，表明下一次计数的开始
        // 本代码中RecordFlag标志位并没有起到实质性的作用，仅仅是个幌子
        RecordFlag = 1;
    }

    system("pause");
    return 0;
}

/*
 * @Author: seenli 
 * @Date: 2020-11-18 17:07:15 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-18 18:47:15
 */


/**
 * audio ping-pong buffer implement
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> //system("pause");的头文件

volatile uint8_t Recording = 0;         // record数据的标志位, 可能用不到
volatile uint8_t CurrentSample = 0;     // 统计ping-pong buffer已经record多少个数

volatile int16_t MicBuffer1[8];       // 定义俩寄存器
volatile int16_t MicBuffer2[8];

volatile int16_t *Backbuffer;           // record buffer
volatile int16_t *Activebuffer;         // process buffer


/**
 * BufferPtr = 0: MicBuffer1处于processing状态, MicBuffer2处于record状态
 * BufferPtr = 1: MicBuffer2处于record状态, MicBuffer1处于processing状态
*/
volatile uint8_t BufferPtr = 0;         // 表明不同的状态

uint16_t Pitch[8] = {60,60,61,62,62,62,63,64};      // 两帧音频Pitch数据的模拟

int main(void) {

    // 初始化MicBuffer1[8]
    for (int i = 0; i < 8; i++) {
        MicBuffer1[i] = Pitch[i];
    }

    //Initialize The Ping-pong Buffer. 
    //back buffer will be fill up  while the processing(预测数据) is done on the foreground buffer
    BufferPtr = 0;
    Activebuffer = MicBuffer1;
    Backbuffer = MicBuffer2;

    //Reset the Sample pointer
    CurrentSample = 0;

    //Start the Backbuffer Recording
    Recording = 1;

    // 执行次数, 用于代替原有的while(1)
    uint8_t tmp_num = 4;

    while(tmp_num-- > 0) {
        printf("residue degree %d \n",tmp_num);
        
        // 如果准备好了用于process的back buffer
        
        // 假装process一下back buffer, 将back buffer中所有数据增加10
        for (int i = 0; i < 8; i++) {
            Activebuffer[i] += 10;
        }

        // Wait for the Background capture to complete
        while(Recording == 1) {
            
        }
        
    }
    
    
    system("pause");
    return 0;
}

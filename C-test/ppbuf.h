/*
 * @Author: seenli 
 * @Date: 2020-11-18 15:47:56 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-18 20:55:52
 */



/**
 * @brief simple ping-pong buffer implementation
 */

#ifndef PING_PONG_BUFFER_H_
#define PING_PONG_BUFFER_H_

#include <stdbool.h>

/* ping pong buffer control structure */
typedef struct {
	unsigned char *buffer_data;	// 存储数据的数组
	unsigned char *ping;		// ping指针
	unsigned char *pong;		// pong指针
	int buffer_size;
	int put_index;
	int get_index;
	bool full_signal;
}ppbuf_t;

/**
 * @brief insert on active buffer
 */
int ppbuf_insert_active(ppbuf_t *p, void *data, int size);

/**
 * @brief remove from inactive buffer
 */
int ppbuf_remove_inactive(ppbuf_t *p, void *data, int size);

/**
 * @brief get full signal
 */
bool ppbuf_get_full_signal(ppbuf_t *p, bool consume);


/* instantiate a fully initialized and static ping-pong buffer */
#define PPBUF_DECLARE(name,size)								\
		unsigned char ppbuf_mem_##name[size * 2] = {0};			\
		ppbuf_t name = {										\
			.buffer_data = &ppbuf_mem_##name[0],				\
			.ping = &ppbuf_mem_##name[0],						\
			.pong = &ppbuf_mem_##name[size],					\
			.buffer_size = size,								\
			.put_index = 0,										\
			.get_index = 0,										\
			.full_signal = false								\
		}

#endif /* PING_PONG_BUFFER_H_ */

/*
 * @Author: seenli 
 * @Date: 2020-11-18 15:47:27 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-18 20:32:50
 */

/**
 * @brief main application to test ping-pong-buffer
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h> //system("pause");的头文件
#include "ppbuf.h"

/* creates 一对 ping-pong-buffer*/
PPBUF_DECLARE(test, 4);

int main(void)
{
    unsigned char data = {110,110,110,110};
    unsigned char buf = {0,0,0,0};

    /* fill the active buffer with some raw value */
    while (ppbuf_get_full_signal(&test, false) != true)
    {
        /* insert values in active buffer */
        ppbuf_insert_active(&test, &data, sizeof(data));
        printf("data inserted on ping buffer: %hu", data);
        data += 2;

        /* gets the data on the pong buffer */
        ppbuf_remove_inactive(&test, &buf, sizeof(buf));
        printf("\t\tdata got from pong buffer: %hu \n\r", buf);
    }

    /* buffer full lets swap it */
    ppbuf_get_full_signal(&test, true);

    printf("SWAPPING BUFFERS! \n\r");

    data = 1;

    /* fill the active buffer with some raw value */
    while (ppbuf_get_full_signal(&test, false) != true)
    {
        /* insert values in active buffer */
        ppbuf_insert_active(&test, &data, sizeof(data));
        printf("data inserted on ping buffer: %hu", data);
        data += 2;

        /* gets the data on the pong buffer */
        ppbuf_remove_inactive(&test, &buf, sizeof(buf));
        printf("\t\tdata got from pong buffer: %hu \n\r", buf);
    }

    system("pause");
    return 0;
}

/**
 * @brief simple ping pong buffer implementation
 */

int ppbuf_insert_active(ppbuf_t *p, void *data, int size)
{
    int ret = 0;
    unsigned char *ptr;

    if (p == NULL || data == NULL || size == 0)
    {
        /* check your parameters */
        ret = -1;
    }
    else
    {
        if (size > (p->buffer_size - p->put_index))
        {
            /* not enough room for new samples */
            ret = -1;
        }
        else
        {
            /* take the current position */
            int mem_position = ((p->ping) * p->buffer_size) + p->put_index;
            ptr = (unsigned char *)p->buffer_data;

            /* copy the contents */
            memcpy(&ptr[mem_position], data, size);

            /* update put index */
            p->put_index += size;
            p->full_signal = (p->put_index >= p->buffer_size ? true : false);

            /* swap will only generated when ppbuf_get_full_signal is called */
            ret = 0;
        }
    }
    return (ret);
}

int ppbuf_remove_inactive(ppbuf_t *p, void *data, int size)
{
    int ret = 0;
    unsigned char *ptr;

    if (p == NULL || data == NULL || size == 0)
    {
        /* check your parameters */
        ret = -1;
    }
    else
    {
        if (size > (p->buffer_size - p->get_index))
        {
            /* not enough data in sample buffer */
            ret = -1;
        }
        else
        {
            /* take the current position */
            int mem_position = ((p->pong) * p->buffer_size) + p->get_index;
            ptr = (unsigned char *)p->buffer_data;

            /* copy the contents */
            memcpy(data, &ptr[mem_position], size);

            /* update put index */
            p->get_index += size;

            /* when buffer is empty we are not able to extract anymore data */
            ret = 0;
        }
    }
    return (ret);
}

bool ppbuf_get_full_signal(ppbuf_t *p, bool consume)
{
    /* take the last signaled full occurrence */
    bool ret = (p != NULL ? p->full_signal : false);

    if ((consume != false) && (p != NULL) && (ret != false))
    {
        p->full_signal = false;

        /* swap the buffer switches */
        p->ping[0] = p->ping[0] ^ p->pong[0];
        p->pong[0] = p->pong[0] ^ p->ping[0];
        p->ping[0] = p->ping[0] ^ p->pong[0];

        /* resets the buffer position */
        p->get_index = 0;
        p->put_index = 0;
    }
    return (ret);
}

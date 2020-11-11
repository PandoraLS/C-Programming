/*
 * @Author: seenli 
 * @Date: 2020-11-11 16:53:31 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-11 19:34:43
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
 
int main()
{
    size_t size = sizeof(char) * 10;
    char *a = (char *)malloc(size);
    char *current;
    ptrdiff_t diff;

    current = a;
    do {
        scanf("%c", current);
        if (current - a >= size - 1){
            size *= 2;
            diff = current - a;
            a = (char *)realloc(a, size);
            current = a + diff;
        }
    }while (*current++ != '\n');

    *current = '\x0';

    system("pause");
    return(0);
}
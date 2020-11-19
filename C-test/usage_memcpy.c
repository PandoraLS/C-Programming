/*
 * @Author: seenli 
 * @Date: 2020-11-19 10:21:33 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-19 10:25:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int abc[3], def[3] = {1, 2, 3};
    memcpy(abc, def, sizeof(abc));
    for (int i = 0; i < sizeof(def) / sizeof(int); i++) {
        printf("%d,",abc[i]);
    }
    system("pause");
    return 0;
}

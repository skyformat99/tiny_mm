/*
 * FileName : test.c
 * Author   : xiahouzuoxin @163.com
 * Version  : v1.0
 * Date     : 2014/10/18 10:54:25
 * Brief    : 
 * 
 * Copyright (C) MICL,USTB
 */

#include <stdio.h>
#include "Config.h"
#include "tiny_mm.h"

#define NX      (100)
uint8_t x[NX];

int main(void) 
{
    float *data1;
    int   *data2;
    int   i =0;

    struct st_tiny_mm gb_mm;
    tiny_mm_create(&gb_mm, (uint8_t *)x, sizeof(uint8_t)*NX);
    data1 = (float *)tiny_mm_get(&gb_mm, 4*sizeof(float));
    if (data1) {
        // process data1 here
        data1[0] = 1;
        data1[1] = 2;
        data1[2] = 3;
        data1[3] = 4;
    } else {
        printf("Alloc for data1 error\n");
    }
    data2 = (int *)tiny_mm_get(&gb_mm, 3*sizeof(int));
    if (data2) {
        // process data2 here
        data2[0] = 10;
        data2[1] = 20;
        data2[2] = 30;
    } else {
        printf("Alloc for data2 error\n");
    }

    printf("data1: ");
    for (i=0; i<4; i++) {
        printf("%.1f ", data1[i]);
    }
    printf("\n");

    printf("data2: ");
    for (i=0; i<3; i++) {
        printf("%d ", data2[i]);
    }
    printf("\n");

    // Be careful: must free data2 first than data1 just like a stack.
    // So that @tiny_mm module is suite for temporary memory alloc in subfunction.
    tiny_mm_put(&gb_mm, (uint32_t **)(&data2), 3*sizeof(float));
    tiny_mm_put(&gb_mm, (uint32_t **)(&data1), 4*sizeof(int));

    if (NULL== data1) {
        printf("data1 is NULL\n");
    }
    if (NULL== data2) {
        printf("data2 is NULL\n");
    }

    return 0;
}



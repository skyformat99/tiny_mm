/*
 * FileName : tiny_mm.c
 * Author   : xiahouzuoxin @163.com
 * Version  : v1.0
 * Date     : 2014/10/18 10:26:28
 * Brief    : A simple memory management and been 
 *            used in 32-bits embeded system.
 *
 * ==== Example for use ====
 *
 * #define NX      (100)
 * int x[NX];
 * float *data1;
 * int   *data2;
 *
 * struct st_tiny_mm gb_mm;
 * tiny_mm_create(&gb_mm, (uint8_t)x, sizeof(int)*NX);
 * data1 = (float *)tiny_mm_get(&gb_mm, 4*sizeof(float));
 * if (data1) {
 *     // process data1 here
 * }
 * data2 = (int *)tiny_mm_get(&gb_mm, 3*sizeof(int));
 * if (data2) {
 *     // process data2 here
 * }
 *
 * // Be careful, must free data2 first than data1 just like a stack.
 * // So that @tiny_mm module is suite for temporary memory alloc in subfunction.
 * tiny_mm_put(&gb_mm, (uint32_t **)(&data2), 3*sizeof(float));
 * tiny_mm_put(&gb_mm, (uint32_t **)(&data1), 4*sizeof(int));
 * 
 * Copyright (C) MICL,USTB
 */

#include "tiny_mm.h"
 
/*
 * @brief   Create a memory block
 * @inputs  
 *   mm      tiny_mm structure
 *   buf     an array have been definited
 *   n_bytes length of array in bytes unit
 * @outputs 
 * @retval  
 */
void tiny_mm_create(struct st_tiny_mm *mm, uint8_t *buf, uint32_t n_bytes)
{
    mm->buf     = buf;
    mm->max_len = n_bytes;    
    mm->cur_len = 0;
}


/*
 * @brief   Get a part from memory block
 * @inputs  
 *   mm      tiny_mm structure
 *   n_bytes length want to get in bytes unit
 * @outputs 
 * @retval  
 */
void *tiny_mm_get(struct st_tiny_mm *mm, uint32_t n_bytes)
{
    void *ret = (void *)0;

    if (mm->cur_len + n_bytes < mm->max_len) {
        ret = mm->buf + mm->cur_len;
        mm->cur_len += n_bytes;
    } else {
        //
    }

    return ret;
}

/*
 * @brief   Put a part to memory block.
 *   Alloc and Free memory process must be like a stack, 
 *   otherwise it will return a 0 error.
 * @inputs  
 *   mm        tiny_mm structure
 *   buf_addr  the address of *buf want to free
 *   n_bytes   length want to put in bytes unit
 * @outputs 
 * @retval  
 */
uint8_t tiny_mm_put(struct st_tiny_mm *mm, uint32_t **buf_addr, uint32_t n_bytes)
{
    if (mm->cur_len < n_bytes) {
        return 0;
    } else {
        mm->cur_len -= n_bytes;
        if ((uint32_t)(*buf_addr) != (uint32_t)(mm->buf + mm->cur_len)) {
            mm->cur_len += n_bytes;  // free a error position
            return 0;
        }
        *buf_addr = (void *)0;
        return 1;
    }
}


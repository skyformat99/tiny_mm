/*
 * FileName : E:\MyDesigner\Projects\tiny_mm\tiny_mm.h
 * Author   : xiahouzuoxin @163.com
 * Version  : v1.0
 * Date     : 2014/10/18 10:30:02
 * Brief    : 
 * 
 * Copyright (C) MICL,USTB
 */
#ifndef  _TINY_MM_H
#define  _TINY_MM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Config.h"

struct st_tiny_mm {
    uint8_t *buf;
    uint32_t max_len;
    uint32_t cur_len;
};

extern void tiny_mm_create(struct st_tiny_mm *mm, uint8_t *buf, uint32_t n_bytes);
extern void *tiny_mm_get(struct st_tiny_mm *mm, uint32_t n_bytes);
extern uint8_t tiny_mm_put(struct st_tiny_mm *mm, uint32_t **buf_addr, uint32_t n_bytes);

#ifdef __cplusplus
}
#endif
#endif  /*_TINY_MM_H*/

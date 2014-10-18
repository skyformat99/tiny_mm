## Discription

小型的内存管理代码，用于32-bit的嵌入式平台。

该模块现在在子函数中合理使用内存有用。进子函数时按顺序A,B,C分配内存，出子函数时按C,B,A的逆序释放内存。
相当于将一大块内存按栈的方式手动进行管理。

已应用于DSP6713处理器信号采集模块中的大块内存管理。

## Usage

```c
#define NX      (100)
int x[NX];
float *data1;
int   *data2;

struct st_tiny_mm gb_mm;
tiny_mm_create(&gb_mm, (uint8_t)x, sizeof(int)*NX);
data1 = (float *)tiny_mm_get(&gb_mm, 4*sizeof(float));
if (data1) {
    // process data1 here
}
data2 = (int *)tiny_mm_get(&gb_mm, 3*sizeof(int));
if (data2) {
    // process data2 here
}

// Be careful, must free data2 first than data1 just like a stack.
// So that @tiny_mm module is suite for temporary memory alloc in subfunction.
tiny_mm_put(&gb_mm, (uint32_t **)(&data2), 3*sizeof(float));
tiny_mm_put(&gb_mm, (uint32_t **)(&data1), 4*sizeof(int));
```

## About Me 

<xiahouzuoxin@163.com>

Copyright (c) MICL, USTB.
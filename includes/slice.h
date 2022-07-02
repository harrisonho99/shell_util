#include "mem.h"

typedef struct
{
    int cap;
    int len;
    byte_t *pool;
} slice_t;
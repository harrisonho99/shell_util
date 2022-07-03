#include "mem.h"
typedef struct
{
    size_t cap;
    size_t len;
    byte_t *pool;
} slice_t;

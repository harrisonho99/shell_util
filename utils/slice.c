
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "slice.h"

/**
 * @brief grow slice by dupble the size of it
 *
 * @param sl
 * @param n
 * @return slice_t*
 */
slice_t *slice_grow(slice_t *sl, size_t n)
{
    // dupble the capacity, at least n
    sl->cap = (sl->cap * 2) + n;
    // realloc already copy content to new pool and free the old one
    void *new_pool = realloc(sl->pool, sl->cap);
    if (new_pool == NULL)
    {
        printf("Error: slice realloc failed\n");
        exit(1);
    }
    sl->pool = new_pool;
    return sl;
}

/**
 * @brief make a slice memory
 *
 * @param len
 * @param cap
 * @return slice_t*
 */
slice_t *make_slice(size_t len, size_t cap)
{
    slice_t *sl = (slice_t *)calloc(1, sizeof(slice_t));
    if (sl == NULL)
    {
        printf("Error: slice malloc failed\n");
        exit(1);
    }
    sl->len = len;
    sl->cap = cap;
    sl->pool = (byte_t *)calloc(cap, sizeof(byte_t));
    if (sl->pool == NULL)
    {
        printf("Error: slice pool malloc failed\n");
        exit(1);
    }
    return sl;
}

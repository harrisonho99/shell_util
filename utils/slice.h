#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../includes/slice.h"
#include "../includes/mem.h"

slice_t *slice_grow(slice_t *sl, size_t n);
slice_t *make_slice(size_t len, size_t cap);

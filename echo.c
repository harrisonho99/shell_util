#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "./utils/slice.h"
// The MIT License (MIT)

// Copyright (c) 2022 Harrison Ho

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

// UNIX  echo
#define POOl_MAX_SIZE 1073741824 // 1GB
// prototype
char *growCharPool(char *pool, size_t old_size);

int main()
{
    int argc = 3;
    char const *argv[] = {"echo", "hello", "world"};

    char *src = "hoang";
    slice_t *slice = make_slice(strlen(src) + 1, strlen(src) + 1);
    memcpy(slice->pool, src, strlen(src));
    slice->pool[strlen(src)] = '\0';
    printf("%s\n", (char *)slice->pool);

    // clean up
    free(slice->pool);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int main(int argc, char const *argv[])
{

    // seperator
    char *sep = '-';

    // last index
    int last_index = argc - 2;

    // string pool
    int pool_size = 1024;
    int max_pool_index = pool_size - 1;
    char *pool = (char *)malloc(pool_size);
    int pool_index = 0;

    for (int i = 1; i < argc; i++)
    {
        int str_len = strlen(argv[i]);
        if (i != last_index)
        {

            // 1 byte (sep)
            pool_index += (str_len + 1);
        }
    }




    free(pool);
    return 0;
}

void *grow()
{
}
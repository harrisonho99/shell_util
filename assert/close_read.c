#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{

    int p[2]; // define pipe

    int status = pipe(p);
    if (status == -1)
    {
        perror("pipe\n");
        exit(2);
    }

    if (fork() == 0) // child process
    {
        sleep(2);    // wait parrent
        close(p[0]); // close read end
    }
    else
    {
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        int n = read(p[0], buffer, BUFFER_SIZE);
        printf("n :%d\n", n);
        printf("%s\n", buffer);
    }

    /* code */
    return 0;
}

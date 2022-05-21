#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// define unix pwd command
#ifndef MAX_BUF
#define MAX_BUF 8192 // 8bytes
#endif
int main(int argc, char const *argv[])
{
    char path[MAX_BUF];
    getcwd(path, MAX_BUF);
    printf("%s\n", path);
    return 0;
}

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    int pid = fork();
    if (pid == 0)
    {
        sleep(2);
        printf("Child process done\n");
    }
    else
    {
        wait(&pid);
    }

    return 0;
}

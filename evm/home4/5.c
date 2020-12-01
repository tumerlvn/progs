#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int size = atoi(argv[1]);
    pid_t pid;

    for (int i = 0; i < size; i++) {
        pid = fork();
        if (pid == 0) {
            printf("%u %u\n", getpid(), getppid());
            //continue;
        } else {
            wait(NULL);
            break;
        }
    }
    return 0;
}

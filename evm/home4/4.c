#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int size = atoi(argv[1]);
    pid_t pid;
    for (int i = 0; i < size; i++) {
        pid = fork();
        if (pid == 0) {
            printf("%u %u\n", getpid(), getppid());
            break;
        } else {
            wait(NULL);
        }
    }
    return 0;
}

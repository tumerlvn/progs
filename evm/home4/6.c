#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    char fname[100];
    int len = strlen(argv[1]);
    for (int i = 0; i < len - 2; i++) {
        fname[i] = argv[1][i];
    }
    fname[len] = '\0';
    execlp("gcc", "gcc", argv[1], "-o", fname, "-Wall", "-Werror", NULL); 
    return 0;
}

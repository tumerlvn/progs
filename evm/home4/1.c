#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const **argv) {
    char fname[100];
    strcpy(fname, argv[1]);
    char text;
    int fd = open(fname, O_RDONLY);
    while (read(fd, &text, 1) > 0)
        write(1, &text, 1);
    close(fd); 
    return 0;
}

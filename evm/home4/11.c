#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const **argv) {
    char fname[100];
    strcpy(fname, argv[0]);
    int len = strlen(fname);
    //strcpy(fname + len, ".c");
    char text;
    puts(fname);
    

    return 0;
}

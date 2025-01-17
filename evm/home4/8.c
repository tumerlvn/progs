#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

struct Image {
    char preheader[18];
    int w, h;
};

struct Image openImage(char *filename) {
    struct Image img;
    int fd = open(filename, O_RDONLY);
    read(fd, &img.preheader, sizeof(img.preheader));
    read(fd, &img.w, sizeof(img.w));
    read(fd, &img.h, sizeof(img.h));
    close(fd);
    return img;
}

int main(int argc, char const **argv) {
    char fname[100];
    strcpy(fname, argv[1]);
    struct Image img = openImage(fname);
    printf("%d %d\n", img.w, img.h);
    return 0;
}

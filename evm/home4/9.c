#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Pixel {
    unsigned char r, g, b;
};

struct Image {
    char preheader[18];
    int w, h;
    char postheader[28];
    struct Pixel **pixmap;
};

struct Image openImage(char *filename) {
    struct Image img;
    int fd = open(filename, O_RDONLY);
    read(fd, &img.preheader, sizeof(img.preheader));
    read(fd, &img.w, sizeof(img.w));
    read(fd, &img.h, sizeof(img.h));
    read(fd, &img.postheader, sizeof(img.postheader));
    struct Pixel tmp;
    img.pixmap = malloc(img.h * sizeof(struct Pixel *));
    for (int i = 0; i < img.h; i++) {
        img.pixmap[i] = malloc(img.w * sizeof(struct Pixel));
        for (int j = 0; j < img.w; j++) {
            read(fd, &tmp.r, 1);
            read(fd, &tmp.g, 1);
            read(fd, &tmp.b, 1);
            img.pixmap[i][j] = tmp;
        }
    }
    close(fd);
    return img;
}

void saveImage(struct Image img, char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
                            S_IRUSR | S_IWUSR);
    write(fd, &img.preheader, sizeof(img.preheader));
    write(fd, &img.w, sizeof(img.w));
    write(fd, &img.h, sizeof(img.h));
    write(fd, &img.postheader, sizeof(img.postheader));
    for (int i = img.h - 1; i >= 0; i--) {
        for (int j = 0; j < img.w; j++) {
            write(fd, &img.pixmap[i][j].r, 1);
            write(fd, &img.pixmap[i][j].g, 1);
            write(fd, &img.pixmap[i][j].b, 1);
        }
    }
    close(fd);
}

int main(int argc, char const **argv) {
    char fname[100];
    strcpy(fname, argv[1]);
    struct Image img = openImage(fname);
    strcpy(fname, argv[2]);
    saveImage(img, fname);
    return 0;
}

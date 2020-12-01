#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int getGrad(int i, int j, int **d, int w, int h) {
    int lenV = 0;
    int *vec = NULL;
    int max;
    if (i == 0) {
        lenV++;
        vec = realloc(vec, lenV);
        vec[lenV] = abs(d[i][j] - d[i + 1][j]);
    } else if (i == h - 1) {
        lenV++;
        vec = realloc(vec, lenV);
        vec[lenV] = abs(d[i][j] - d[i - 1][j]);
    } else {
        lenV += 2;
        vec = realloc(vec, lenV);
        vec[lenV - 1] = abs(d[i][j] - d[i + 1][j]);
        vec[lenV] = abs(d[i][j] - d[i - 1][j]);
    }
    if (j == 0) {
        lenV++;
        vec = realloc(vec, lenV);
        vec[lenV] = abs(d[i][j] - d[i][j + 1]);
    } else if (i == h - 1) {
        lenV++;
        vec = realloc(vec, lenV);
        vec[lenV] = abs(d[i][j] - d[i][j - 1]);
    } else {
        lenV += 2;
        vec = realloc(vec, lenV);
        vec[lenV - 1] = abs(d[i][j] - d[i][j + 1]);
        vec[lenV] = abs(d[i][j] - d[i][j - 1]);
    }
    max = vec[0];
    for (int i = 1; i < lenV; i++) {
        if (max < vec[i]) {
            max = vec[i];
        }
    }
    free(vec);
    return max;
}

void saveImage(struct Image img, char *filename, int level) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
                            S_IRUSR | S_IWUSR);
    write(fd, &img.preheader, sizeof(img.preheader));
    write(fd, &img.w, sizeof(img.w));
    write(fd, &img.h, sizeof(img.h));
    write(fd, &img.postheader, sizeof(img.postheader));
    int black = 0;
    int white = 255;
    int **d = malloc(img.h * sizeof(int *));
    for (int i = 0; i < img.h; i++) {
        d[i] = malloc(img.w * sizeof(int));
        for (int j = 0; j < img.w; j++) {
            d[i][j] = img.pixmap[i][j].r + img.pixmap[i][j].g + img.pixmap[i][j].b;
        }
    }

    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            if (getGrad(i, j, d, img.w, img.h) > level) {
                write(fd, &black, 1);
                write(fd, &black, 1);
                write(fd, &black, 1);
            } else {
                write(fd, &white, 1);
                write(fd, &white, 1);
                write(fd, &white, 1);
            }
        }
    }
    for (int i = 0; i < img.h; i++) {
        free(d[i]);
    }
    free(d);
    close(fd);
}

int main(int argc, char const **argv) {
    char fname[100];
    strcpy(fname, argv[1]);
    struct Image img = openImage(fname);
    strcpy(fname, argv[2]);
    int level = atoi(argv[3]);
    saveImage(img, fname, level);
    //printf("%d %d\n", img.w, img.h);
    return 0;
}

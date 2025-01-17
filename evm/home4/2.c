#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int rzrd(int num) {
    int tmp = 1;
    while (num > 9) {
        num /= 10;
        tmp *= 10;
    }
    return tmp;
}

void printInt(int num) {
    if (num == 0) {
        write(1, "0", 1);
        return;
    }
    int cnt = rzrd(num);
    char tmp;
    while (num > 0) {
        tmp = num / cnt + '0';
        num = num - (num / cnt) * cnt;
        cnt /= 10;
        write(1, &tmp, 1);
    }
}

int main(int argc, char const **argv) {
    char fname[100];
    strcpy(fname, argv[1]);
    int len = strlen(fname);
    char text;
    int ncnt = 0;
    int wcnt = 0;
    int bcnt = 0;

    int fd = open(fname, O_RDONLY);
    while (read(fd, &text, 1) > 0) {
        if (text == '\n') {
            ncnt++;
            wcnt++;
        } else if (text == ' ') {
            wcnt++;
        }
        bcnt++;
    }
    bcnt--;

    printInt(ncnt);
    write(1, " ", 1);
    printInt(wcnt);
    write(1, " ", 1);
    printInt(bcnt);
    write(1, "\n", 1);
    close(fd);
    return 0;
}

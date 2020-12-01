#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const **argv) {
    char fname0[100];
    char fname1[100];
    strcpy(fname0, argv[1]);
    strcpy(fname1, argv[2]);
    char text;

    int fdsrc = open(fname0, O_RDONLY);
    int fddst = open(fname1, O_WRONLY | O_CREAT | O_TRUNC,
                            S_IRUSR | S_IWUSR);
    while (read(fdsrc, &text, 1) > 0) {
        if (('a' <= text && text <= 'z') || ('A' <= text && text <= 'Z') || text == ' ' || text == '\n') {
            write(fddst, &text, 1);
        }
    }
    close(fdsrc);
    close(fddst);
}

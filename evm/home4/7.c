#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    char *s = malloc(11 * sizeof(char));
    pid_t pid;
    fgets(s, 11, stdin);
    int len = strlen(s);
    s[len - 1] = '\0';
    //printf("%s %d\n", s, strcmp(s, "exit"));
    while (strcmp(s, "exit") && strcmp(s, "quit")) {
        pid = fork();
        if (pid == 0) {
            execlp(s, s, NULL);
            break;
        } else {
            wait(NULL);
        }
        fgets(s, 11, stdin);
        len = strlen(s);
        s[len - 1] = '\0';
    }
    free(s);
    return 0;
}

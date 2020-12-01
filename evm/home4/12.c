# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
int main ( int argc , char ** argv ) {
    pid_t pid = fork ();
    if (pid == 0) {
        printf("I am child, pid: %u\n",
        getpid());
    } else {
        printf("I am parent, pid: %u\n",
        getpid());
    }
    while (1) {
    }
    return 0;
}

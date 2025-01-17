#include <stdio.h>

int main() {
    char time[9];
    int seconds;
    int tmp = 0;
    scanf("%8s\n", time);
    scanf("%d", &seconds);
    for (int i = 2; i >= 0; i--) {
        tmp += (time[i * 3] - '0') * 10 + (time[i * 3 + 1] - '0');
        tmp += seconds % 60;
        if (i) {
            time[i * 3] = (tmp % 60) / 10 + '0';
            time[i * 3 + 1] = (tmp % 60) % 10 + '0';
        } else {
            time[i * 3] = (tmp % 24) / 10 + '0';
            time[i * 3 + 1] = (tmp % 24) % 10 + '0';
        }
        tmp /= 60;
        seconds /= 60;
    }
    printf("%s", time);
    return 0;
}

#include <stdio.h>

int main() {
    int input;
    scanf("%d\n", &input);
    char c;
    int result = 0;
    while ((c = getchar()) != '\n') {
        result *= 10;
        int tmp;
        tmp = c - '0';
        result += tmp;
        result %= input;
    }
    printf("%d\n", result);
    return 0;
}

#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    for (int i = 2; i <= input; i++) {
        if (input % i == 0 && i % 2 == 0) {
            printf("%d ", i);
        }
    }

    puts("");
    return 0;
}

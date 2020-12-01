#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    int counter = 0;
    for (int i = 3; input % i == 0; i *= 3) {
        counter++;
    }
    printf("%d", counter);
    return 0;
}

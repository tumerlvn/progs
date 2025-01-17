#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    int64_t input;
    int output = 0;
    scanf("%"PRId64, &input);
    while (input) {
        if (output < input % 10) {
            output = input % 10;
        }
        input /= 10;
    }
    printf("%d", output);
    return 0;
}

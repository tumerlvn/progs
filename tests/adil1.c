#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a_size, b_size;
    scanf("%d%d", &a_size, &b_size);
    int *a = malloc(a_size * sizeof(int));
    int *b = malloc(b_size * sizeof(int));
    for (int i = 0; i < a_size; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < b_size; i++) {
        scanf("%d", &b[i]);
    }

    return 0;
}

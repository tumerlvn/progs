#include <stdio.h>

int main() {
    int iter;
    scanf("%d", &iter);

    for (int i = 0; i < iter; i++) {
        int n;
        scanf("%d", &n);
        printf("%d ", n);
        for (int j = 1; j < n; j++) {
            printf("%d ", j);
        }
    }
    return 0;
}

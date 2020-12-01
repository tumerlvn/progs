#include <stdio.h>

int main() {
    int size;
    int a[10][10];
    int b[10];
    int tmp = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < size; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tmp += a[i][j] * b[j];
        }
        printf("%d\n", tmp);
        tmp = 0;
    }
    return 0;
}

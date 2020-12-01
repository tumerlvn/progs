#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int size = 0;
    int actualSize = 2;
    int *arr = malloc(actualSize * sizeof(int));
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            if (actualSize <= size + 1) {
                actualSize *= 2;
                arr = realloc(arr, actualSize * sizeof(int));
            }
            arr[size] = i;
            size++;
        }
    }
    arr[size] = n;
    size++;
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    free(arr);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **downTriangle(int n) {
    int **arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc((i + 1) * sizeof(int));
        for (int j = 0; j < i + 1; j++) {
            arr[i][j] = i + j + 2;
        }
    }
    return arr;
}

void freeArr(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

void printDownTriangle(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int **arr = downTriangle(n);
    printDownTriangle(arr, n);
    freeArr(arr, n);
    return 0;
}

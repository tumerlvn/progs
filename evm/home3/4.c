#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **memArr(int n) {
    int **arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));
    }
    return arr;
}

void freeArr(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

void initArr(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printArr(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int **arr = memArr(n);
    initArr(arr, n);
    int *tmp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = tmp;
    printArr(arr, n);
    freeArr(arr, n);
    return 0;
}

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

void printVec(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    puts("");
}

void squareMat(int **src, int **dst, int size) {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            dst[i][k] = 0;
            for (int j = 0; j < size; j++) {
                dst[i][k] += src[i][j] * src[j][k];
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int **arr = memArr(n);
    int **res = memArr(n);
    initArr(arr, n);
    //printArr(arr, n);
    squareMat(arr, res, n);
    printArr(res, n);
    freeArr(arr, n);
    freeArr(res, n);
}

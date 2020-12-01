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

int modules(int *arr, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += abs(arr[i]);
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int **arr = memArr(n);
    initArr(arr, n);
    //printArr(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", modules(arr[i], n));
    }
    puts("");
    freeArr(arr, n);
}

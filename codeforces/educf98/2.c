#include <stdio.h>
#include <stdlib.h>

int main() {
    int iter;
    scanf("%d", &iter);
    int* result = malloc(iter * sizeof(int));
    for (int i = 0; i < iter; i++) {
        int max;
        int min;
        int sum = 0;
        int boxes;
        scanf("%d", &boxes);
        int* array = malloc(boxes * sizeof(int));
        scanf("%d", &(array[0]));
        sum += array[0];
        max = array[0];
        for (int j = 1; j < boxes; j++) {
            scanf("%d", &(array[j]));
            sum += array[j];
            if (max < array[j]) max = array[j];
        }
        result[i] = (boxes - 1) * max - sum; 
        if (result[i] < 0) {
            result[i] %= boxes - 1;
            if (result[i] != 0) result[i] += boxes - 1;
        }
        free(array);
    }
    for (int i = 0; i < iter; i++) {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}

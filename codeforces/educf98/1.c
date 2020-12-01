#include <stdio.h>
#include <stdlib.h>

int main() {
    int iter;
    scanf("%d", &iter);
    int* cntArr = malloc(iter * sizeof(int));
    for (int i = 0; i < iter; i++) {
        int x, y;
        int min;
        int max;
        int cnt = 0;
        scanf("%d %d", &x, &y);
        if (x > y) {
            min = y;
            max = x;
        } else {
            min = x;
            max = y;
        }
        cnt += min * 2;
        if (max > min) 
        cnt += (max - min) * 2 - 1;
        cntArr[i] = cnt;
    }
    for (int i = 0; i < iter; i++) {
        printf("%d\n", cntArr[i]);
    }
    free(cntArr);
    return 0;
}

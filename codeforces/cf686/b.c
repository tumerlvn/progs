#include <stdio.h>
#include <stdlib.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int n;
        scanf("%d", &n);
        int *arr = malloc(n * sizeof(int));
        int *check = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            check[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &(arr[j]));
            if (check[arr[j] - 1] == 0) {
                check[arr[j] - 1] = j + 1; 
            } else {
                check[arr[j] - 1] = -1;
            }
        }
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (check[j] > 0) {
                flag = 0;
                printf("%d\n", (check[j])); 
                break;
            }
        }
        if (flag) {
            printf("-1\n");
        }
        free(arr);
        free(check);
    }
}

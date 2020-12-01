#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d", &size);
    int arr[1000000];
    arr[0] = 0;
    for (int i = 1; i < size; i++) {
        arr[i] = 1;
    }
    for (int i = 1; i < size/2; i++) {
        if (arr[i]) {
            for (int j = (i + 1) * 2 - 1; j < size; j += i + 1) {
                arr[j] = 0;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts(" ");
    return 0;
}

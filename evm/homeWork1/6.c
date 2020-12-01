#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxsum = 0;
    int currentsum = 0;
    for (int i = 0; i < n; i++) {
        currentsum += arr[i];
        if (currentsum < 0) {
            currentsum = 0;
        }
        if (maxsum < currentsum) {
            maxsum = currentsum;
        }
    }
    printf("%d\n", maxsum);
    return 0;
}

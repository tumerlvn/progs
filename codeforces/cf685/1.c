#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int cnt = 0;
        while (x != 1) {
            for (int j = x/2; j >= 1; j--) {
                if (x % 2 == 1) {
                    x--;
                    cnt++;
                    break;
                }
                if (j != 1 && x % j == 0) {
                    x /= j;
                    cnt++;
                    break;
                }
                if (j == 1) {
                    x--;
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

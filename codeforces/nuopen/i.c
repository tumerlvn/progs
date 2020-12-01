#include <stdio.h>

int main() {
    int n, x;
    int min = 0, max = 0;
    scanf("%d %d", &n, &x);

    if (n-1 >= x)
        min = 1;
    else if (x % (n-1) == 0)
        min = x / (n-1);
    else
        min = x / (n-1) + 1;

    if (n-1 >= x)
        max = 1;
    else if (x % (n-1) != 0)
        max = (x / (n-1)) * 2 + 1;
    else
        max = (x / (n-1)) * 2 - 1;
    printf("%d %d\n", min, max);
    return 0;
}

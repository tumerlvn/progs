#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d\n", &n);
    char *s = malloc(n * sizeof(char));
    int result = 0;
    for (int i = 0; i < n; i++) {
        s[i] = getchar();
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = i - 1; j >= 0 && (n-1) - i >= i - j; j--) {
            if (s[i] == s[j] && s[i] == s[2 * i - j])
                result++;
        }
    }
    printf("%d\n", result);
    free(s);
    return 0;
    //1 2 1 2 3 
    //1 2 3 2 1
}

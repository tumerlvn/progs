#include <stdio.h>
#include <stdlib.h>

int main() {
    int iter;
    scanf("%d", &iter);

    for (int i = 0; i < iter; i++) {
        int n, k;
        scanf("%d %d\n", &n, &k);
        char *str = malloc((n + 1) * sizeof(char));
        char *bstr = malloc((n + 1) * sizeof(char));
        int a[26] = {0};
        int b[26] = {0};
        for (int j = 0; j <= n; j++) {
            str[j] = getchar(); 
            if (j != n)
                a[str[j] - 'a']++;
        }
        str[n] = 0;
        for (int j = 0; j <= n; j++) {
            bstr[j] = getchar(); 
            if (j != n)
                b[bstr[j] - 'a']++;
        }
        bstr[n] = 0;
        int flag = 1;
        for (int j = 0; j < 26; j++) {
            if (b[j] == 0) {
                continue;
            }
            if ((b[j] - a[j]) % k != 0) {
                flag = 0; 
                break;
            } else {
                if (a[j] != b[j]) {
                    for (int l = 0; l < j; l++) {
                        if (a[l] == b[l]) continue;
                        if (b[j] - a[j] >= a[l] - b[l]) {
                            a[j] += a[l] - b[l];
                            a[l] = b[l];
                        } else {
                            a[j] = b[j];
                            a[l] -= (b[j] - a[j]);
                        }
                    }
                    if (a[j] != b[j]) {
                        flag = 0;
                        break;
                    }
                }
            } 
        }

        if (flag) {
            puts("Yes");
        } else {
            puts("No");
        }
        free(str);
        free(bstr);
    }
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int iter;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++) {
        int n, q;
        scanf("%d %d", &n, &q);
        char *string = malloc((n + 1) * sizeof(char));
        scanf("%s", string);
        for (int j = 0; j < q; j++) {
            int flag = 0;
            int l, r;
            scanf("%d %d", &l, &r);
            for (int k = l - 2; k >= 0; k--) {
                if (string[k] == string[l-1]) flag = 1;
            }
            if (!flag) {
                for (int k = r; k < n; k++) {
                    if (string[k] == string[r-1]) flag = 1; 
                }
            }
            if (flag) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
        free(string);
    }
}

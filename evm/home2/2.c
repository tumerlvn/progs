#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s1 = malloc(101 * sizeof(char));
    char *s2 = malloc(101 * sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);
    int size1 = 0;
    int size2 = 0;
    while (s1[size1]) {
        size1++;
    }
    while (s2[size2]) {
        size2++;
    }
    int mat[102][102] = {0};
    int max = 0;
    for (int i = 1; i < size1 + 1; i++) {
        for (int j = 1; j < size2 + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            if (max < mat[i][j]) {
                max = mat[i][j];
            }
        }
    }
    printf("%d\n", max);

    free(s1);
    free(s2);
    return 0;
}

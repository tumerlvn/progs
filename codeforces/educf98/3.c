#include <stdio.h>
#include <stdlib.h>

int main() {
    int iter;
    scanf("%d\n", &iter);
    int* result = malloc(iter * sizeof(int));
    for (int i = 0; i < iter; i++) {
        int cnt = 0;
        char string[200000];
        int j = 0;
        while ((string[j] = getchar()) != '\n' && string[i] != EOF) {
            j++;
        }
        for (int k = 0; k < j; k++) {
            if (string[k] == '(') {
                for (int l = k + 1; l < j; l++) {
                    if (string[l] == ')') {
                        string[l] = '\0';
                        cnt++;
                        break;
                    }
                }
            } else if (string[k] == '[') {
                for (int l = k + 1; l < j; l++) {
                    if (string[l] == ']') {
                        string[l] = '\0';
                        cnt++;
                        break;
                    }
                }
            } 
        }
        result[i] = cnt;
    }
    for (int i = 0; i < iter; i++) {
        printf("%d\n", result[i]);
    }
    free(result);
}

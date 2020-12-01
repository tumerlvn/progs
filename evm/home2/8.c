#include <stdio.h>
#include <stdlib.h>

int main() {
    int matSize = 1;
    char **mat = malloc(matSize * sizeof(char*));
    char *buffer = malloc(4 * sizeof(char));
    buffer[3] = '\0';
    char c;
    int size = 0;
    int j = 0;
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            if (size == 3) {
                if (matSize < j + 1) {
                    matSize++;
                    mat = realloc(mat, matSize * sizeof(char*));
                }
                mat[j] = buffer;
                buffer = malloc(4 * sizeof(char));
                j++;
            }
            size = 0;
            buffer[3] = '\0';
        } else if (c >= 'a' && c <= 'z' && size < 4) {
            buffer[size] = c;
            size++;
        }
    }
    if (size == 3) {
            if (matSize < j + 1) {
                matSize++;
                mat = realloc(mat, matSize * sizeof(char*));
            }
            mat[j] = buffer;
            buffer = malloc(4 * sizeof(char));
            j++;
    }
    for (int i = 0; i < matSize; i++) {
        printf("%s ", mat[i]);
    }
    for (int i = 0; i < matSize; i++) {
        free(mat[i]);
    }
    free(mat);
    puts("");
    return 0;
}

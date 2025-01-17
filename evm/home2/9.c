#include <stdio.h>
#include <stdlib.h>

int main() {
    int matSize = 1;
    int bufferSize = 1;
    char **mat = malloc(matSize * sizeof(char*));
    char *buffer = malloc(bufferSize * sizeof(char));
    char c;
    int size = 0;
    int j = 0;
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            if (matSize < j + 1) {
                matSize *= 2;
                mat = realloc(mat, matSize * sizeof(char*));
            }
            for (int i = 0; i < size/2; i++) {
                char tmp = buffer[i];
                buffer[i] = buffer[size - i - 1];
                buffer[size - i - 1] = tmp;
            }
            buffer[size] = '\0';
            mat[j] = buffer;
            buffer = malloc(bufferSize * sizeof(char));
            j++;
            size = 0;
        } else if (c >= 'a' && c <= 'z') {
            if (bufferSize <= size + 1) {
                bufferSize *= 2;
                buffer = realloc(buffer, bufferSize * sizeof(char));
            }
            buffer[size] = c;
            size++;
        }
    }
    if (matSize < j + 1) {
        matSize *= 2;
        mat = realloc(mat, matSize * sizeof(char*));
    }
    for (int i = 0; i < size/2; i++) {
        char tmp = buffer[i];
        buffer[i] = buffer[size - i - 1];
        buffer[size - i - 1] = tmp;
    }
    buffer[size] = '\0';
    mat[j] = buffer;
    j++;
    for (int i = 0; i < j; i++) {
        printf("%s ", mat[i]);
    }
    puts("");
    for (int i = 0; i < j; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}

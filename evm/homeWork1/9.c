#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);
    int a[10][10];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        int maxj = 0;
        int maxflag = 0;
        int minflag = 0;
        for (int j = 1; j < size; j++) {
            if (a[i][maxj] < a[i][j]) {
                maxj = j;
                maxflag = 0;
            } else if (a[i][maxj] == a[i][j]) {
                maxflag = 1;
            }
        }
        int mini = 0;
        for (int j = 1; j < size; j++) {
            if (a[mini][maxj] > a[j][maxj]) {
                mini = j;
                minflag = 0;
            } else if (a[mini][maxj] == a[j][maxj]) {
                minflag = 1;
            }
        }
        if (!minflag && !maxflag && mini == i) {
            printf("%d %d : %d\n", i + 1, maxj + 1, a[i][maxj]);
        }
    }
    return 0;
}

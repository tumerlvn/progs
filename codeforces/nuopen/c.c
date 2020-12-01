#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
     return *(int*)a - *(int*)b;
 }

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    int max = -1000000000;
    int cnti = 0, cntf = 0;
    int maxdif = 0;
    int resi = 0, resf = 0;
    int flag = 0;
    int iflag = 1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) {
            max = arr[i];
            cnti = i;
            cntf = i;
            maxdif = 0;
        } else if ((max == arr[i]) && (((i - cntf) <= 2) || flag)) {
            if (flag && iflag) {
                cnti = i;
                flag = 0;
            }
            cntf = i;
        }
        if (((i - cntf > 2) || (i == n - 1)) && ((cntf - cnti) > maxdif)) {
            maxdif = cntf - cnti;
            resi = cnti;
            resf = cntf;
            if (max == arr[i]) {
                cnti = i;
                iflag = 0;
            } else {
                iflag = 1;
            }
            flag = 1;

        }
    }
    //7 1 7 1 7
    printf("%d %d\n", resi + 1, resf + 1);

    return 0;
}

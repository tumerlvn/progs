#include <stdio.h>
#include <stdlib.h>

int cmpr_str(char* s1, char* s2) {
    for (int i = 0; i < 100; i++) {
        char tmp1, tmp2;
        if(s1[i] == 0 &&  s2[i] == 0) {
            return 0;
        } else if(s1[i] == 0) {
            return 1;
        } else if(s2[i] == 0) {
            return -1;
        }

        if(s1[i] >= 'a') {
            tmp1 = s1[i] - 'a';
        } else {
            tmp1 = s1[i] - 'A';
        }

        if(s2[i] >= 'a') {
            tmp2 = s2[i] - 'a';
        } else {
            tmp2 = s2[i] - 'A';
        }
 
        if(tmp1 < tmp2) {
            return 1;    
        } else if(tmp1 > tmp2) {
            return -1;
        }
    }

    return 0;
}

int main() {
    char* s1 = malloc(101 * sizeof(char));
    char* s2 = malloc(101 * sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);

    printf("%d\n", cmpr_str(s1, s2));
    free(s1);
    free(s2);
    return 0;
}

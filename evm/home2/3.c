#include <stdio.h>
#include <stdlib.h>

int formula() {
    char c;
    int result;
    while ((c = getchar()) != '\n') {
        if (c == '(') {
            result = formula();
        } else if (c >= '0' && c <= '9') {
            result = c - '0';
        } else if (c == '*') {
            c = getchar();
            result *= c - '0';
        } else if (c == '+') {
            c = getchar();
            result += c - '0';
        } else if (c == '-') {
            c = getchar();
            result -= c - '0';
        } else if (c == ')') {
            return result;
        }
    }
    return result;
}

int main() {
    char c = 'r';
    printf("%d\n", formula());



    return 0;
}

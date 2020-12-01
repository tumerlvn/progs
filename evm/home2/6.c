#include <stdio.h>
#include <stdlib.h>

struct Rational {
    int up;
    int down;
};

typedef struct Rational rat;

int nod(int a, int b) {
    while (a && b) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

rat sum(rat a, rat b) {
    rat tmpRat;
    tmpRat.up = a.up * (b.down / nod(a.down, b.down)) + b.up * (a.down / nod(a.down, b.down));
    tmpRat.down = a.down * b.down / nod(a.down, b.down);
    int n = nod(tmpRat.up, tmpRat.down);
    tmpRat.up /= n;
    tmpRat.down /= n;
    return tmpRat;
}

rat mul(rat a, rat b) {
    rat tmpRat;
    tmpRat.up = a.up * b.up;
    tmpRat.down = a.down * b.down;
    int n = nod(tmpRat.up, tmpRat.down);
    tmpRat.up /= n;
    tmpRat.down /= n;
    return tmpRat;
}

void initialize(rat *a) {
    int i = 0;
    char c = getchar();
    int tmp = 0;
    while (c != '\n' && c != ' ') {
        if (c >= '0' && c <= '9') {
            tmp *= 10;
            tmp += c - '0';
        } else if (c == '/') {
            a->up = tmp;
            tmp = 0;
        }
        c = getchar();
    }
    a->down = tmp;
}

int main() {
    rat a = {0, 0};
    rat b = {0, 0};
    initialize(&a);
    initialize(&b);
    printf("%d/%d %d/%d\n", sum(a, b).up, sum(a, b).down, mul(a, b).up, mul(a, b).down);
    return 0;
}

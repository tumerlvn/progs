#include <stdio.h>
struct Vector {
    int x;
    int y;
};

typedef struct Vector Vec;

void scanVec(Vec *a) {
    scanf("%d %d", &(a->x), &(a->y));
}

int productVec(Vec a, Vec b, Vec c) {
    return (a.x - c.x) * (b.y - a.y) - (a.y - c.y) * (b.x - a.x);
}

void checkPos(int a, int b, int c) {
    int s1, s2, s3;
    s1 = a * b;
    s2 = a * c;
    s3 = b * c;
    if ((s1 > 0 && s2 > 0 && s3 > 0) || (s1 < 0 && s2 < 0 && s3 < 0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    Vec a, b, c, d;
    scanVec(&a);
    scanVec(&b);
    scanVec(&c);
    scanVec(&d);
    checkPos(productVec(a, b, d), productVec(b, c, d), productVec(c, a, d));
    return 0;
}

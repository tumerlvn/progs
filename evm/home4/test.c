#include <stdio.h>

int main() {
    int x = 15;
    int y = (x*((3+2*x)+2))+((7-12)+(2*x+2*(4 - 1)));
    int z = 3*x - 2 + (x+2*(y+1))/(y*y-(y+x*x));
    printf("%d", y);
    return 0;
}

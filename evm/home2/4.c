#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    puts("");
}

void makesum(int sum, int number, int *answer, int iterator) {
    /*if (number == 1) {
        printf("%d\n", sum);
        return;
    }*/
    int max = sum - number + 1;
    for (int i = 1; i <= max; i++) {
        if (number == 1) {
            answer[iterator - 1] = max;
            printArray(answer, iterator);
            return;
        }
        answer[iterator - number] = i;
        makesum(sum - answer[iterator - number], number - 1, answer, iterator);
    }
}

int main() {
    int sum;
    int number;
    int answer[100];
    scanf("%d %d", &sum, &number);
    makesum(sum, number, answer, number);
    return 0;
}

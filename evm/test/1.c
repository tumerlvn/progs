#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

struct node *pushfront(struct node *list, int value) {
    struct node *tmp = malloc(sizeof(struct node));
    tmp->value = value;
    tmp->next = list;
    return tmp;
}

void printlist(struct node *list) {
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    puts("");
}

int main() {
    struct node *list;
    for (int i = 0; i < 1000000000; i++) {
        list = pushfront(list, i);
        list = pushfront(list, i);
        list = pushfront(list, i);
    }
    //printlist(list);
    return 0;
}

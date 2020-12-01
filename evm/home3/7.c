#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

struct node *pushFront(struct node *list, int value) {
    struct node *tmp = malloc(sizeof(struct node));
    tmp->value = value;
    tmp->next = list;
    return tmp;
}

void pushBack(struct node *list, int value) {
    while (list->next) {
        list = list->next;
    }
    struct node *tmp = malloc(sizeof(struct node));
    tmp->value = value;
    tmp->next = NULL;
    list->next = tmp;
}

struct node *pushSort(struct node *list, int value) {
    struct node *tmp = malloc(sizeof(struct node));
    struct node *prev;
    struct node *start = list;
    tmp->value = value;
    tmp->next = NULL;
    if (list->value > value) {
        tmp->next = list;
        return tmp;
    }
    prev = list;
    list = list->next;
    while (list) {
        if (value < list->value) {
            tmp->next = list;
            prev->next = tmp;
            return start;
        }
        prev = list;
        list = list->next;
    }
    prev->next = tmp;
    return start;
}

void printList(struct node *list) {
    printf("[");
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    puts("]");
}

void deleteList(struct node *list) {
    while (list) {
        struct node *prev = list;
        list = list->next;
        free(prev);
    }
}

struct node *initList() {
    struct node *list = malloc(sizeof(struct node));
    int n;
    scanf("%d", &n);
    if (n) {
        list->value = n;
        list->next = NULL;
        printList(list);
        scanf("%d", &n);
        while (n) {
            list = pushSort(list, n);
            printList(list);
            scanf("%d", &n);
        }
    }
    return list;
}

int main() {
    struct node *list;
    list = initList();
    deleteList(list);
    return 0;
}

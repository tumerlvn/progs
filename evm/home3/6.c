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

struct node *listsAssemble(struct node *list1, struct node *list2) {
    struct node *start = list1;
    struct node *prev;
    if (list2->value < list1->value) {
        start = list2;
        list2 = list2->next;
        start->next = list1;
        prev = start;
    } else {
        prev = list1;
        list1 = list1->next;
    }
    while (list2 && list1) {
        if (list2->value < list1->value) {
            prev->next = list2;
            list2 = list2->next;
            (prev->next)->next = list1;
            prev = prev->next;
        } else {
            prev = list1;
            list1 = list1->next;
        }
    }
    if (list2) {
        prev->next = list2;
    }
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
        scanf("%d", &n);
        while (n) {
            list = pushSort(list, n);
            scanf("%d", &n);
        }
    }
    return list;
}

int main() {
    struct node *list1 = initList();
    struct node *list2 = initList();
    printList(list1);
    printList(list2);
    list1 = listsAssemble(list1, list2);
    printList(list1);
    deleteList(list1);
    return 0;
}

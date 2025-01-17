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

int main() {
    struct node *list = malloc(sizeof(struct node));
    int n;
    scanf("%d", &n);
    if (n) {
        list->value = n;
        list->next = NULL;
        printList(list);
        scanf("%d", &n); 
        while(n) {
            pushBack(list, n); 
            printList(list);
            scanf("%d", &n);
        }
    }
    deleteList(list);
    return 0;
}

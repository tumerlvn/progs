#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *pnode;

void printTree(pnode tree);

pnode addNode(pnode tree, int value) {
    pnode init = tree;
    pnode prev = NULL;
    pnode p = malloc(sizeof(struct Node));
    p->value = value;
    p->left = p->right = NULL;
    while (tree) {
        prev = tree;
        if (value < tree->value) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    if (value < prev->value) {
        prev->left = p;
    } else {
        prev->right = p;
    }
    return init;
}

pnode getTree() {
    pnode tree = NULL;
    int tmp;
    scanf("%d", &tmp);
    if (tmp) {
        tree = malloc(sizeof(struct Node));
        tree->value = tmp;
        tree->left = tree->right = NULL;
        printf("[");
        printTree(tree);
        printf("]\n");
    } else {
        return tree;
    }

    scanf("%d", &tmp);
    while (tmp) {
        tree = addNode(tree, tmp);
        printf("[");
        printTree(tree);
        printf("]\n");
        scanf("%d", &tmp);
    }
    return tree;
}

void printTree(pnode tree) {
    if (tree) {
        printTree(tree->left);
        printf("%d ", tree->value);
        printTree(tree->right);
    }
}

void deleteTree(pnode tree) {
    if (tree) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}

int main() {
    pnode tree = getTree();
    deleteTree(tree);
    return 0;
}

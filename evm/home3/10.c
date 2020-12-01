#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *pnode;

void printTree(pnode tree, int level);

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
    } else {
        return tree;
    }

    scanf("%d", &tmp);
    while (tmp) {
        tree = addNode(tree, tmp);
        scanf("%d", &tmp);
    }
    return tree;
}

void printTree(pnode tree, int level) {
    if (tree) {
        for (int i = 0; i < level; i++) {
            printf(".");
        }
        printf("%d\n", tree->value);
        printTree(tree->left, level + 1);
        printTree(tree->right, level + 1);
    }
}

pnode deleteLeaves(pnode tree) {
    if (!tree) {
        return NULL;
    }
    if (!tree->left && !tree->right) {
        free(tree);
        return NULL;
    } else {
        tree->left = deleteLeaves(tree->left);
        tree->right = deleteLeaves(tree->right);
    }
    return tree;
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
    int level = 0;
    tree = deleteLeaves(tree);
    printTree(tree, level);
    deleteTree(tree);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) {
        fprintf(stderr, "Khong du bo nho\n");
        exit(EXIT_FAILURE);
    }
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int treeHeight(Node *root) {
    if (root == NULL) return 0;
    int l = treeHeight(root->left);
    int r = treeHeight(root->right);
    return (l > r ? l : r) + 1;
}

int main(void) {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->right = createNode(6);
    root->right->left = createNode(7);

    printf("Chieu cao: %d\n", treeHeight(root));
    return 0;
}
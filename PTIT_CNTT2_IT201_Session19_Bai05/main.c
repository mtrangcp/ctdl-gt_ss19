#include <stdio.h>
#include <stdlib.h>

typedef  struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if ( newNode == NULL ) {
        printf("Cap phat khong thanh cong");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int inorder(Node* root, int n) {
    if ( root == NULL ) {
        return 0;
    }
    if ( root->data == n) {
        return 1;
    }
    inorder(root->left, n);
    inorder(root->right, n);

    return -1;
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int n;
    printf("Nhap so can tim: ");
    scanf("%d", &n);

    inorder(root->left, n) == 1 ? printf("TRUE") : printf("FALSE");

    return 0;
}
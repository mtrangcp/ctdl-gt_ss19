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

// preorder ( n l r)
void preorder(Node* root) {
    if ( root == NULL ) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Inorder Traversal:\n");
    preorder(root);
    return 0;
}
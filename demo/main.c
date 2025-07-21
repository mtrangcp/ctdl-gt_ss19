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

// inorder ( l n r)
void inorder(Node* root) {
    if ( root == NULL ) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

// postorder ( l r n )
void postorder(Node* root) {
    if ( root == NULL ) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(void) {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");
    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\n");
    printf("Postorder Traversal:\n");
    postorder(root);

    return 0;
}
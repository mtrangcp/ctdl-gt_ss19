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
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Inorder Traversal:\n");
    postorder(root);
    return 0;
}
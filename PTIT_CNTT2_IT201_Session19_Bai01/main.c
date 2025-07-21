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

int main(void) {
    int n;
    printf("nhap so bat ki: ");
    scanf("%d", &n);

    Node* head = createNode(n);

    Node* head2 = createNode(2);
    head2->left = createNode(3);
    head2->right = createNode(4);
    head2->left->left = createNode(5);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if ( newNode == NULL ) {
        printf("Cap phat khong thanh cong!");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct {
    Node* items[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

void enQueue(Queue* queue, Node* item) {
    if (isFull(queue)) {
        printf("Queue is full!");
        return;
    }
    queue->items[++queue->rear] = item;
}

Node* deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!");
        return;
    }
    return queue->items[queue->front++];
}

int bfs(Node* root, int n) {
    if ( root == NULL ) {
        return;
    }
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while ( !isEmpty(&q) ) {
        Node* current = deQueue(&q);
        if ( current->data == n) return 1;
        if ( current->left != NULL ) enQueue( &q, current->left );
        if ( current->right != NULL ) enQueue( &q, current->right );
    }
    return 0;
}

int main(void) {
    Node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);

    int n;
    printf("Nhap so can tim: ");
    scanf("%d", &n);
    bfs( root, n ) == 1 ? printf("TRUE") : printf("FALSE");
    return 0;
}
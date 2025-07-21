#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        fprintf(stderr, "Cap phat bo nho that bai!\n");
        exit(EXIT_FAILURE);
    }
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

typedef struct QNode {
    Node *data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear  = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enQueue(Queue *q, Node *item) {
    QNode *tmp = (QNode*)malloc(sizeof(QNode));
    if (tmp == NULL) {
        fprintf(stderr, "Cap phat QNode that bai!\n");
        exit(EXIT_FAILURE);
    }
    tmp->data = item;
    tmp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = tmp;
    } else {
        q->rear->next = tmp;
        q->rear = tmp;
    }
}

Node *deQueue(Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }
    QNode *tmp = q->front;
    Node *item = tmp->data;
    q->front = tmp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(tmp);
    return item;
}

void insertNode(Node *root, int value) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    while (!isEmpty(&q)) {
        Node *cur = deQueue(&q);
        if (cur->left == NULL) {
            cur->left = createNode(value);
            return;
        } else {
            enQueue(&q, cur->left);
        }
        if (cur->right == NULL) {
            cur->right = createNode(value);
            return;
        } else {
            enQueue(&q, cur->right);
        }
    }
}

void levelOrder(Node *root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    while (!isEmpty(&q)) {
        Node *cur = deQueue(&q);
        printf("%d ", cur->data);
        if (cur->left) enQueue(&q, cur->left);
        if (cur->right) enQueue(&q, cur->right);
    }
}

int main(void) {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    levelOrder(root);
    printf("\n");

    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 8);

    printf("Sau: \n");
    levelOrder(root);
    return 0;
}
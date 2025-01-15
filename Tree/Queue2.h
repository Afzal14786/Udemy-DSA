#ifndef Queue2_h
#define Queue2_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left_child;
    struct Node *right_child;
    int data;
} Node;

typedef struct Queue {
    int size;
    int front;
    int rear;
    Node **que;
} Queue;

void create_Queue(Queue *q, int size) {
    q->size = size + 1; // Add one extra space for circular queue
    q->front = 0;
    q->rear = 0;
    q->que = (Node **)malloc(sizeof(Node *) * q->size);
}

void circular_enque(Queue *q, Node *data) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("The Queue Is Full . . .\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->que[q->rear] = data;
    }
}

Node* circular_deque(Queue *q) {
    Node *ans = NULL;
    if (q->front == q->rear) {
        printf("Queue Is Empty.\n");
    } else {
        q->front = (q->front + 1) % q->size;
        ans = q->que[q->front];
    }
    return ans;
}

int isEmpty(Queue q) {
    return q.front == q.rear;
}

#endif

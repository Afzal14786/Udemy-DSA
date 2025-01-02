#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *que;
};



void create_Queue(struct Queue *q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->que = (int *)malloc(sizeof(int) * size);
}

void enqueuing(struct Queue *q, int data) {
    // checking full condition //
    if (q->rear == q->size-1) {
        printf("The Queue Is Full, Unable To Perform Insertion Operation.\n");
    } else {
        q->rear++;
        q->que[q->rear] = data;
    }
}

int dequeuig(struct Queue *q) {
    int ans = -1;
    if (q->front == q->rear) {
        printf("The Queue Is Empty, Unable To Perform Delete Operation.\n");
        return -1;
    } else {
        q->front++;
        ans = q->que[q->front];
    }

    return ans;
}

void circular_enque(struct Queue *q, int data) {
    /* checking the full condition */
    if ((q->rear + 1) % q->size == q->front) {
        printf("The Queue Is Full . . .\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->que[q->rear] =  data;
    }
}

int circular_deque(struct Queue *q) {
    int ans = -1;
    if (q->front == q->rear) {
        printf("Queue Is Empty.\n");
    } else {
        q->front = (q->front + 1) % q->size;
        ans = q->que[q->front];
    }

    return ans;
}

void circular_display(struct Queue q) {
    int i = (q.front+1)% q.size;

    do {
        printf("%d ", q.que[i]);
        i = (i+1)%q.size;
    } while (i != (q.rear+1)% q.size);
    printf("\n");
}

void display(struct Queue q) { 
    for (int i = q.front + 1; i <= q.rear; ++i) {
        printf("%d ", q.que[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q1;
    create_Queue(&q1, 7);

    printf("Here Is Inserting The Elements.\n");
    circular_enque(&q1, 10);
    circular_enque(&q1, 20);
    circular_enque(&q1, 30);
    circular_enque(&q1, 40);
    circular_enque(&q1, 50);
    circular_enque(&q1, 60);
    circular_display(q1);

    printf("Deleting The Elements.\n");
    printf("%d\n", circular_deque(&q1));
    printf("%d\n", circular_deque(&q1));
    printf("%d\n", circular_deque(&q1));
    printf("After Deleting The Element's The Que Look's Like : ");
    circular_display(q1);

    printf("\nInserting Emelent At Free Spaces.\n");
    circular_enque(&q1, 1000);
    circular_enque(&q1, 92);
    
    circular_display(q1);

    printf("The Capacity Of The Queue Is : %d .\n", q1.size);
    
    return 0;
};
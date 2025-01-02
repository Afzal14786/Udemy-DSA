#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enQueue(int data) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    /*checking full condition */
    if (temp == NULL) {
        printf("The Queue Is Full.\n");
    } else {
        temp->data = data;
        temp->next = NULL;
        /* if the first node is null */
        if (front == NULL) {
            front = rear = temp;
        } else {
            /* otherwise */
            rear->next = temp;
            rear = temp;
        }
    }
}

int deQueue() {
    struct Node *temp;
    int ans = -1;

    /* checking empty condition's */
    if (front == NULL) {
        printf("The Queue Is Empty ... \n");
    } else {
        temp = front;
        ans = front->data;
        front = front->next;
        free(temp);
    }

    return ans;
}

void display () {
    struct Node *temp = front;

    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    
    enQueue(10);
    enQueue(80);
    enQueue(20);
    enQueue(30);

    display();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n) {
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; ++i) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d", p->data);
        if(p->next != NULL) {
            printf("-> ");
        }
        p = p->next;
    }
    printf("\n");
}

int ADD(struct Node *p) {
    int sum = 0;
    while (p != NULL) {
        sum = sum + p->data;
        p = p->next;
    }

    return sum;
}

int main() {
    int array[] = {3,2,4,5,7,8};
    Create(array, 6);
    Display(first);

    printf("The Sum Of All Lists Is %d.\n", ADD(first));
    return 0;
}
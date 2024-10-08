#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INT32_MIN -32767

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
        last->next  = temp;
        last = temp;
    }
}

void Display (struct Node *p) {
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL)  {
            printf("-> ");
        }
        p = p->next;
    }

    printf("\n");
}

int MAX(struct Node *p) {
    int max = INT32_MIN;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }

    return max;
}

// using recursive approach //
int MAX_Recursive(struct Node *p) {
    int max = INT32_MIN;
    if (p == NULL) {
        return INT32_MIN;
    } else {
        max = MAX_Recursive(p->next);
        return max > p->data ? max : p->data;
    }
}

int main() {
    int arr[] = {4,5,7,2,3,10,23,53,7,87};
    Create(arr,10);
    Display(first);

    printf("The Maximum Element In The List Is : %d.\n", MAX_Recursive(first));
    return 0;
}
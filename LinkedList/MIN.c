#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #define MAX_INT 3212343

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

int MIN(struct Node *p) {
    int min = __INT32_MAX__;
    while (p != NULL) {
        if (p->data < min) {
            min = p->data;
        }

        p = p->next;
    }

    return min;
}

int main() {
    int arr[] = {4,5,7,2,3,10,23,53,7,87,1};
    Create(arr,11);

    printf("The Minimum Element In The List Is : %d.\n", MIN(first));
    return 0;
}
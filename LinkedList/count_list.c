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

int Length(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

int LengthReverse(struct Node *p) {
    /* Space Complexity : O(n)*/ /* Costly In Terms Of Space*/
    /* Time Complexity : O(0)*/
    // if (p != NULL) {
    //     return 1 + LengthReverse(p->next);
    // }

    // return -1;

    int count = 0;
    if (p) {
        count = LengthReverse(p->next);
        return count + 1;
    }

    return -1;
}

int main() {
    int arr[] = {32,54,34,90,87,65,34};
    Create(arr,7);
    Display(first);

    int length = LengthReverse(first);
    printf("The Length Of The Linked List Is : %d.\n", length);

    return 0;
}
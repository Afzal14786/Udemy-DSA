#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void Create_List(int A[], int n) {
    struct Node *temp, *tail;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    tail = first;

    for (int i = 0; i < n; ++i) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

int IS_SORTED(struct Node *p) {
    struct Node *curr;
    int x = INT_MIN;
    curr = first;
    while (curr != NULL) {
        if (curr->data < x) {
            return 0;
        }
        x = curr->data;
        curr = curr->next;
    }
    return 1;
}

void Display_List(struct Node *p) {
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf("-> ");
        }
        p = p->next;
    }

    printf("\n");
}

int main() {
    int A[] = {2,5,8,9,1,12,14,45};
    Create_List(A,8);
    Display_List(first);
    if (IS_SORTED(first) == 1) {
        printf("Congratulation The Given List Is Sorted.\n");
    } else {
        printf("So Sad, The Given List Is Not Sorted.\n");
    }
    return 0;
}
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

// reverse method 1 //

void reverse_1() {
    struct Node *curr_node, *pre_node, *next_node;
    curr_node = next_node = first;
    pre_node = NULL;

    while( next_node != NULL) {
        next_node = next_node->next;
        curr_node->next = pre_node;
        pre_node = curr_node;
        curr_node = next_node;
    }

    first = pre_node;
}

void reverse_2(struct Node *q, struct Node *p) {
    if (p != NULL) {
        reverse_2(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}

void Display (struct Node *p) {
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
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

void reverse_3(struct Node *p) {
    struct Node *curr = p;

    int *A;
    int i = 0;
    A = (int *)malloc(sizeof(int)*Length(p));

    while (curr != NULL) {
        A[i] = curr->data;
        curr = curr->next;
        i++;
    }
    curr = p;
    i++;
    while (curr != NULL) {
        curr->data = A[i];
        curr = curr->next;
        i--;
    }
}


int main() {

    int arr[] = {4,5,7,2,3,10,23,53,7,87,1};
    Create(arr,11);
    printf("Before Calling The Reverse Function The Linked List Look Like :~ \n");
    Display(first);
    reverse_1(first);
    // reverse_2(NULL, first);
    // reverse_3(first);
    printf("After Calling The Reverse Function The Linked List Look Like :~ \n");
    Display(first);

    return 0;
}
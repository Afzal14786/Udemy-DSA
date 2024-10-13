#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// void Create(int A[], int n) {
//     struct Node *temp, *last;
//     first = (struct Node *)malloc(sizeof(struct Node));
//     first->data = A[0];
//     first->next = NULL;
//     last = first;

//     for (int i = 1; i < n; ++i) {
//         temp = (struct Node *)malloc(sizeof(struct Node));
//         temp->data = A[i];
//         temp->next = NULL;
//         last->next = temp;
//         last = temp;
//     }
// }

/*
    Make it perfect it is not yet perfect //
*/
// always insert at the end //

void Insert_Always_Sorted (struct Node *p, int value) {
    struct Node *temp, *current = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (first == NULL) {
        first = temp;
    } else {
        while (p && p->data < value) {
            current = p;
            p = p->next;
        }

        if (p == first) {
            temp->next = first;
            first = temp;
        } else {
            temp->next = current->next;
            current->next = temp;
        }
    }
}

/* using single pointer */

void Insert(struct Node *p, int value) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (first == NULL ||  first->data >= value) {
        temp->next = first;
        first = temp;
    } else {
        while (p->next != NULL &&  p->next->data < value) {
            p = p->next;
        }
        temp->next =  p->next;
        p->next = temp;
    }
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(" -> ");
        }
        p = p->next;
    }

    printf("\n");
}

int main() {

    // int A[] = {3,5,4,2,4,1};
    // Create(A,6);
    Insert(first, 1);
    Insert(first, 5);
    Insert(first, 80);
    Insert(first, 60);
    Insert(first, 10);

    printf("Using Two Pointers We Successfully Created The  Linked List\n");
    Display(first);
    Insert(first, 30);
    Display(first);

    return 0;
}
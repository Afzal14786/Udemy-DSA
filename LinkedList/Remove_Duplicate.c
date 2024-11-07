#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 1; i < n; ++i) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void Remove_Duplicate(struct Node *p) {
    struct Node *current_node, *next_node;
    current_node = first;
    next_node = first->next;

    

    while (next_node != NULL) {
        if (current_node->data == next_node->data) {
            current_node->next = next_node->next;
            free(next_node);
            next_node = current_node->next;
        }
        current_node = next_node;
        next_node = next_node->next;
    }
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
    int A[] = {1,2,3,4,4,5,6,6,7};
    Create_List(A,9);
    printf("Before Removing The Duplicate Element From The List. The List Look's Like :\n");
    Display_List(first);
    Remove_Duplicate(first);

    printf("After Removing The Duplicate Element From The List. The List Look's Like :\n");
    Display_List(first);
    return 0;
}
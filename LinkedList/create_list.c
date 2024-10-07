#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;

} *first = NULL;

void Create(int A[], int n) {
    // create a temp pointer and last pointer //
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
        if (p->next != NULL) {
            printf(" -> ");
        }
        p = p->next;
    }
}

// it will reverse the list //
void Display2(struct Node *p) {
    if(p != NULL) {
        Display2(p->next);
        if(p->next != NULL) {
            printf(" -> ");
        }
        printf("%d", p->data);
    }
}

int main() {
    int arr[] = {10,54,32,53,43,42,54,90};
    Create(arr, 8);
    printf("Display The List In It's Own Order.\n");
    Display(first);
    printf("\n");

    printf("Display The List In Reverse Order. \n");
    // using Recursive //
    Display2(first);
    printf("\n");

    return 0;
}
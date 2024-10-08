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

struct Node * Search(struct Node *p, int key) {
    while (p != NULL) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

struct Node * Recursive_Linear_Search(struct Node *p, int key) {
    if (p == NULL) {
        return NULL;
    } else {
        if (p->data == key) {
            return p;
        }

        return Recursive_Linear_Search(p->next, key);
    }
} 

/*
    Improving the search using two methods.
        * Transposition (Move The Found Key To One Step Backward)
        * Move To Head (Move The Found Key At The Very First Place Of The Linked List)
*/

struct Node * Improve_Search(struct Node *p, int key) {
    struct Node *tail;
    while (p != NULL) {
        if (p->data == key) {
            tail->next = p->next;
            p->next = first;
            first = p;

            return p;
        }

        tail = p;
        p = p->next;
    }

    return NULL;
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

int main() {

    struct Node *ans;

    int arr[] = {4,5,7,2,3,10,23,53,7,87,1};
    Create(arr,11);
    printf("Before Calling The Improved Linear Search The Linked List Look Like :~ \n");
    Display(first);

    ans = Improve_Search(first, 3);

    if (ans != NULL) {
        // here is the fuction calling for linear search //
        printf("The Element is found : %d.\n", ans->data);
    } else {
        printf("The Key Is Not Found.\n");
    }

    printf("After Calling The Improved Linear Search The Linked List Look Like :~ \n");
    Display(first);
    return 0;
}
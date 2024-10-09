#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void INSERT(int position, int value) {
    /* Steps */

    /* 1. Create 2 Nodes : temp, and p*/
    struct Node *temp, *p;

    /* Check Where To Insert . If (position == 0) means it insert before the first node.*/
    if (position == 0) {

        /* Create temp in heap */
        temp = (struct Node *)malloc(sizeof(struct Node));
        /* Store the value in temp node's data*/
        temp->data = value;
        /* Assign temp node's next location to first where currently first points*/
        temp->next = first;

        /* Make first is the head pointer which points in the newly added (temp node)*/
        first = temp;

        /* Here check if position is > 0 means it is assign at any given position with time complexity of O(n) times*/
    } else if (position > 0) {

        /* Maintain a p pointer node . Initialy it points to the first node*/
        p = first;

        /* Move p pointer to (positions - 1) times and also check it points to a valid node or not means p != NULL*/
        for (int i = 0; i < position - 1 && p; ++i) {
            p = p->next;
        }

        /* Checking the condition after moving the p by position - 1, p points to a valid location or not*/
        if (p != NULL) {

            /* if yes, then create a temp node.*/
            temp = (struct Node *)malloc(sizeof(struct Node));

            /* store the data in temp node*/
            temp->data = value;

            /* assign newly node's next location to p's next location where currently p points*/
            temp->next = p->next;

            /* now assign p's next to temp (newly added node's address store in p's next)*/
            p->next = temp;
        }
    }
}

int Length(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

void INSERT_2(int index, int value){
    struct Node *temp, *p;
    
    if (index < 0 || index > Length(first)) {
        printf("Please Enter A Valid Index . (Index Should Be >= 0 and <= %d).\n", Length(first));
        return;
    }


    p = (struct Node *)malloc(sizeof(struct Node));
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;

    // checking the condition if //
    if (index == 0) {
        temp->next = first;
        first = temp;
    } // check another condtion //
    else if (index > 0) {
        p = first;
        for (int i = 0; i < index - 1; ++i) {
            p = p->next;
        }

        if (p != NULL) {
            temp->next = p->next;
            p->next = temp;
        }
    }

}

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
    int index, value;
    int arr[] = {3,5,10,76,65,98,23};
    Create(arr, 7);
    printf("Before Inserting A New Node The List Look's Like.\n");
    Display(first);

    // insert method calls here //
    printf("Enter The Index and value Which you want to store.\n");
    scanf("%d %d", &index, &value);

    if (index >= 0 && index <= Length(first)) {
        INSERT_2(index, value);
        printf("After Inserting A New Node The List Look's Like.\n");
        Display(first);
        
    } else {
        INSERT_2(index, value);
    }
}
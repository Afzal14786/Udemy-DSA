#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

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


/* Program For Creating A Node.\n*/
void INSERT(int position, int value);
int DELETE(int position);
int COUNT();
void REVERSE();
int MAXIMUM();
int MINIMUM();
void IS_SORTED();


int main() {

    int choice, value;
    // Menu-driven program using do-while and switch-case
    // do {
    //     printf("\nMenu Driven Program In Linked List.\n");
    //     printf("1. Insert A New Element In List.\n");
    //     printf("2. Delete A Node From Linked List.\n");
    //     printf("3. Count The No Of Nodes Present In The List.\n");
    //     printf("4. Find Maximum Element In The List.\n");
    //     printf("5. Find Minimum Element In The List.\n");
    //     printf("6. Check If The List Is Sorted Or Not.\n");
    //     printf("7. Exit.\n");

    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         /* Cases */
    //     }

    // } while (choice != 7);

    INSERT(0,30);
    INSERT(1,20);
    INSERT(2,90);
    REVERSE();
    Display(first);
    return 0;
}

void INSERT(int position, int value) {
    struct Node *current_node, *tail_node;
    if (position < 0 || position > COUNT()) {
        printf("Enter A Valid Position. (Position Should Be >= 0 to %d).\n", COUNT());
        return;
    }

    current_node = (struct Node *)malloc(sizeof(struct Node));
    current_node->data = value;
    current_node->next = NULL;

    if (position == 0) {
        if (first == NULL) {
            first = current_node;
        } else {
            current_node->next = first;
            first = current_node;
        }
    } else if (position > 0) {
        tail_node = first;
        for (int i = 0; i < position - 1 && tail_node; ++i) {
            tail_node = tail_node->next;
        }

        if (tail_node != NULL) {
            current_node->next = tail_node->next;
            tail_node->next = current_node;
        }
    }
}

int DELETE(int position) {
    struct Node *curr_node, *tail_node;
    curr_node = first;
    tail_node = NULL;
    
    int deleted_elem = -1;

    if (position < 0 || position > COUNT()) {
        printf("Invalid Index. (Position Should Be 0 to %d).\n", COUNT());
        return -1;
    }

    if (position == 1) {
        /* Delete The Very First Node*/
        curr_node = first;
        deleted_elem = first->data;
        first = first->next;
        free(curr_node);
        return deleted_elem;
    } else {
        curr_node = first;
        for (int i = 0; i < position - 1; ++i) {
            tail_node = curr_node;
            curr_node = curr_node->next;
        }

        if (curr_node) {
            curr_node->next = tail_node->next;
            deleted_elem = curr_node->data;
            free(curr_node);
            return deleted_elem;
        }
    }
}

int COUNT()
{
    struct Node *current_node = first;
    int count = 0;
    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }
    return count;
}

void REVERSE() {
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


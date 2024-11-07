#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n) {
    struct Node *current, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; ++i) {
        current = (struct Node *)malloc (sizeof(struct Node));
        current->data = A[i];
        current->next = NULL;
        last->next = current;
        last = current;
    }
}

int count_length(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

int delete(int position)
{
    struct Node *current, *tail;
    current = first;
    tail = NULL;
    int deleted_value = -1;
    if (position < 1 || position > count_length(first)) {
        printf("Invalid position.\nPosition Must Be 1 <= %d.\n", count_length(first));
        return -1;
    } else {
        if (position == 1) {
            /* Means Need To Delete The Vey First Node.*/
            current = first;
            deleted_value = first->data;
            first = first->next;
            free(current);
            return  deleted_value;
        } else {
            for (int i = 0; i < position - 1 && current; ++i) {
                tail =  current;
                current = current->next;
            }

            if (current) {
                deleted_value = current->data;
                tail->next = current->next;
                free(current);
                return deleted_value;
            }

            return deleted_value;
        }
    }
}

void Display(struct Node *p) {
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
    int A[] = {1,2,3,4,5};
    Create(A,5);
    printf("%d\n", count_length(first));
    Display(first);
    printf("%d\n", delete(3));
    Display(first);
    

    return 0;
}
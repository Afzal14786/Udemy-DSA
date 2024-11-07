#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

void Create(int A[], int n) {
    
    struct Node *currenrt_node, *last;
    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = A[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; ++i) {
        currenrt_node = (struct Node *)malloc(sizeof(struct Node));
        currenrt_node->data = A[i];
        currenrt_node->next = last->next;
        last->next = currenrt_node;
        last = currenrt_node;
    }
}

void Display (struct Node *p) {
    do {
        printf("%d", p->data);
        if (p->next != head) {
            printf("-> ");
        }
        p = p->next;

    } while (p != head);

    printf("\n");
}

int Count(struct Node *p) {

    int length = 0;
    do {
        length++;
        p = p->next;
    } while (p != head);

    return length;
}

int MAX (struct Node *p) {
    int min_value = -1;

    do {
        if (min_value < p->data) {
            min_value = p->data;
        }
        p = p->next;
    } while (p != head);

    return min_value;
}

int MIN (struct Node *p) {
    int max = 2147483647;

    do {
        if (p->data < max) {
            max = p->data;
        }
    } while (p != head);

    return max;
}

void Insert(int pos, int data) {
    struct Node *curr, *newNode;

    /* Checking The Valid Conditions if position is < or > length of the list*/
    if (pos < 0 || pos > Count(head)) {
        printf("Please Enter A Valid Position.\nPosition Should Pos >=0 and <= %d.\n", Count(head));
        exit(0);
    }

    if (pos == 0) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    } else {
        curr = head;
        for (int i = 0; i < pos - 1; ++i) {
            curr = curr->next;
        }

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = curr->next;
        curr->next = newNode; 
    }
}

int Delete(int pos) {
    struct Node *curr_ptr, *q;
    int deleted_elem = -1;
    /*Checking The Position's Condition*/
    /* Checking The Valid Conditions if position is < or > length of the list*/
    if (pos < 0 || pos > Count(head)) {
        return deleted_elem;
    }

    if (pos == 0) {
        /* means delete the head node*/
        curr_ptr = head;
        while (curr_ptr->next != head) {
            curr_ptr = curr_ptr->next;
        }

        deleted_elem = head->data;
        if (head == NULL) {
            free(head);
            head = NULL;
        } else {
            curr_ptr->next = head->next;
            free(head);
            head = curr_ptr->next;
        }
        return deleted_elem;

    } else {
        curr_ptr = head;
        for (int i = 0 ; i < pos - 2; ++i) {
            curr_ptr = curr_ptr->next;
        }
        q = curr_ptr->next;
        deleted_elem = q->data;
        free(q);

        return deleted_elem; 
    }

}

int main () {

    int A[] = {1,4,7,3,5};
    Create(A, 5);
    Display(head);

    printf("The Length Of The Given String is %d .\n", Count(head));
    printf("The Maximum Value In The List Is %d .\n", MAX(head));
    printf("The Minimum Value In The List Is %d .\n", MIN(head));

    int position, data;
    // printf("Enter The Index And Date Which you want to add in the list : \n");
    // scanf("%d %d", &position, &data);

    // Insert(position, data);
    // printf("After Inserting New Value In The List, The List Look's Like : ");
    // Display(head);

    printf("Enter Positon To Delete A Node From Linked List : ");
    scanf("%d", &position);
    
    if (Delete(position) == -1) {
        printf("Please Enter A Valid Position.\nPosition Should Pos >=0 and <= %d.\n", Count(head));
        exit(0);
    } else {
        printf("The Node At Position %d Deleted Successfully.\n", position);
        printf("List After Deletion : ");
        Display(head);
    }

    return 0;
}
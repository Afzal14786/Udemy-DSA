#include <stdio.h>
#include <stdlib.h>
#include "Queue2.h"

Node* root = NULL;  // global pointer //

void create() {
    Node *p, *t;
    int x;
    Queue q;
    create_Queue(&q, 100);

    printf("Enter The Value Of Root: ");
    scanf("%d", &x);

    root = malloc(sizeof(Node));
    root->data = x;
    root->left_child = root->right_child = NULL;
    circular_enque(&q, root);

    while (!isEmpty(q)) {
        p = circular_deque(&q);

        printf("Enter Left Child Value Of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = malloc(sizeof(Node));
            t->data = x;
            t->left_child = t->right_child = NULL;
            p->left_child = t;
            circular_enque(&q, t);
        }

        printf("Enter The Right Child Value Of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = malloc(sizeof(Node));
            t->data = x;
            t->left_child = t->right_child = NULL;
            p->right_child = t;
            circular_enque(&q, t);
        }
    }
}

void preOrder(Node* p) {
    if (p) {
        printf("%d ", p->data);
        preOrder(p->left_child);
        preOrder(p->right_child);
    }
}

void postOrder(Node* p) {
    if (p) {
        postOrder(p->left_child);
        postOrder(p->right_child);
        printf("%d ", p->data);
    }
}

void inOrder(Node* p) {
    if (p) {
        inOrder(p->left_child);
        printf("%d ", p->data);
        inOrder(p->right_child);
    }
}

int main() {
    create();
    printf("\nPreOrder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("\nPostOrder Traversal: ");
    postOrder(root);
    printf("\n");

    printf("\nInOrder Traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}

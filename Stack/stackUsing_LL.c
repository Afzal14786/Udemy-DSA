#include <stdio.h>
#include <stdlib.h>

struct Stack_Node {
    int data;
    struct Stack_Node *next;
} *top = NULL;


void PUSH(int x) {
    struct Stack_Node *temp = top;
    temp = (struct Stack_Node *)malloc(sizeof(struct Stack_Node));
    if (temp == NULL) {
        printf("Stack is full.\n");
        return;
    } else {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

int Stack_Size() {
    int size = 0;
    struct Stack_Node *temp = top;
    while (temp) {
        size++;
        temp = temp->next;
    }

    return size;
}

void Display(struct Stack_Node *p) {
    while (p != NULL) {
        printf("%d", p->data);
        if(p->next != NULL) {
            printf("-> ");
        }
        p = p->next;
    }
    printf("\n");
}

int POP() {
    struct Stack_Node *temp;
    int x = -1;
    if (top == NULL) {
        printf("Stack is underflow or stack is empty.\n");
        return x;
    } else {
        temp = top;
        x = top->data;
        top = top->next;
        free(temp);
        return x;
    }
}

int peek(int pos) {
    struct Stack_Node *temp;;
    int x = -1;

    if (pos < 1 || pos > Stack_Size()) {
        printf("Invalid Position. It Should Be >= 1 And <= %d.\n", Stack_Size());
        return x;
    }

    if (top == NULL) {
        printf("No Element found in stack.\n");
        return x;
    } else {
        if (pos == 1) {
            POP();  /* pop out the first node*/
        } else if (pos > 1) {
            temp = top;
            for (int i = 0; i < pos - 1; ++i) {
                temp = temp->next;
            }
            if (temp != NULL) {
                x = temp->data;
            }
            return x;
        }
    }

}

int isFull() {
    struct Stack_Node *temp = (struct Stack_Node *)malloc(sizeof(struct Stack_Node));  // Use nothrow to avoid exceptions on failure
    if (temp == NULL) {
        return 1;  // Stack is full (memory allocation failed)
    } else {
        free(temp);  // Free the allocated memory to avoid memory leak
        return 0;  // Stack is not full
    }
}


int Stack_Top() {

    if (top != NULL) {
        return top->data;
    }

    return -1;
}

int isEmpty() {
    return (top == NULL) ? 1 : 0;
}

int main() {
    struct Stack_Node node;
    PUSH(10);
    PUSH(20);
    PUSH(30);
    PUSH(40);
    PUSH(50);

    Display(top);
    printf("Size Of The Stack Is : %d.\n", Stack_Size());
    printf("The Poped Elem Is : %d.\n", POP());
    Display(top);
    printf("Peek a value from stack at given position : %d.\n", peek(4));
    return 0;
}
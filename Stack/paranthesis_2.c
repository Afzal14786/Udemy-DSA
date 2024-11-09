#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
} *top = NULL;

void push(char ch) {
    struct Node *temp = top;
    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("stack is full !\n");
        return;
    } else {
        temp->data = ch;
        temp->next = top;
        top = temp;
    }
}

char pop() {
    struct Node *temp;
    char ans = '0';
    if(top == NULL) {
        printf("stack is empty!\n");
        return ans;
    } else {
        temp = top;
        ans = top->data;
        top = top->next;
        free(temp);

        return ans;
    }
}

int isBalanced(char *exp) {
    for (int i = 0; exp[i] != '\0'; ++i) {
        if (exp[i] == '(') {
            push(exp[i]);
        }  else if (exp[i] == '{') {
            push(exp[i]);
        } else if (exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == NULL) {
                return 0;
            } else {
                pop();
            }
        } else if (exp[i] == '}') {
            if (top == NULL) {
                return 0;
            } else {
                pop();
            }
        } else if (exp[i] == ']') {
            if (top == NULL) {
                return 0;
            } else {
                pop();
            }
        }
    }

    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *exp = "{[(a+b)*(c-d)]}";
    printf("%d\n", isBalanced(exp));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Stack {
    int top;
    int size;
    int *stack;
};

void Create_Stack(struct Stack *st) {
    printf("Enter Size : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->stack = (int *)malloc(st->size*sizeof(int));
}

void Display_Stack(struct Stack st) {
    for (int i = st.top; i >=0; --i) {
        printf("%d ", st.stack[i]);
    }
    printf("\n");
}

void PUSH (struct Stack *st, int value) {
    /*if stack is full or not */
    if (st->top == st->size-1) {
        /* size is full*/
        printf("Stack Overflow.\n");
        return;
    } else {
        /* now enter the data*/
        st->top++;
        st->stack[st->top] = value;
    }
}

int POP(struct Stack *st) {
    int x = -1;
    /*checking if the stack is null or not*/
    if (st->top == -1) {
        return x;
    } else {
        x = st->stack[st->top];
        st->top--;

        return x;
    }
}

/* Always beek the topmost value*/
int STACKTOP(struct Stack st) {
    int x = -1;
    if (st.top == -1) {
        printf("Stack Underflow.\n");
        return x;
    } else {
        return st.stack[st.top];
    }
}

int PEEK(struct Stack st, int position) {
    int x = -1;
    if (st.top - position + 1 < 0) {
        return -1;
    } else {
        return x = st.stack[st.top - position + 1];
    }
}

int isEmpty(struct Stack st) {
    if (st.top == -1) {
        // true
        return 1;
    } else {
        // false
        return 0;
    }
}

int isFull(struct Stack st) {
    if(st.top = st.size-1) {
        // true
        return 1;
    }

    // false
    return 0;
}

void Create_Menu() {
        printf("\n---Stack Basic Operation---\n");
        printf("1. Create A Stack.\n");
        printf("2. Push An Element Into The Stack.\n");
        printf("3. Pop The Element From The Stack.\n");
        printf("4. Peek An Element From Given Position.\n");
        printf("5. Is Stack Full.\n");
        printf("6. Is Stack Empty.\n");
        printf("7. Display The Stack.\n");
        printf("8. Exit.\n\n");

        printf("--- Enter Your Choice : ");
}

int main() {
    struct Stack st;
    int choice;

    while (choice != 8) {

        Create_Menu();
        scanf("%d", &choice);
        int ans;

        switch (choice) {
            case 1:
                Create_Stack(&st);
                printf("Stack Successfully Created ... \n");
                break;
            case 2:
                int value;
                printf("Enter The Value, That You Want To Push : ");
                scanf("%d", &value);
                PUSH(&st, value);
                printf("\nPushed Successfully.\n");
                break;

            case 3:
                ans = POP(&st);
                if (ans != -1) {
                    printf("Successfylly Poped Value Is %d.\n", ans);
                } else {
                    printf("Stack Underflow.\n");
                }
                break;

            case 4:
                int pos;
                printf("Enter The Position : ");
                scanf("%d", &pos);
                ans = PEEK(st, pos);
                if (ans == -1) {
                    printf("Invalid Position %d .\n", pos);
                } else {
                    printf("Successfully Peaked %d From Stack.\n", ans);
                }
                break;

            case 5:
                ans = isFull(st);
                if (ans == 0) {
                    printf("Stack Is Not Full.\n");
                } else {
                    printf("Stack Is Full.\n");
                }
                break;

            case 6:
                ans = isEmpty(st);
                if (ans == 0) {
                    printf("No, Stack Is Not Empty.\n");
                } else {
                    printf("Stack Is Empty.\n");
                }
                break;

            case 7:
                printf("Here Is The Stack From Top View : ");
                Display_Stack(st);
                break;

            case 8:
                printf("---- Thanking You ----\n");
                return 0;

            default:
                printf("Please Enter A Valid Choice.\n");
        }
    }   
    return 0;
}
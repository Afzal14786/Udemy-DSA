#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Stack {
    private:
        Node *top;
    public:
        Stack() {
            top = NULL;
        }

        void push(int value);
        int pop();
        int peek(int position);
        int size();
        bool isFull();
        bool isEmpty();
        void Display();
};

/*Implememtation*/

int Stack::size() {
    int length = 0;
    Node *curr = top;

    while (curr) {
        length++;
        curr = curr->next;
    }

    return length;
}

void Stack::push(int value) {
    Node *temp = new Node;

    if (temp == NULL) {
        cout << "Stack overflow" << endl;  // Corrected to "overflow"
    } else {
        temp->data = value;
        temp->next = top;
        top = temp;
    }
}

int Stack::pop() {
    int ans = -1;
    
    if (top == NULL) {
        return -1;
    } else {
        Node *curr = top;
        ans = top->data;
        top = top->next;
        delete curr;    
    }
    return ans;
}

int Stack::peek(int position) {
    int ans = -1;
    
    if (position < 1 || position > size()) {
        return ans;
    } else {
        if (position == 1) {
            ans = top->data;
            return ans;
        } else {
            Node *curr = top;
            for (int i = 0; i < position-1; ++i) {
                curr = curr->next;
            }
            if (curr) {
                ans = curr->data;
            }
            return ans;
        }
        return ans;
    }
}

void Stack::Display() {
    Node *temp = top;

    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        if (temp != NULL) {  // Corrected condition here
            cout << " -> ";
        }
    }
    cout << endl;
}

bool Stack::isEmpty() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}
/*
bool Stack::isFull() {
    Node *temp = new(nothrow) Node;  // Use nothrow to prevent exceptions on failure
    if (temp == NULL) {
        cout << "Yes, the stack is full.\n";  // Optional: only if you want this message
        return true;
    } else {
        delete temp;
        return false;
    }
}
*/

void Create_Menu() {
    cout << "\n-----Stack Basic Operation's Menu-----\n";
    cout << "1. Push into the stack.\n";
    cout << "2. Pop from the stack.\n";
    cout << "3. Peek from the stack.\n";
    cout << "4. Size of the stack.\n";
    cout << "5. Is stack empty.\n";
    cout << "6. Display The Stack.\n";
    cout << "7. Exit.\n\n";

    cout << "---Enter Your Choice : ";
}

int main() {

    Stack st;
    int choice, ans;

    while (choice != 7) {
        Create_Menu();
        cin >> choice;


        switch (choice) {
            case 1:
                int value;
                cout << "Enter value that you want to push into stack : ";
                cin >> value;
                st.push(value);
                cout << endl << value << " successfully pushed to stack---\n";
                break;
            
            case 2:
                ans = st.pop();
                if (ans == -1) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << ans << " Popped successfully from stack.\n"; 
                }
                break;

            case 3:
                int pos;
                cout << "Enter position, for getting your data from stack : ";
                cin >> pos;
                ans = st.peek(pos);
                if (ans == -1) {
                    cout << "Invalid Position. Position Should be >= 1 and <= " << st.size() << endl;
                } else {
                    cout << ans << " peeked successfully from stack.\n";
                }
                break;

            case 4:
                cout << "Size of the stack is : " << st.size() << endl;
                break;

            case 5:
                ans = st.isEmpty();
                if (ans == 1) {
                    cout << "Yes, the stack is empty." << endl;
                } else {
                    cout << "No, the Stack is not empty.\n";
                }
                break;

            case 6:
                cout << "Here is the stack : ";
                st.Display();
                break;

            case 7:
                cout << "\n-----Thanking You-----\n\n";
                break;
            
            default:
                cout << "Invalid Choice. Entered A Valid Choice Between (1 to 6).\n";
        }
    }
    return 0;
}
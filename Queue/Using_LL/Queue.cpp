#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Queue {
    private:
        Node *front;
        Node *rear;
    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }

        void enQueue(int data);
        int deQueue();
        void display();
};

void Queue::enQueue(int data) {
    // create a temp node //
    Node *temp = new Node;
    if (temp == NULL) {
        cout << "The Queue Is Full, Unable To Perform Insertion . . .\n";
    } else {
        temp->data = data;
        temp->next = NULL;
         
        // if it is the first node or element //
        if (front == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
}

int Queue::deQueue() {
    int ans = -1;
    Node *temp = new Node;

    // if the que is empty //
    if (front == NULL) {
        cout << "The Queue Is Empty, Unable To Perform Deletion . . .\n";
    } else {
        temp = front;
        ans = front->data;
        front = front->next;
        free(temp);
    }

    return ans;
}

void Queue::display() {
    Node *temp = front;

    while (front) {
        cout << front->data << " ";
        front = front->next;
    }

    cout << endl;
}

int main() {
    Queue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);

    q1.display();
    return 0;
}
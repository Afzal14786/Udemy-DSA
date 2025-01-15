#include <iostream>
using namespace std;

/**
 * Operations On Queue :
 * 1. enQueue(int data);   Insert Something into queue.
 * 2. deQueue();           Delete something from queue.
 * 3. size();              Size of the queue.
 * 4. isEmpty();           Queue is Empty ?
 * 5. isFull();            Queue is Full?
 * 6. last_elem();         Rear element in the queue;
 * 7. first_elem();        First element in the queue;
 */

class Node {
    public:
        int data;
        Node *next;
};

class Queue {
    private:
        Node *rear;
        Node *front;
    public:
        Queue() {
            rear = nullptr;
            front = nullptr;
        }

        void enQueue(int data);
        int deQueue();
        int size();
        bool isEmpty();
        bool isFull();
        int last_elem();
        int first_elem();
        void display();
};

bool Queue::isEmpty() {
    if (rear == front) {
        return true;   // queue is empty //
    } else {
        return false;
    }
}

bool Queue::isFull() {
    Node *temp = new Node;
    if (temp == nullptr) {
        return true;   // queue is full 
    }
    delete temp;
    return false; // not full 
}

void Queue::enQueue(int data) {
    if (isFull()) {
        throw std::out_of_range("Queue is Full.\n");
    } else {
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;

        if (front == nullptr) {
            rear = front = temp;
        }

        rear->next = temp;
        rear = temp;
    }
}

int Queue::deQueue() {
    // is Queue is empty //
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty, unable to deQueue element right now.\n");
    }

    // temp node assign to rear pointer //
    Node *temp = rear;
    int value = temp->data;
    rear = rear->next;   // move rear pointer to next location //

    delete temp;   // delete the temp pointer //

    return value;   // deleted value return here //
}

int Queue::size() {
    Node *temp = rear;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }

    delete temp;   // delete temp pointer //
    return count;   // return the size of the queue //
}

int Queue::last_elem() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty\n");
    }

    return rear->data;   // return new inserted data //
}

int Queue::first_elem() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty.\n");
    }

    return front->data;
}

void Queue::display() {

    if (isEmpty()) {
        throw std::out_of_range("Queue is empty, unable to display the queue.\n");
    }

    Node *temp = front;

    while (front) {
        cout << front->data << " ";
        front = front->next;
    }

    cout << endl;
    delete temp;   /// delete the temp pointer //
}

int main() {
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);

    q.display();

    return 0;
}
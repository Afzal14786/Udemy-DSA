#ifndef queue_header
#define queue_header

#include <iostream>
using namespace std;

/**
 * Creating a node class for tree //
 */
class Node {
public:
    int data;
    Node *left_child;
    Node *right_child;
};

/**
 * Creating a circular array using C++ //
 */
class Queue {
private:
    int size;       // Size of the array //
    int front;      // Front pointer //
    int rear;       // Rear pointer //
    Node **que;     // Queue array to hold the address of each node of the tree //

public:
    Queue(int size) {
        this->size = size;
        front = rear = 0;  // Initialize to 0, so that it's ready to store nodes.
        que = new Node *[this->size];
    }

    // Function / methods for queue useful for tree structure //
    void enQueue(Node *data);
    Node* deQueue();
    bool empty();
};

bool Queue::empty() {
    return front == rear;  // Corrected empty condition
}

void Queue::enQueue(Node *data) {
    if ((rear + 1) % size == front) {  // Circular queue full condition
        throw std::out_of_range("Queue is full, unable to enqueue.\n");
    } else {
        que[rear] = data;
        rear = (rear + 1) % size;  // Circular increment
    }
}

Node* Queue::deQueue() {
    if (front == rear) {  // Empty queue condition
        throw std::out_of_range("Queue is empty, unable to deQueue.\n");
    } else {
        Node* ans = que[front];
        front = (front + 1) % size;  // Circular increment
        return ans;
    }
}

#endif

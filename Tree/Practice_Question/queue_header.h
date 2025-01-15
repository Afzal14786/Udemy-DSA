#ifndef queue_header
#define queue_header

#include <iostream>
using namespace std;

/**
 * creating a node class for tree //
 */

class Node {
    public:
        int data;
        Node *left_child;
        Node *right_child;
};

/**
 * creating a circular array using C++ //
 */
class Queue {
    private:
        int size;  // size of the array //
        int front;  // font pointer //
        int rear;  // rear pointer //
        Node **que;   // que type array hold the address of the each node of tree //

    public:
        Queue(int size) {
            this->size = size;
            front = rear = -1;
            que = new Node *[size];
        }

        // function / methods for queue useful for tree structure //
        
        void enQueue(Node *data);
        Node * deQueue();
        bool empty();
};

bool Queue::empty() {
    return rear == front;
}

void Queue::enQueue(Node *data) {
    if ((rear+1) % size == front) {
        throw std::out_of_range("Queue is full, unable to enqueue.\n");
    } else {
        rear = (rear+1)%size;
        que[rear] = data;
    }
}

Node * Queue::deQueue() {
    Node *ans = nullptr;
    if (rear == front) {
        throw std::out_of_range("Queue is empty, unable to deQueue.\n");
    } else {
        front = (front+1)%size;
        ans = que[front];
    }

    return ans;
}


#endif
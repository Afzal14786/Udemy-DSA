#include <iostream>
#include <stack>
using namespace std;

class Queue {
    private:
        int rear;
        int front;
        int size;
        int *queue;

    public: 
        Queue(int size) {
            this->size = size;
            queue = new int[size];
            front = -1;
            rear = -1;
        }
        void enqueuing(int data);
        int dequeuing();
        void display();
        bool isFull();
        bool isEmpty();
        void circular_enque(int data);
        int circular_deque();
        void circular_display();
        void reverse_queue();
};

/**
 * we can implement queue using 2 stacks
 */



/**
 * using stack we can reverse the queue 
 */

void Queue::reverse_queue() {
    /* create an auxilary stack */
    stack<int> st;
    /* dequeue all the elements untill the queue is empty and push all the elements in the stack */
    while (!isEmpty()) {
        st.push(circular_deque());
    }

    /**
     * now pop all the elements of the stack untill it empty and enque to queue
     */
    
    while (!st.empty()) {
        circular_enque(st.top());
        st.pop();
    }
}

void Queue::circular_enque(int data) {
    /* checking full condition */
    if ((rear+1) % size == front) {
        cout << "The Queue Is Full.\n";
    } else {
        rear = (rear+1)%size;
        queue[rear] = data;
    }
}

int Queue::circular_deque() {
    int ans = -1;
    /* checking empty status */
    if (rear == front) {
        cout << "The Queue Is Empty.\n";
    } else {
        front = (front+1)%size;
        ans = queue[front];
    }

    return ans;
}

void Queue::circular_display() {
    int i = (front+1)%size;

    do {
        cout << queue[i] << " ";
        i = (i+1)%size;
    } while (i != (rear+1)%size);

    cout << endl;
}

void Queue::enqueuing(int data) {
    if (isFull()) {
        cout << "Queue Is Full, Unable To Perform Insertion Operation.\n";
    } else {
        rear++;
        queue[rear] = data;
    }
}

int Queue::dequeuing() {
    int ans = -1;
    if (isEmpty()) {
        cout << "The Queue Is Empty, Unable To Perform Deletion Operation.\n";
    } else {
        front++;
        ans = queue[front];
    }

    return ans;
}

bool Queue::isFull() {
    if (rear == size-1) {
        return true;
    } 

    return false;
}

bool Queue::isEmpty(){
    if (front == rear) {
        return true;
    }

    return false;
}

void Queue::display() {
    for (int i = front + 1; i <= rear; ++i) {
        cout << queue[i] << " ";
    }

    cout << endl;
}

int main() {
    int size;
    cout << "Enter The Size Of The Queue : ";
    cin >> size;

    Queue q1(size);

    q1.circular_enque(10);
    q1.circular_enque(20);
    q1.circular_enque(30);
    q1.circular_enque(40);
    q1.circular_enque(50);

    cout << "The Queue : ";
    q1.circular_display();

    cout << "\nReversing The Queue : \n";
    q1.reverse_queue();
    cout << "After Reversing The Queue : ";
    q1.circular_display();

    return 0;
}
#include <iostream>
using namespace std; 

/**
 * Implementing The Queue And It's ADT's Using Linked List ... 
 */

// ------------------------------------------------------------------------ //

        // Main Operation In Queue //
        /**
         * 1. enQueue(int x) : Insertion In Queue . O(1)
         * 2. deQueue (): Deletion From Queue . O(1)
         */

        // Auxilary Operation's On Queue //
        /**
         * 1. isFull() : Is The Queue Is Full . O(1)
         * 2. isEmpty() : Is The Queue Is Empty . O(1)
         * 3. size() : Size Of The Queue . O(1)
         */

// ------------------------------------------------------------------------ //

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
            front = nullptr;
            rear = nullptr;
        }
        void enQueue(int data);
        int deQueue();
        int size();
        bool isFull();
        bool isEmpty();
        void display_queue();
};

/* Inserting Element Into The Queue */

void Queue::enQueue(int data) {
    Node *temp = new Node;
    // is the queue full //
    if (isFull()) {
        cout << "Queue Is Full Unable To Perform Insertion Operation.\n";
    } else {
        // if the queue is not null //
        temp->data = data;
        temp->next = nullptr;

        // if the inserting element is the very first node, then
        if (front == nullptr) {
            front = rear = temp;
        } 

        // if it is not then insert element after rear, at rear->next //
        rear->next = temp;
        rear = temp;
    }
}

int Queue :: deQueue() {
    // creating a temp node //
    Node *temp = new Node;
    int x = -1;

    // if the queue is empty //
    if (front == nullptr) {
        cout << "The Queue Is Empty, Unable To Perform Deletion At This Moment : ";
        return x;
    } else {
        // assign temp node to front //
        temp = front;
        // hold current data //
        x = front->data;
        // move front to the next node //
        front = front->next;
        // node delete temp node //
        delete temp;
    }

    // final, return the deleted data //
    return x;
}

bool Queue :: isFull() {
    // creating a temp auxilary node //
    return false;
}

bool Queue :: isEmpty() {

    if (front == nullptr) {
        return true;
    }

    return false;
}

int Queue::size() {
    // create temp node //
    Node *temp = new Node;
    temp = front;
    int count = 0;
    
    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

void Queue::display_queue() {

    if (isFull()) {
        return;
    }

    Node *temp = front;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


void menu_option() {
    cout << "\n --------- Welcome To Queue And It's ADT's --------- \n";
    cout << "1. Insert Data Into Queue .\n";
    cout << "2. Delete Data Fron Queue .\n";
    cout << "3. Size Of The Queue .\n";
    cout << "4. Queue Is Full Or Not .\n";
    cout << "5. Queue Is Empty Or Not .\n";
    cout << "6. Display The Queue : \n";
    cout << "7. --------- Exit --------- \n\n";

    cout << "Enter Your Choice : ";
}

int main() {
    int choice, data, size, ans;
    Queue q1;

    while (choice != 7) {
        menu_option();
        cin >> choice;

        

        switch (choice)
        {
        case 1:
            cout << "\nEnter The Data You Want To Insert Into Queue : ";
            cin >> data;
            q1.enQueue(data);
            cout << data << " Successfully Added To Queue.\n";
            break;
        case 2:
            data = q1.deQueue();
            cout << data << " Successfully Deleted From Queue.\n";
            cout << "Now The Queue Is Look's Like : ";
            q1.display_queue();
            break;

        case 3:
            size = q1.size();
            cout << "Size of The Queue Is : " << size << endl;
            break;
        case 4:
            if (q1.isFull()) {
                cout << "The Queue Is Full.\n";
            } else {
                cout << "The Queue Is Not Full Yet.\n";
            }
            break;
        case 5:
            if (q1.isEmpty()) {
                cout << "The Queue Is Empty.\n";
            } else {
                cout << "Queue Is Not Empty.\n";
            }
            break;

        case 6:
            cout << "Here Is The Queue : ";
            q1.display_queue();
            break;
        case 7:
            cout << "6.\n --------- Thank Your Using Me --------- \n\n";
            return 0;
        default:
            cout << "Invalid Choice, Try Again --- \n";
            break;
        }
    }
    return 0;
}
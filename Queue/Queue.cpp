#include <iostream>
#include <any>
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
template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;
};

template <typename T>
class Queue {
    private:
        Node<T> *front;
        Node<T> *rear;
    public:
        Queue() {
            front = nullptr;
            rear = nullptr;
        }
        void enQueue(T data);
        T deQueue();
        int size();
        bool isFull();
        bool isEmpty();
        void display_queue();
        T front_data();
        T rear_data();
};

/* Inserting Element Into The Queue */

template <typename T>
void Queue<T>::enQueue(T data) {

    Node<T> *temp = new Node<T>;
    // is the queue full //
    if (isFull()) {
        throw std::out_of_range("Queue Is Full .");
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

template <typename T>
T Queue<T> :: deQueue() {
    // if the queue is empty //
    if (isEmpty()) {
        throw std::out_of_range("The Queue Is Empty.\n");
    } 
    // creating a temp node and asign it to front and store the data in a variable //
    Node<T> *temp = front;
    T value = front->data;
    
    // move front to the next node //
    front = front->next;
    // node delete temp node //
    delete temp;

    // final, return the deleted data //
    return value;
}

template <typename T>
bool Queue<T> :: isFull() {
    // creating a temp auxilary node //
    return false;
}

template <typename T>
bool Queue<T> :: isEmpty() {

    if (front == nullptr) {
        return true;
    }

    return false;
}


template <typename T>
int Queue<T> ::size() {
    // create temp node //
    Node<T> *temp = new Node<T>;
    temp = front;
    int count = 0;
    
    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

template <typename T>
T Queue<T> :: front_data() {
    if (isEmpty()) {
        throw std::out_of_range("Queue Is Empty.\n");
    }

    return front->data;
}

template <typename T>
T Queue<T> :: rear_data() {
    if (isEmpty()) {
        throw std::out_of_range("Queue Is Empty.\n");
    }

    return rear->data;
}


template <typename T>
void Queue<T>::display_queue() {

    if (isEmpty()) {
        throw std::out_of_range("Queue is empty, unable to display the queue.\n");
    }

    Node<T> *temp = front;
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
    cout << "6. Front Data .\n";
    cout << "7. Rear Data Is .\n";
    cout << "8. Display The Queue : \n";
    cout << "9. --------- Exit --------- \n\n";

    cout << "Enter Your Choice : ";
}

// void display_variant_variable (std::variant<int, double, string> var)  {
//     if (auto pval = std::get_if<int>(&var)) {
//         cout << "Integer : " << *pval << endl;
//     } else if (auto pval = std::get_if<double>(&var)) {
//         cout << "Double : " << *pval << endl;
//     } else if (auto pval = std::get_if<string>(&var)) {
//         cout << "String : " << *pval << endl;
//     } else {
//         cout << "Unknown Type!" << endl;
//     }
// }



int main() {
    Queue<int> q1;
    int choice, size, data;

    while (choice != 9) {
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
            cout << "Front Data Is : " << q1.front_data() << endl;
            break;
        
        case 7:
            cout << "Rear Data Is : " << q1.rear_data() << endl;
            break;

        case 8:
            cout << "Here Is The Queue : ";
            q1.display_queue();
            break;
        case 9:
            cout << "6.\n --------- Thank Your Using Me --------- \n\n";
            return 0;
        default:
            cout << "Invalid Choice, Try Again --- \n";
            break;
        }
    }
    return 0;
}
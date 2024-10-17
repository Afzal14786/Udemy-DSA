#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class LinkedList {
	private:
		Node *head;
	public:
		LinkedList() {
			head = NULL;
		}
		LinkedList(int A[], int n);
		// ~LinkedList();

		void DisplayList();
		void Insert(int index, int value);
		void Delete(int index);
		int Search(int key); // Linear and Improved //
		bool Is_Sorted();
		void Sort_List();
		bool Is_Having_Loop();
        int Count_Nodes();
};

/* Creating The List In C++*/
LinkedList :: LinkedList(int A[], int n) {
	Node *temp, *last;
	head = new Node;
	head->data = A[0];
	head->next = NULL;
    last = head;

    for (int i = 1; i < n; ++i) {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void LinkedList::DisplayList() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        if (temp->next != NULL) {
            cout << "-> ";
        }
        temp = temp->next;
    }

    cout << endl;
}

/* Function for count the no of nodes in the list*/

int LinkedList::Count_Nodes() {
    Node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}
/* Function For inserting at given positon */
void LinkedList::Insert(int idx, int value) {
    Node *curr_node, *next_node = head;
    // check the index value //
    if (idx < 0 && idx > Count_Nodes()) {
        cout << "Invalid Index.\n" << "(Index Shound Be >=0 To %d.)\n" << Count_Nodes() << endl;
    }

    /* Create the node which is going to insert. */
    curr_node = new Node;
    curr_node->data = value;
    curr_node->next = NULL;


    if (idx == 0) {
        curr_node->next = head;
        head = curr_node;
    } else {
        for (int i = 0; i < idx - 1; ++i) {
            next_node = next_node->next;
        }

        if (next_node) {
            curr_node->next = next_node->next;
            next_node->next = curr_node;
        }
    }
}

/* Implementing Delete Function For List*/

void LinkedList::Delete(int index) {
    Node *curr_node = head;
    Node *next_node = NULL;
    int deleted_value = 0;

    if (head == NULL) {
        cout << "The List is Empty. Deletion Not Possible .\n";
        return;
    } else {
        if (index == 0) {
            /* delete the very first node*/
            deleted_value = head->data;
            head = head->next;
            delete curr_node;
            cout << "The Deletied Value From The List Is : " << deleted_value << endl;
            return;
        } else {
            for (int i = 0; i < index - 1; ++i) {
                next_node = curr_node;
                curr_node = curr_node->next;
            }

            if (next_node != NULL) {
                next_node->next = curr_node->next;
                deleted_value = curr_node->data;
                delete curr_node;
                cout << "The Deletied Value From The List Is : " << deleted_value << endl;
                return;
            }
        }
    }
}

int main() {

    int Arr[] = {1,2,3,4,5,6};
    
    LinkedList list(Arr, 6);
    cout << "\n List Before Insertion : ";
    list.DisplayList();
    // cout << "\nList After Insertion : ";
    // list.Insert(2,100);
    
    // list.DisplayList();

    /*Dleting a node  */
    list.Delete(3);
    list.DisplayList();

    return 0;
}
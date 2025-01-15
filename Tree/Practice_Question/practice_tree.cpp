#include <iostream>
#include "queue_header.h"
using namespace std;


class Tree {
    public:
        Node *root;
        Tree() {
            root = nullptr;
        }
        void create_tree();
        void inorder(Node *p);
        void preorder(Node *p);
        void postorder(Node *p);
};

void Tree::create_tree() {
    Node *p, *temp;
    int value;  // it holds the value of the tree //

    Queue q(100);    // create a circular array queue //

    /* insert the root node */
    cout << "Enter The Value Of root$ Node : ";
    cin >> value;

    /* crate a new root and holds the data in value */
    root = new Node;
    root->data = value;
    root->left_child = root->right_child = nullptr;

    while (!q.empty()) {
        p = q.deQueue();

        /* enter the value of left child */
        cout << "Enter the left child of " << value << " : ";
        cin >> value;


        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->left_child = temp->right_child = nullptr;
            p->left_child = temp;
            q.enQueue(temp);
        }

        cout << "Enter the right child of " << value << " : ";
        cin >> value;

        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->left_child = temp->right_child = nullptr;
            p->right_child = temp;
            q.enQueue(temp);
        }
    }

}

void Tree::inorder(Node *p) {
    if ( p!= nullptr) {
        inorder(p->left_child);
        cout << p->data << " ";
        inorder(p->right_child);
    }
}

int main() {
    Tree t;
    t.create_tree();
    t.inorder(t.root);
    return 0;
};



#include <iostream>
#include <stack>
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
    void iterative_inorder(Node *p);
    void iterative_preorder(Node *p);
    void iterative_postorder(Node *p);
};

void Tree::create_tree() {
    Node *p, *temp;
    int value;  // holds the value of the tree //

    Queue q(100);    // create a circular array queue //

    /* insert the root node */
    cout << "Enter The Value Of root Node : ";
    cin >> value;

    /* create a new root and hold the data in value */
    root = new Node;
    root->data = value;
    root->left_child = root->right_child = nullptr;

    q.enQueue(root);  // Enqueue the root node right after creation

    while (!q.empty()) {
        p = q.deQueue();  // Dequeue a node

        // Prompt for left child
        cout << "Enter the left child of " << p->data << " (-1 for no left child): ";
        cin >> value;

        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->left_child = temp->right_child = nullptr;
            p->left_child = temp;
            q.enQueue(temp);  // Enqueue the new left child
        }

        // Prompt for right child
        cout << "Enter the right child of " << p->data << " (-1 for no right child): ";
        cin >> value;

        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->left_child = temp->right_child = nullptr;
            p->right_child = temp;
            q.enQueue(temp);  // Enqueue the new right child
        }
    }
}

void Tree::inorder(Node *p) {
    if (p != nullptr) {
        inorder(p->left_child);
        cout << p->data << " ";
        inorder(p->right_child);
    }
}

void Tree::preorder(Node *p) {
    if (p != nullptr) {
        cout << p->data << " ";
        preorder(p->left_child);
        preorder(p->right_child);
    }
}

void Tree::postorder(Node *p) {
    if (p != nullptr) {
        postorder(p->left_child);
        postorder(p->right_child);
        cout << p->data << " ";
    }
}

void Tree::iterative_inorder(Node *p) {
    stack<Node*> st;
    while (p != nullptr || !st.empty()) {
        if (p != nullptr) {
            st.push(p);
            p = p->left_child;
        } else {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->right_child;
        }
    }
}

void Tree::iterative_preorder(Node *p) {
    stack<Node*> st;
    while (p != nullptr || !st.empty()) {
        if (p != nullptr) {
            cout << p->data << " "; // Print the node
            st.push(p);
            p = p->left_child;
        } else {
            p = st.top();
            st.pop();
            p = p->right_child;
        }
    }
}
void Tree::iterative_postorder(Node *p) {
    stack<Node*> st;
    Node* lastVisited = nullptr;
    
    while (p != nullptr || !st.empty()) {
        if (p != nullptr) {
            st.push(p);
            p = p->left_child;
        } else {
            Node* peekNode = st.top();
            if (peekNode->right_child != nullptr && lastVisited != peekNode->right_child) {
                p = peekNode->right_child;
            } else {
                cout << peekNode->data << " ";
                lastVisited = st.top();
                st.pop();
            }
        }
    }
}


int main() {
    Tree t;
    t.create_tree();
    cout << "Inorder Traversal: ";
    t.iterative_postorder(t.root);
    cout << endl;
    return 0;
}

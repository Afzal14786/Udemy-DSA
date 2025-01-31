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
    int count_nodes(Node *p);
    int height(Node *p);
    int sum_of_nodes(Node *p);
    int count_leaf_node(Node *p);
    int count_non_leaf_node(Node *p);
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

int Tree::count_nodes(Node *p) {
    // Way 1 :
    // int x = 0, y = 0;
    // if (p != nullptr) {
    //     x = count_nodes(p->left_child);
    //     y = count_nodes(p->right_child);

    //     if (p->left_child && p->right_child) {
    //         return x + y + 1;
    //     } else {
    //         return x + y;
    //     }
    // }

    // Way 2

    if (p == nullptr) {
        return 0;
    }

    if (!p->left_child && !p->right_child) {
        return count_nodes(p->left_child) + count_nodes(p->right_child) + 1;
    }
    return count_nodes(p->left_child) + count_nodes(p->right_child);
}

int Tree::height(Node *p) {
    int x = 0, y = 0;
    if (p == 0) {
        return 0;
    }

    if (p != nullptr) {
        x = height(p->left_child);
        y = height(p->right_child);

        if (x > y) {
            return x + 1;
        } else {
            return y + 1;
        }
    }

    return 0;
}

int Tree::sum_of_nodes(Node *p) {
    int x = 0, y = 0;
    if (p != nullptr) {
        x = sum_of_nodes(p->left_child);
        y = sum_of_nodes(p->right_child);

        return x + y + p->data;
    }

    return 0;
}

int Tree::count_leaf_node(Node *p) {
    int x = 0, y = 0;
    if (p != nullptr) {
        x = count_leaf_node(p->left_child);
        y = count_leaf_node(p->right_child);

        /**
         * If the nodes' left-child as well as right-child is null, then we can count it as null-nodes or leaf nodes
         * Means a node with degree(0), means no child.
         *          ----- Here is the condition -----
         */
        if (p->left_child == nullptr && p->right_child == nullptr) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
}

int Tree::count_non_leaf_node(Node *p) {
    int x = 0, y = 0;
    if (p != nullptr) {
        x = count_non_leaf_node(p->left_child);
        y = count_non_leaf_node(p->right_child);

        /**
         * If the node have both the child then we can count it as non-leaf nodes or the node which have degree(2) .
         *              This is a node with degree(2).
         * 
         *          ----- Here is the condition -----
         */
        if (p->left_child != nullptr && p->right_child != nullptr) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }

    return 0;
}

/**
 * we can also count the no of nodes if a node have one children as well as 2 children
 * means a node a have degree(1) and degree(2) . All the internal nodes were count in this .
 *          ---- Here is the condition ----
 *      if (p->left_child || p->right_child) {
 *          return x + y + 1;
 *      } else {
 *          x + y;
 *      }
 */

/**
 * We can also count the no of nodes which have degree(1), means only one child
 *      ----- Here is the condition -----
 *      if ((p->left_child != nullptr && p->right_child == nullptr) || (p->left_child == nullptr && p->right_child != nullptr)) {
 *          return x + y + 1;
 *      } else {
 *          x + y;
 *      }
 * 
 *      We can enhance the operation using XOR(^) operation
 *      Here is the operation 
 * 
 *      if (p->left_child != nullptr ^ p->right_child != nullptr) {
 *          return x + y + 1;
 *      }
 */



int main() {
    Tree t;
    t.create_tree();
    cout << "Inorder Traversal: ";
    t.iterative_postorder(t.root);
    cout << endl;
    cout << "The number of nodes in the tree is : " << t.count_nodes(t.root) << endl;
    cout << "The height of the tree is : " << t.height(t.root) << endl;
    cout << "Sum of the nodes in the tree is : "<< t.sum_of_nodes(t.root) << endl;
    count << "Count the no of Leaf nodes in the tree : " << t.count_leaf_node(t.root) << endl;
    return 0;
}

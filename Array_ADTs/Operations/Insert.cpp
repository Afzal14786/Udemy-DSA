#include <iostream>
using namespace std;

class Array_Operations {

    public :
        int size;
        int length;
        int *A;

        Array_Operations(int size) {
            this->size = size;
            length = 0;
            A = new int[size];
        }

        ~Array_Operations() {
            delete []A;
        }
};

/* Create Display Method To Display : */

void display (Array_Operations &ar_op) {

    cout << "The Element's Inside the array : ";
    for (int i = 0; i < ar_op.length; ++i) {
        cout << ar_op.A[i] << " ";
    }
    cout << endl;
}

/* Taking the elements as input from the user.*/

void input_elem(Array_Operations &ar_op) {
    cout << "Enter The Elements : ";
    for (int i = 0; i < ar_op.length; ++i) {
        cin >> ar_op.A[i];
    }
}

/* Inser Element at a particular index. */

void insert_value(Array_Operations &ar_op, int idx, int value) {
    if (idx >=0 && idx <= ar_op.length && ar_op.length < ar_op.size) {
        for (int i = ar_op.length; i > idx; --i) {
            ar_op.A[i] = ar_op.A[i-1];
        }
        ar_op.A[idx] = value;
        ar_op.length++;
    } else {

        cout << "Insertion index is out of bounds or array is full." << endl;
    }
}

int main() {

    int index;
    int value;
    int size;

    // Array_Operations *ar = new Array_Operations();
    cout << "Enter The Size Of The Array : ";
    cin >> size;

    Array_Operations ar(size);

    cout << "Enter The Length Of The Array Or No Of Elements in the array : ";
    cin >> ar.length;

    input_elem(ar);
    display(ar);

    cout << "Enter The Index Where You Want To Store The Value : ";
    cin >> index;
    cout << "Enter The Value : ";
    cin >> value;

    insert_value(ar, index, value);
    display(ar);

    return 0;
}
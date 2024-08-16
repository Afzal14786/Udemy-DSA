#include <iostream>
using namespace std;

struct ShiftOperator {
    int array[20];
    int size;
    int length;
};

void leftShift(struct ShiftOperator *left) {
    int temp;
    int i;
    for (i = 0; i < left->length-1; ++i) {
        if (i == 0) {
            temp = left->array[i];
        }
        left->array[i] = left->array[i+1];
    }
    left->array[i] = temp;
}

void rightShift(struct ShiftOperator *right) {
    int temp, i;
    for (i = right->length-1; i >= 0; --i) {
        if (i == right->length-1) {
            temp = right->array[i];
        }
        right->array[i] = right->array[i-1];
    }

    right->array[0] = temp;
}

void Display (struct ShiftOperator left ) {
    for (int i = 0; i < left.length; ++i) {
        cout << left.array[i] << " ";
    }
    cout << endl;
}
int main() {
    struct ShiftOperator left = {{1,2,3,4,5}, 6, 5};
    rightShift(&left);
    Display(left);
    return 0;
}
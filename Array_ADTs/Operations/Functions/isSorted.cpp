#include <iostream>
using namespace std;

struct Array {
    int array[20];
    int size;
    int length;
};

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * arranging +ve and -ve number's
 */
void ArrangeElements(struct Array *arr) {
    int i = 0;
    int j =  arr->length-1;

    while (i < j) {
        while (arr->array[i] < 0) {
            ++i;
        }

        while (arr->array[j] >= 0) {
            --j;
        }

        if (i < j) {
            swap (&arr->array[i], &arr->array[j]);
        }
    }
}
/**
 * check array is sorted or not.
 */
bool isSorted(struct Array arr) {
    for (int i = 0; i < arr.length-1; ++i ) {
        if (arr.array[i] > arr.array[i+i]) {
            return false;
        }
    }
    return true;
}

void display(struct Array array) {
    cout << "Elements are inside the array : ";
    for (int i = 0; i < array.length; ++i) {
        cout << array.array[i] << " ";
    }
    cout << endl;
}

/**
 * Inserted in a sorted array.
 */

void insert(struct Array *insrt, int value) {

    if (insrt->length == insrt->size) {
        return;
    }

    int i = insrt->length-1;
    while (i >= 0 && insrt->array[i] > value) {
        insrt->array[i+1] = insrt->array[i];
        i--;
    }
    insrt->array[i+1] = value;
    insrt->length++;

}

int main() {

    // struct Array ar = {{-3,-8,6,11,-9,15,24,0,-1,26,-7}, 11, 20};
    struct Array insrt= {{2,3,4,5,7,8,9,10,15,16,21,24,25}, 20, 13};
    // cout << "Element's before arranging the element's : \n";
    
    // bool ans = isSorted(ar);
    // ArrangeElements(&ar);
    // display(ar);
    // if (ans == 0) {
    //     cout << "Array is not sorted.\n";
    // } else {
    //     cout << "It's not sorted.\n";
    // }

    insert(&insrt, 11);
    display(insrt);

    return 0;
}
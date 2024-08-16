#include <iostream>
using namespace std;

struct Reverse_Operation {
    int array[20];
    int size;
    int length;
};

/**
 * Method 1 :   
 *      Using extra auxilary space
 *      time complexity = O(n)
 *      space complexity = O(n)
 */

void reverse(struct Reverse_Operation *rev) {
    int *B;
    B = new int[rev->length];
    for (int i = rev->length-1, j = 0; i >= 0; --i, ++j) {
        B[j] = rev->array[i];
    }

    for (int i = 0; i < rev->length; ++i) {
        rev->array[i] = B[i];
    }
}

/***
 * Method 2:
 *  it will take constant space 
 *  time complexity = O(n)
 *  space complexity = O(1);
 */
void reverse2(struct Reverse_Operation *rev2) {
    for (int i = 0, j = rev2->length-1; i < j; ++i, --j) {
        int temp =  rev2->array[i];
        rev2->array[i] = rev2->array[j];
        rev2->array[j] = temp;
    }
}

void Display (struct Reverse_Operation rev ) {
    for (int i = 0; i < rev.length; ++i) {
        cout << rev.array[i] << " ";
    }
    cout << endl;
}

int main() {

    struct Reverse_Operation ar = {{1,2,3,4,5,6,7}, 7, 7};
    reverse(&ar);
    Display(ar);

    return 0;
}
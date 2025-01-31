#include <iostream>
using namespace std;

struct Array
{
    int arr[20];
    int size;
    int len;
};

void display(struct Array del) {
    cout << "Elements are inside the array : ";
    for (int i = 0; i < del.len; ++i) {
        cout << del.arr[i] << " ";
    }
    cout << endl;
}
/**
 * Delete an element from a particular given index.
 */
int delete_elem(struct Array *del, int idx) {

    int temp_value = 0;
    if (idx >= 0 && idx < del->len) {
        temp_value = del->arr[idx];
        for (int i = idx; i < del->len-1; ++i) {
            del->arr[i] = del->arr[i+1];
        }
        del->len--;
        return temp_value;

    }
    return temp_value;
}

/**
 * Searching :
 *      1. Linear Search
 *      2. Binary Search
 */

/* Linear Search */

int linear_search(struct Array ar, int key) {
    for (int i = 0; i < ar.len; ++i) {
        if (key == ar.arr[i]) {
            return i;
        }
    }

    return -1;
}

/* Improve linear search using swap the key element with the starting value. */

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int lin_imp(struct Array *imp_lin, int key) {
    for (int i = 0; i < imp_lin->len-1; ++i) {
        if (key == imp_lin->arr[i]) {
            swap(imp_lin->arr[i], imp_lin->arr[0]);
            return 0;
        }
    }
    return -1;
}

/* Binary Search */

int binary_search(struct Array bisrch, int key) {

    int start = 0;
    int end = bisrch.len;

    while (start <= end) {
        int mid = start + (end - start)/2;
        if (key == bisrch.arr[mid]) {
            return mid;
        } else if (key > bisrch.arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    struct Array elem = {{1,2,3,4,5,6,7,8,9,10},10,10};

    // int ans = delete_elem(&elem, 0);
    // cout << "The Element " << ans << " is deleted.\n";

    int find = lin_imp(&elem, 4);
    cout << "The key element found at index : "<< find << endl;
    display(elem);

    
}

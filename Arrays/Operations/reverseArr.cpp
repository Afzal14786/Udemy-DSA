#include <iostream>

void printArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ",";
    }
    std::cout << "\n";
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void reverse1(int *arr, int size) {
    int newAr[size];

    for (int i = 0; i < size; ++i) {
        int j = size-i-1;
        newAr[i] = arr[j];
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = newAr[i];
    }

    printArr(arr, size);  // printing the reverse array with extra space .

    /**
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
}

void reverseOptimize(int *arr, int size) {
    int start = 0, end = size-1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // now printing the reverse array 
    printArr(arr, size);

    /**
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
}

int main() {
    int array[] = {3, 7, 9, 10, 78};
    int size = sizeof(array) / sizeof(int);

    /** Reverse the array without using any extra space */
    reverseOptimize(array, size);
    
    int array2[] = {10, 20, 30, 40, 50, 60};
    int size2 = sizeof(array2) / sizeof(int);

    /* reverse the array using extra space */
    reverse1(array2, size2);

    return 0;
}
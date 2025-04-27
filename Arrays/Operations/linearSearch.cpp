#include <iostream>

int findKey(int *array, int size, int key) {

    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;  // means key not found and time complexity is O(n)
}


/**
 * Time Complexity : 
 *      1. Best Case Time Complexity : O(1) : Key found at first index
 *      2. Wrost Case Time Complexity : O(n) : key found at last or not found
 *      3. Average Case Time Complexity : O(n) : key found in the middle of the array or in between
 */
int main() {
    int array[] = {3, 6, 8, 12, 7, 9};
    int key = 50;
    int size = sizeof(array) / sizeof(int);
    std::cout << "The given key " << key << " is Found at index: " << findKey(array, size, key) << std::endl;
    return 0;
}
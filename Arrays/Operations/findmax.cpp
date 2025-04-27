#include <iostream>

int findMax(int arr[], int size) {
    int max = arr[0];

    for (int i = 0; i < size; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}


int findMin(int *array, int size) {
    int min = array[0];
    
    for (int i = 0; i < size; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
    }

    return min;
}

int main() {
    int array[] = {5,4,3,9,12,1};
    int size = sizeof(array) / sizeof(int);
    std::cout << "The largest number in the given array is : " << findMax(array, size) << std::endl;
    std::cout << "The smallest number in the given array is : " << findMin(array, size) << std::endl;

    return 0;
}
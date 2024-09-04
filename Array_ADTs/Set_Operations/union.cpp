#include <iostream>
using namespace std;

class Array {
    private:
        int *array;
        int size;
        int length;

    public:
        Array() {
            size = 10;
            length = 0;
        }

        Array(int size) {
            this->size = size;
            length = 0;
            array = new int[size];
        }

        Array* UNION(Array ar);
        void insertElement(int length);
};

void Array::insertElement(int length) {
    for (int i = 0; i < length; ++i) {
        cin >> array[i];
    }
}



Array* Array::UNION(Array arr) {
    int i = 0, j = 0, k = 0;
    int *result = new int[length + arr.length];

    while (i < length && j < arr.length) {
        if (array[i] < arr.array[j]) {
            result[k++] = array[i++];
        } else if (arr.array[j] < array[i]) {
            result[k++] = arr.array[j++];
        } else if (array[i] == arr.array[j]) {
            result[k++] = array[i++];
            j++;
        }
    }

    for (; i < length; i++) {
        result[k++] = array[i];
    }

    for (; j < arr.length; j++) {
        result[k++] = arr.array[j];
    }

    return result;
}

int main() {
    
    return 0;
}


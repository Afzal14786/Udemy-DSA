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
            length = 10;
            array = new int[size];
        }

        Array(int size) {
            this->size = size;
            length = 0;
            array = new int[size];
        }

        Array* difference(Array arr);

};

int main() {

    return 0;
}

Array* Array::difference(Array array2) {
    int i,j,k;
    i = j = k = 0;

    Array *result = new Array(length + array2.length);
    while (i < length && j < array2.length) {
        if (array[i] < array2.array[j]) {
            result->array[k++] = array[i++];
        } else if (array2.array[j] < array[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    for (; i < length; ++i) {
        result->array[k++] = array[i];
    }
    result->length = k;
    return result;
}
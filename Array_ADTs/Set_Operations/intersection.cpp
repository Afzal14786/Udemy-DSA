#include <iostream>
using namespace std;

class Array {
    private:
        int *arr;
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
            arr = new int[size];
        }

    Array* Intersection(Array ar2);
        
};



int main() {

    return 0;
}

Array *Array::Intersection(Array ar2)
{
    int i = 0, j = 0, k = 0;
    Array *ar3 = new Array(length + ar2.length);
    while (i < length && j < ar2.length) {
        if (arr[i] < ar2.arr[j]) {
            i++;
        } else if (ar2.arr[j] < arr[i]) {
            j++;
        } else if (arr[i] == ar2.arr[j]) {
            ar3->arr[k++] = arr[i++];
            j++;
        }
    }

    ar3->length = k;

    return ar3;
}

#include <iostream>
using namespace std;

/**
 * The methods are :
 *      1. get(index)
 *      2. set(index, new_value)
 *      3. delete(index)
 *      4. max()
 *      5. min()
 *      6. avg()
 *      7. sum()
 */

struct Array {
    int arr[20];
    int size;
    int length;
};

void DISPLAY(struct Array ar) {
    cout << "Here are the elements inside the array : ";
    for (int i = 0; i < ar.length; ++i) {
        cout << ar.arr[i] << " ";
    }
    cout << endl;
}

/* It will get the value from a given index. */
int GET(struct Array ar, int idx) {
    return ar.arr[idx];
}

/* It will set a new element in a given index value. */
void SET(struct Array *ar, int idx, int new_value) {
    ar->arr[idx] = new_value;
}

/* It will return the delete element from the array. */
int DELETE(struct Array *ar, int index) {
    int deleted = 0;
    if (index >= 0 && index < ar->length) {
        deleted = ar->arr[index];
        for (int i = index; i < ar->length-1; ++i) {
            ar->arr[i] = ar->arr[i+1];
        }
        ar->length--;
        return deleted;
    }

    return deleted;
}

/* Finding max value in an array.*/

int MAX(struct Array ar) {
    int max = 0;;
    for (int i = 0; i < ar.length; i++) {
        if (ar.arr[i] > max) {
            max = ar.arr[i];
        }
    }

    return max;
}

/* Finding min value in an array. */
int MIN(struct Array ar) {
    int min = ar.arr[0];
    for (int i = 1; i < ar.length; i++) {
        if (ar.arr[i] < min) {
            min = ar.arr[i];
        }
    }
    return min;
}

/* Calculate sum of elements inside the array. */

int SUM (struct Array ar) {
    int total = 0;
    for (int i = 0; i < ar.length; ++i) {
        total += ar.arr[i];
    }

    return total;
}

/* Finding average of an array. */

float AVG (struct Array ar) {
    int sum = SUM(ar);
    float avg = (float) sum/ar.length;

    return avg;
}

int main() {

    struct Array arr = {{10,87,67,54,76,45,89,67, 997,54,90}, 20, 11};
    /* Calling Get Function.*/
    int get_elem = GET(arr, 5);
    cout << "Element at given index is :) " << get_elem << "\n";

    /*Calling Set Function .*/
    SET(&arr, 0, 100);
    cout << "Set A new value at given index 0 :)\n";
    DISPLAY(arr);

    int ans = DELETE(&arr, 6);
    cout << "The Element " << ans << " is successfully deleted from the array :).\n";
    DISPLAY(arr);

    int max = MAX(arr);
    cout << "Miximum element in the array is :) " << max << endl;

    int min = MIN(arr);
    cout << "The minimum element in the array is :) " << min << endl;

    int sum = SUM(arr);
    cout << "Sum of the element inside the array is :) " << sum << endl;

    float avg = AVG(arr);
    cout << "Average of the array is :) " << avg << endl;
    return 0;

    /**
     * Here are the output's for the above function calls :
     *  Element at given index is :) 45
        Set A new value at given index 0 :)
        Here are the elements inside the array : 100 87 67 54 76 45 89 67 997 54 90 
        The Element 89 is successfully deleted from the array :).
        Here are the elements inside the array : 100 87 67 54 76 45 67 997 54 90 
        Miximum element in the array is :) 997
        The minimum element in the array is :) 45
        Sum of the element inside the array is :) 1637
        Average of the array is :) 163.7
     */
}
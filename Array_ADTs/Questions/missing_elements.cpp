#include <iostream>
using namespace std;

class FindMissingElement {
    private:
        int *array;
        int size;
        int length;

    public:
        FindMissingElement() {
            size = 10;
            length = 10;
            array = new int[size];
        }

        FindMissingElement(int size) {
            this->size = size;
            length = size;
            array = new int[size];
        }

        
        void Insert();
        int single_elem_in_sorted_array();
        void missing_elem2();
        void multiple_miss_elem();
        void unsorted_miss_elem();
        void Display();
};



int main() {

    FindMissingElement ms(10);
    cout << "Kindly Enter a Sorted Array : ";
    ms.Insert();

    // cout << "The Missing Element is : " << ms.single_elem_in_sorted_array() << endl;
    // cout << ms.missing_elem2() << endl;
    ms.unsorted_miss_elem();

    return 0;
}

void FindMissingElement::Display()
{
    cout << "Here are the elements inside the array : ";
    for (int i = 0; i < size - 1; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
}

void FindMissingElement::Insert()
{
    for (int i = 0; i < length; ++i) {
        cin >> array[i];
    }
}

int FindMissingElement::single_elem_in_sorted_array()
{
    int last_elem = array[size-1];
    int total = last_elem * (last_elem + 1)/2;

/**
 * Time Complexity = O(n)
 */

    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    int missing_elem = total - sum;
    return missing_elem;
}

void FindMissingElement::missing_elem2()
{
/**
 * Time Complexity = O(n)
 * 
 * If the number's are not first 'n' natural number's .
 */
    int ans;
    for (int i = 0; i < length; ++i) {
        int diff = array[0] - 0;
        if (array[i]-i != diff) {
            ans = i + diff;
            cout << "The Missing Element Is : " << ans << endl;
            return;
        }
    }
}

void FindMissingElement::multiple_miss_elem()
{
    int diff = array[0] - 0;
/**
 * Time Complexity = O(n)
 */
    for (int i = 0; i < length; ++i) {
        if (array[i]-i != diff) {
            while (diff < array[i]-i) {
                cout << "Missing Element Are : " << i + diff << endl;
                diff++;
            }
        }

    }
}

/**
 * Multiple missing element in Unsorted Array.
 */


void FindMissingElement::unsorted_miss_elem()
{
    int high = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] > high) {
            high = array[i];
        }
    }
    cout << "The Heighest Element in the array is : " << high << endl;

    int *arr = new int[high];

    /**
     * Initialize all the elements of hash table with 0.
     */
    for (int i = 0; i < high; ++i) {
        arr[i] = 0;
    }

    /**
     * marked 1 at inside the hash table which are present in the given array.
     */
    for (int i = 0; i < length; ++i) {
        arr[array[i]]++;
    }

    /**
     * Finding the missing elements ; 
     */

    cout << "The Missing Elements Are : " << endl;
    for (int i = 1; i < high; ++i) {
        if (arr[i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}
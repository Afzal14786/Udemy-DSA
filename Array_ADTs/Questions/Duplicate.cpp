#include <iostream>
using namespace std;

class Find_Duplicate {
    private:
        int *array;
        int size;
        int length;

    public:
        Find_Duplicate() {
            size = 10;
            length = 10;
            array = new int[size];
        }

        Find_Duplicate(int size) {
            this->size = size;
            length = size;
            array = new int[size];
        }

        void Insert();
        void display();
        int max();
        void duplicate1();
        void count_duplicates();
        void duplicate_using_hash();
        void unsorted_duplicate();
        void Unsorted_Hash_Table_Duplicate();
};

int main() {
    Find_Duplicate find(10);
    
    cout << "Inser A Sorted List Of Elements : ";
    find.Insert();
    
    find.Unsorted_Hash_Table_Duplicate();


    find.display();
    return 0;
}

void Find_Duplicate::display()
{
    cout << "Here are the elements inside the array : ";
    for (int i = 0; i < size - 1; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int Find_Duplicate::max()
{
    int max = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void Find_Duplicate::Insert()
{
    for (int i = 0; i < length; ++i) {
        cin >> array[i];
    }
}

void Find_Duplicate::duplicate1()
{
    int lastDuplicate = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] == array[i+1] && array[i] != lastDuplicate) {
            cout << "Duplicate Element is : " << array[i] << endl;
            lastDuplicate = array[i];
        }
    }
}

void Find_Duplicate::count_duplicates()
{
    for (int i = 0; i < length - 1; ++i) {
        if (array[i] == array[i+1]) {
            int j = i + 1;
            while (array[j] == array[i]) {
                j++;
            }
            cout << "Duplicate Element Is : " << array[i] << " And ";
            cout << "It's Appearing " << j-i << " Times." << endl;
            i = j - 1;
        }
    }
}

/**
 * Using Hash Table
 */
void Find_Duplicate::duplicate_using_hash()
{
    int len_size = array[length-1];
    int *hashTable = new int[len_size];
    for (int i = 0; i < len_size; ++i) {
        hashTable[i] = 0;
    }

    for (int i = 0; i < length; ++i) {
        hashTable[array[i]]++;
    }

    for (int i = 0; i < len_size; ++i) {
        if (hashTable[i] > 1) {
            cout << "Duplicate Element is : " << i << " And ";
            cout << "It's Appearing " << hashTable[i] << " Times" << endl;
        }
    }
}

/**
 * Duplicate in unsorted array :
 */
void Find_Duplicate::unsorted_duplicate()
{
    for (int i = 0; i < length - 1; ++i) {
        int count = 1;
        if (array[i] != -1) {
            for (int j = i + 1; j < length; ++j) {
                if (array[i] == array[j]) {
                    count++;
                    array[j] = -1;
                }
            }

            if (count > 1) {
                cout << "Duplicate Is : " << array[i] << " And ";
                cout << "It's Appearing " << count << " Times." << endl;
            }
        }
    }
}


/**
 * Duplicate in unsorted array : Using Hash Table
 */

void Find_Duplicate::Unsorted_Hash_Table_Duplicate()
{
    int len_size = 8;
    int *hash = new int[len_size];

    for (int i = 0; i <= len_size; ++i) {
        hash[i] = 0;
    }
    for (int i = 0; i < length; ++i) {
        hash[array[i]]++;
    }

    for (int i = 0; i <= len_size; ++i) {
        if (hash[i] > 1) {
            cout << "Duplicate Element is : " << i << " And ";
            cout << "It's Appearing " << hash[i] << " Times"<< endl;
        }
    }
}

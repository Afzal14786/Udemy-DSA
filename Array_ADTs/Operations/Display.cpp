#include <iostream>
using namespace std;

class Array {

public:
    int size;
    int length;
    int *A;
};

/* Here a display method to display the element's inside an array.*/
void display(Array ar) {
    for (int i = 0; i < ar.length; ++i) {
        cout << ar.A[i] << " ";
    }
    cout << endl;
}

int main() {

    Array *ar = new Array();
    cout << "Enter The Size Of The Array : ";
    cin >> ar->size;
    cout << "Enter, How many element you want to enter : ";
    cin >> ar->length;
    
    ar->A = new int[ar->size];
    
    cout << "Enter The Element's you want to entered in the array : ";
    for (int i = 0; i < ar->length; ++i) {
        cin >> ar->A[i];
    }

    cout << "Here Is The Element's Inside the array : ";
    display(*ar);
    



    return 0;
}
#include <iostream>
using namespace std;



int main() {
    /*
        There are 3 ways or methods to declare a 2D array.
    */

    /* Way 1 */

    // Decleration //
//    int array[3][4];

    /* decleration & Initialization*/
    int array[3][4] = {{1,2,3,4},{2,4,6,8},{3,6,9,12}};

    /* Way 2 : Using Single Pointer.*/

    int *Arr[3];
    Arr[0] = new int[4];
    Arr[1] = new int[4];
    Arr[2] = new int[4];

    /* Way 3 Using Double Pointer.*/

    int **A;

    A = new int *[3];

    /* Decleration. */
    A[0] = new int[4];
    /* Initialization. */
    A[0][0] = 5;
    A[0][1] = 10;
    A[0][2] = 15;
    A[0][3] = 20;

    A[1] = new int[4];
    A[1][0] = 25;
    A[1][1] = 30;
    A[1][2] = 35;
    A[1][3] = 40;

    A[2] = new int[4];
    A[2][0] = 45;
    A[2][1] = 50;
    A[2][2] = 55;
    A[2][3] = 60;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    /* Accessing the elements inside 2D array we use for loop.*/

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
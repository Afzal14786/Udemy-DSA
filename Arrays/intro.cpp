#include <iostream>
using namespace std;

/*

    #Topic Starting Information.
    ----------------------------

    Topic : Array's Representation.
    Date : 29 July 2024
    Teacher : Abdul Bari
    Student : Me (Md Afzal).
*/
int main () {

    /* Diferent Ways To Decleration and Initialization Of Array.*/
    int A[5];
    int B[5] = {1,2,3,4,5};
    int C[5] = {3,5,2};
    int D[5] = {0};
    int E[] = {1,2,3,4,5,6};

    /* Using For Loop, Traversing Inside The Array And Accessing The Elements Of The Array.*/

    for (int i = 0; i < 5; ++i) {
        /* Different Ways To Access The Element Of An Array.*/
        /*1.*/ cout << B[i] << " ";     /* O/P : 1 2 3 4 5 */
        // /*2.*/ cout << i[B] << " ";     /* O/P : 1 2 3 4 5 */
        // /*3.*/ cout << *(B+i) << " ";   /* O/P : 1 2 3 4 5 */
    }

    cout <<  endl;
    /* Address Of The Element's Are Contigious : */
    for (int i = 0; i < 5; ++i) {
        cout << &B[i] << " ";
        /*
            O/P :
                0x7ffd0c528530 0x7ffd0c528534 0x7ffd0c528538 0x7ffd0c52853c 0x7ffd0c528540 

            -> All the address are Contigious.
        */
    }
    cout <<  endl;
    return 0;
}
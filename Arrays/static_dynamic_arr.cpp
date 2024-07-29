#include <iostream>
using namespace std;

/*
    # Static and Dynamic Array (In Terms Of Memory Representation).


*/

int main() {
    /*
        int arr[5]; 
        -> This array will create inside the stack memory.
        -> The size of the array is decided at the compile time, when the array is create inside stack.
        -> Memory is allocated at the runtime.
        -> We can create any size of array during runtime and it will create inside stack only.
    */
    int arr[5];

    /*
        -> The array which is created inside heap memory, that's array's size and the memory both are allocated at     runtime.
        -> We can use "new" keyword for creating array or any object inside heap memory.
        -> We can access the heap memory object or array using pointer only.
        Ex :

        /* This will create array of size 5 inside the heap memory. but the "ptr"(Pointer) is created inside the stack /*.

        // Decleration of Pointrer In C++//
        int *ptr ;
        ptr = new int[5];

        // decleration of array inside heap using C language.

        int *ptr;
        ptr = (int *)malloc(5*sizeof(int));
    */

    /*
        * Once the array of some size is created (heap/stack), the size of the array cannot change.
        * And it is not possible to resize it, but still if we want to change the size then it is possible only inside the heap memory .
        * But in this case the actually array cannot increase the size, there is some alternative option to do it.
        * We'll look into it latter. . .
        * 
        * 
        * After the execuation of the program or if the memory of the heap is not required then it must be deallocated.
        * If we cannot deallocate or delete it, then it may cause memory leak.
        * 
        * In C++ we use "delete []p" and
        * In C langauge we use "free(p)", where p is the pointer.
    */

    /* Here is some example.*/

    /* Accessing the array inside the Stack Memory.*/
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    /* This Pointer variable is created inside stack and it holds the address of the array which is inside the Heap Memory. */
    int *ptr;

    // created inside the heap memory. //
    ptr = new int[5];

    /* Using ptr we can access the value inside the array (Heap Memory).*/
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i] << " ";
    }

    cout << endl;

    /* Use it after executing the program to avoid memory leak problem.*/
    delete []ptr;

    /*
        Creating array using C languge inside Heap Memory.
    */

    int array[10];
    int *ptr2;

    ptr2 = (int *)malloc(10*sizeof(int));

    for (int i = 0; i < 10; ++i) {
        cout << ptr2[i] << " ";
    }

    cout << endl;

    /* Use it after executing the program to avoid memory leak problem.*/
    free(ptr2);
    return 0;
}
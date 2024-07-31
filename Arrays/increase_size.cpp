#include <iostream>
using namespace std;

/*
    # Topic : Increasing The Size Of The Array :
    Date : 30 July 24
*/

int main() {
    int *p = new int[5];
    for (int i = 1; i <= 5; ++i) {
        p[i] += i;
    }

    int *q = new int[10];
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    delete []p;
    p = q;
    q = NULL;
 
    for (int i = 0; i < 10; ++i) {
        cout << p[i] << " ";        /* Here q is totally get off from the new array and the p is assign to new array*/
    }
    cout << endl;
    return 0;
}
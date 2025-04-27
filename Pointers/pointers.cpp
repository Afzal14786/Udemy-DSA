#include <iostream>
using namespace std;

/* the number is only change within this function it will not change the actual number which is define in the main function 
 It makes a copy of the passed value and manipulate the value . . .
*/


int passByValue(int num) {
    num = 30;
    return num;
}

// void passByReferance(int *num) {
//     *num = 30;
//     cout << *num << endl;
// }

void passByReferance(int &num) {
    num = 20;
    cout << "The number is updated inside function : "<< num << endl;
}

int main() {
    /* Pass By Value*/
    // int num = 10;
    // cout << num << endl;    // the number'll remain same, it will not change the number .

    // if (num == passByValue(num)) {
    //     cout << "Pass By Referance.\n";
    // } else {
    //     cout << "Pass By Value\n";
    // }

    /* Pass By Referance : Using Pointers */
    int age = 10;
    passByReferance(age);
    cout << "Actual Value is modified : "<< age << endl;        // here age is modified from 10 to 20;

    /* Pass By Referance : Using Referance (alices) Where the differents varials points to the same memory location*/

    int x = 20;
    int &y = x;

    /** above example both `a & b` points the same memory location */
    // let update the `y` and this update will reflect in `x` as well
    y = 300;
    cout << "The Value Of `Y` is : "<< y << endl;
    cout << "The Value Of `X` is : " << x << endl;
    return 0;
}
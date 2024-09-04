#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

/*
    Fibonacchi Series : 0 1 1 2 3 5 8 13 21 . . . so on
*/


/*
    This function will take O(2^n) time for executing the function.
    This method of function calling is know as Exessive Function
*/

int fibonacchi(int x) {
    if (x == 0) {
        return 0;
    } else if (x == 1) {
        return 1;
    } else {
        return fibonacchi(x-2) + fibonacchi(x-1);
    }
}


/*
    Using iterative method, we can reduce the time complexty to O(n).
*/
int fib_loop(int x) {
    int term1 = 0, term2 = 1, sum;
    if (x <= 1) {
        return x;
    }

    for (int i = 2; i <= x; ++i) {
        sum = term1 + term2;
        term1 = term2;
        term2 = sum;
    }

    return sum;
}

/*
    Let's reduce the time complexity of the Fibonacchi Series using recursion 
    From O(n^2) {Quadratic Time Complexity} to O(n) {Linear Time Complexity}.
    This method of function calling is known as "Memoization".
*/

int Fib_arr[10];

int fib_memoization(int x) {
    if (x <= 1) {
        Fib_arr[x] = x;
        return x;
    } else {
        if (Fib_arr[x-2] == -1) {
            Fib_arr[x-2] = fib_memoization(x-2);
        }
        if (Fib_arr[x-1] == -1) {
            Fib_arr[x-1] = fib_memoization(x-1);
        }

        Fib_arr[x] = Fib_arr[x-2] + Fib_arr[x-1];
        return Fib_arr[x-2] + Fib_arr[x-1];
    }
}

int main() {

    // cout << fib_loop(6)<< endl;
    int size;
    cout << "Enter The Size Of The Array : ";
    cin >> size;
    for (int i = 0; i < 10; ++i) {
        Fib_arr[i] = -1;
    }

    int x;
    cout << "Enter A Number : ";
    cin >> x;
    int ans = fib_memoization(x);
    cout << "Using Memoization The Fibonacchi Number Of Given x is : " << ans << endl;

    /*
        Printing the fibonachi series 
        like : 0 1 1 2 3 5 . . . so no.
    */

    for (int i = 0; i < 10; ++i) {
        cout << Fib_arr[i] <<", ";
    }
    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;

void fun (int x) {
    if (x > 0) {
        cout << x << ". Hello.\n";
        fun(x-1);   // Here function call itself in the last statement //
    }

    /*
        Expected Output :
            3. Hello.
            2. Hello.
            1. Hello.
    */
}
int main() {
    int x = 3;
    fun(x);
    return 0;
}
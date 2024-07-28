#include <iostream>
using namespace std;

int fun(int x) {
    if (x > 100)
        return x-10;
    else
        return fun(fun(x+12));
}

int main() {

    int x = 12;
    cout << "Nested Recursion Result Is : " << fun(x) << endl;
    return 0;
}
#include <iostream>
using namespace std;

int fun(int x) {
    static int var = 0;    // It will have the only one single copy of variable and it was updated again and again ...
    if (x > 0) {
        var++;  // here the variable was updated //
        return fun(x-1) + var;
    }

    return 0;
}
int main() {

    int x = 5;
    cout << fun(x) << endl;
    return 0;
}
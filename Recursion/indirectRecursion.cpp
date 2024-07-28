#include <iostream>
using namespace std;

// Known as proto type.
void funB(int x);   // function should be defined before use it .

void funA(int x) {
    if (x > 0) {
        cout << x << ", ";
        funB(x-1);
    }
}

void funB(int y) {
    if (y > 0) {
        cout << y << ", ";
        funA(y/2);
    }
}

int main() {
    int x = 20;
    funA(x);
    cout << endl;
    return 0;
}
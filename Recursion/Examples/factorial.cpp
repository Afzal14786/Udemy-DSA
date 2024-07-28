#include <iostream>
using namespace std;

int fact(int x) {
    if (x == 0) {
        return 1;
    } else {
        return fact(x-1) * x;
    }
}

int fact_loop(int x) {
    int fact = 1;
    for (int i = 1; i <= x; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {

    int var = 5;
    int ans = fact_loop(var);
    cout << "The Factorial Is : " << ans << endl;
    return 0;
}
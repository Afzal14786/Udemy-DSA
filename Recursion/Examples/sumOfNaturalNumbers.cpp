#include <iostream>
using namespace std;

// using recursion //
int sum(int x) {
    if (x == 0) {
        return 0;
    } else {
        return sum(x-1) + x;
    }
}

// using loop //
int sum_loop(int x) {
    int sum = 0;
    for (int i = 1; i <= x; i++) {
        sum += i;
    }
    return sum;
}

// using formula //
int sum_formula(int x) {
    return (x*(x+1))/2;
}
int main() {

    int x = 10;
    int ans = sum_formula(x);
    cout << "The Sum is : " << ans << endl;
    return 0;
}
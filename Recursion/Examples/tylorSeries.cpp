#include <iostream>
using namespace std;

// way 1 : 

double tylor_series(int x, int n) {
    double ans = 0;
    static double p = 1, f = 1;

    if (n == 0) {
        return 1;
    } else {
        ans = tylor_series(x, n-1);
        p *= x;
        f *= n;
        return ans + p/f;
    }
}

// Way 2 : (Horner's Rule) 
// Iterative //

double tylor_iter(int x, int n) {
    double ans = 1;
    for (; n > 0; --n) {
        ans = 1 + x*ans/n;
    }
    return ans;
}

// using recursion //

double tylor_recursion(int x, int n) {
    static double ans = 1;
    if (n == 0) {
        return ans;
    }

    ans = 1 + x*ans/n;
    return tylor_recursion(x, n-1);
}


double tylor(int x, int n) {
    double ans = 1;
    double num = 1, den = 1;

    for (int i = 1; i <= n; ++i) {
        num *= x;
        den *= i;
        ans += num/den;
    }

    return ans;
}
int main() {

    double x, n;
    double ans;
    cout << "Enter The Value Of X : ";
    cin >> x;----------------------------------------------------------------
    cout << "Enter The Value Of N : ";
    cin >> n;

    ans = tylor(x, n);
    cout << "Using Tylor Series : (Exponent Value Of x and n means x^n is :) "  << ans << endl;
    return 0;
}
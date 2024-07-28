#include <iostream>
using namespace std;

// Way 1 //

int pow(int m, int n) {

    if (n == 0) {
        return 1;
    } else {
        return pow(m, n-1) * m;
    }
}

// way 2 //

int power(int m, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return power(m*m, n/2);
    } else {
        return m * power(m*m, (n-1)/2);
    }
}

// using loop //
// check it out latter -> Must solve it latter dont forget it .
// int power_loop(int m, int n) {

//     int ans = 1;
//     for (int i = 1; i <= n; ++i) {
//         ans = m*m;
//     }
//     return ans;
// }
int main() {

    int num, power;
    cout << "Enter The Number : ";
    cin >> num;
    cout << "Enter The Power : ";
    cin >> power;

    int ans =  power_loop(num, power);

    cout << "The Final Result Is : " << ans << endl;
    return 0;
}
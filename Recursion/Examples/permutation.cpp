#include <iostream>
using namespace std;
/*
    Permutaion :
        Permutation refers to the arrangement of a set of objects in a specific order. The order of arrangement is essential in permutations. For example, arranging the letters A, B, and C in different orders (ABC, ACB, BAC, BCA, CAB, CBA) results in different permutations.

    Formula:
        The formula for calculating the number of permutations of 𝑛 distinct objects taken 𝑟 at a time is given by:
            P(n,r)= n! / (n−r)! .

    where n! (n factorial) is the product of all positive integers up to n:
    n!=n×(n−1)×(n−2)× . . . ×1

    Example:
        To find the number of ways to arrange 3 out of 5 letters (A, B, C, D, E):
    
        P(5,3)= 5! / (5−3)! = 5×4×3×2×1 / 2×1 = 120 / 2 = 60
        So, there are 60 different ways to arrange 3 out of 5 letters.

*/

int n_fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }

    return fact;
}

int permutation (int n, int r) {
    int _nfact = n_fact(n);
    int _n_r_fact = n_fact(n-r);

    return _nfact / _n_r_fact;
}
int main() {

    cout << permutation(5,3) << endl;
    return 0;
}
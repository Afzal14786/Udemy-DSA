#include <iostream>
#define MAX_ROW 100
#define INDEX 100
using namespace std;

int n_fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }

    return fact;
}

int combination (int n, int r) {
    int fact_n = n_fact(n);
    int fact_r = n_fact(r);
    int fact_n_r = n_fact(n-r);

    return fact_n/(fact_r * fact_n_r);
}


/*
    Pascal's Triangle :
    It's Look Like :
    ----------------------
          1
         1 1
        1 2 1
       1 3 3 1
      1 4 6 4 1
     1 5 10 10 5 1

     formula :

     comination(n,r) = n! / r! * (n-r)!;
*/

/*
    Using recursive we can build the pascal's triangle :
    formula :

    recursive :
    -------------------
    combination(n-1, r-1) + combination(n-1, r);

    because the result "combination(n,r)" is the result of (combination(n-1, r-1) and combination(n-1,r));
*/

int pascal_triangle(int n, int r) {
    /* Base Case */
    if (r == 0 | n == r) {
        return 1;
    } else {
        return pascal_triangle(n-1, r-1) + pascal_triangle(n-1, r);
    }
}

/*Memoization*/

// first declare a 2D array //

int array_combi[MAX_ROW][INDEX];

/*Write the function*/

int combi_memo(int n, int r) {
    if (r == 0 || n == r) {
        array_combi[n][r] = 1;
        return 1;
    } else {
        if (array_combi[n-1][r-1] == -1) {
            array_combi[n-1][r-1] = combi_memo(n-1, r-1);
        }
        if (array_combi[n-1][r] == -1) {
            array_combi[n-1][r] = combi_memo(n-1, r);
        }
        array_combi[n][r] = array_combi[n-1][r-1] + array_combi[n-1][r];
        return array_combi[n-1][r-1] + array_combi[n-1][r];
    }
}

void print_pascals_triangle(int n) {
    for (int i = 0; i <= n; i++) {
        // Print leading spaces for alignment
        for (int j = 0; j <= n - i - 1; j++) {
            cout << " ";
        }

        // Print binomial coefficients
        for (int j = 0; j <= i; j++) {
        
            cout << " "<< combi_memo(i, j);
        }
        
        cout << endl;
    }
}
int main() {
    int row, index;
    /* Taking n value input as Row no*/
    cout << "Enter The No Of Rows For Pascal Triangle : ";
    cin >> row;

    /*Taking r value input as index*/
    cout << "Enter The Index Value To Find Value Inside The Pascle Triangle : ";
    cin >> index;

    for (int i = 0; i <= row; ++i) {
        for (int j = 0; j <= index; ++j) {
            array_combi[i][j] = -1;
        }
    }

    /* Function Calling With Memoization. */
    cout << "Answer Using Memoization Method : "<< combi_memo(row, index) << endl;

    /* Function Calling Without Memoization */
    cout << "Answer Using Recursive Method : "<< pascal_triangle(row, index) << endl;

    /* Printing The Value's Inside The 2D Array*/
    cout << "------------------------------------------------------------\n";
    cout << "Here Is The Pascale Triangle For " << row << " rows.\n";
    cout << "------------------------------------------------------------\n";
    print_pascals_triangle(row);
    
    return 0;
}
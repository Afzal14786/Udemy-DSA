package Recursion.Example;

import java.util.Scanner;

public class Fibonachi {
    static int fib[];
    static int fibo_memoization(int n) {
        // Pending To Solve //
        // This Approach Is Known As Memoization //
        // Best Approach For Fibonachi
        if (n <= 1) {
            fib[n] = n;
            return n;
        } else {
            if (fib[n-2] == -1) {
                fib[n-2] = fibo_memoization(n-2);
            } else if (fib[n - 1] == -1) {
                fib[n-1] = fibo_memoization(n-1);
            }
            fib[n] = fib[n-2] + fib[n-1];
            return fib[n-2] + fib[n-1];
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter The Number : ");
        int x = scn.nextInt();
        // Approach 1 Calling //
//        System.out.println("The Fibonachi Of " + x + " Is : " + fibo(x));
//        System.out.println("The Fibonachi Of " + x + " Is : " + fibo_loop(x));

        fib = new int[10];
        for (int i = 0; i<10; i++) {
            fib[i] = -1;
        }
        int res = fibo_memoization(x);
        System.out.println("The Fibonachi Of " + x + " Is : " + res);
    }


    // Approach 1 //
    private static int fibo(int n) {

        // Time Complexity = O(2^n)   // Too High //
        // -> This Recursive Function Is Known As Excessive Recursion Function //
        if (n <= 1) {
            return n;
        } else {
            return fibo(n-2) + fibo(n-1);
        }
    }

    // Approach 2 Using Loop //
    private static int fibo_loop(int x) {
        int term0 = 0, term1 = 1, result = 0;

        // Time Complexity = O(n) // Better Then Recursive Approach //
        if (x <= 1)
            return x;
        for (int i = 2; i<=x; i++) {
            result = term0 + term1;
            term0 = term1;
            term1 = result;
        }
        return result;
    }
}

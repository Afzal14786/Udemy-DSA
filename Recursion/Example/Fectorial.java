package Recursion.Example;

import java.util.Scanner;

public class Fectorial {

    // Using Recursive Approach //
    private static int factorial1(int x) {
        // base case //

        if (x <= 0 || x == 1) {
            return 1;
        } else {
            return factorial1(x-1)*x;
        }

    }

    // using loop //

    private static int factorial_loop(int x) {
        int fact = 1;

         /*
            Time Complexity : O(n)
            Space Complexity : O(1)
         */

        for (int i = 1; i <= x; i++) {
            fact *= i;
        }
        return fact;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter The Number : ");
        int x = scn.nextInt();

        // Recursion Function Call //
        System.out.println("The Fectorial Of " + x + " Using Recursion : " + factorial1(x));
        System.out.println("The Fectorial Of " + x + " Using Loop : " + factorial_loop(x));

    }
}

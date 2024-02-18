package Recursion.Example;

import java.util.Scanner;

public class SumOf_N {

    // Using recursive approach //
    private static int sum(int n) {

        /*
            Time Complexity : O(n)
            Space Complexity : O(n)
         */

        if (n == 0) {
            return 0;
        }
        return sum(n-1)+n;
    }

    // Without Recursive Function //

    private static int sum2(int x) {
        /*
            Time Complexity : O(1)
            Space Complexity : O(1)
         */
        if (x == 0) {
            return 0;
        }

        return (x * (x+1)) / 2;
    }

    // using iterative approach //

    private static int sum_iterative(int n) {
        int sum = 0;

        for (int i = 0; i <= n; i++) {
            /*
            Time Complexity : O(n)
            Space Complexity : O(1)
         */
            sum += i;
        }
        return sum;
    }
    public static void main(String[] args) {
        // Sum Of n Natural Number's

        Scanner scn = new Scanner(System.in);
        System.out.println("Enter The Value Of The X : ");
        int x = scn.nextInt();

        // Recursive Function Call //

        System.out.println("The Sum Of " + x +" Natural Number's Is : " + sum(x));

//        constant time
        System.out.println("The Sum Of " + x +" Natural Number's Without Recursive Function : " + sum2(x));

        // using iterative approach //
        System.out.println("The Sum Of n Natural Number's Using Loop : " + sum_iterative(x));
    }
}

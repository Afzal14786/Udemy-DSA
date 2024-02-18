package Recursion;

public class Day1 {
    public static void main(String[] args) {
        int x = 5;
        System.out.println( "The Fectorial Of " + x + " Is : " + factorial(x));
        fun(x);
        System.out.println();
        fun2(x);
    }

    private static int factorial(int x) {
        // base case //
        if (x <= 1) {
            return x;
        } else {
            return x * factorial(x-1);
        }
    }

    private static void fun(int a) {
        if (a > 0) {
            fun(a-1);
            System.out.print(a + " ");
        }
    }

    private static void fun2(int a) {
        if (a > 0) {
            System.out.print(a + " ");
            fun2(a-1);
        }
    }
}

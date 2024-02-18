package Recursion.Example;

import java.util.List;

public class CombinationFormula {
    // Function Code For Combination Formula //
    private static int fact(int n) {
        int fact = 1;
        for (int i = 1; i<= n; i++) {
            fact *= i;
        }
        return fact;
    }

    private static int Combination_Formula(int n, int r) {
        int num, deno;
        num = fact(n);
        deno = fact(r) * fact(n-r);

        return num / deno;
    }
    public static void main(String[] args) {
//        System.out.println(Combination_Formula(5,2));
        System.out.println("Pascle Triangle Using Recursion : " + pascle_triangle(5,2));
    }


    // Using Recursion . . . (Pascle's Triangle)
    private static int pascle_triangle(int x, int y) {
        if (y == 0 || x==y) {
            return 1;
        } else {
            return pascle_triangle(x-1,y-1) + pascle_triangle(x-1,y);
        }
    }


}

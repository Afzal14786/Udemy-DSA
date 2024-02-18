package Recursion.Example;

import java.util.Scanner;

public class Power_Factorial {

    private static int square(int num, int power) {
        if (power == 0) {
            return 1;
        } else if (power % 2 == 0) {
            return square(num*num, power/2);
        } else  {
            return num * square(num*num, (power-1)/2);
        }
    }
    

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter The Number : ");
        int x = scn.nextInt();
        System.out.println("Enter The Power : ");
        int power = scn.nextInt();

        // recursion function call //
        System.out.println("The Result Using Recursion Approach 1 : " + power_recursion1(x, power));
        System.out.println("The Result Using Recursion Approach 2 : " + power_recursion2(x, power));
    }

    private static int power_recursion2(int x, int power) {
        if (power == 0) {
            return 1;
        } else {
            return power_recursion2(x, power-1) * x;
        }
    }

    private static int power_recursion1(int x, int power) {
        if (power == 0) {
            return 1;
        } else if (power % 2 == 0) {
            return power_recursion1(x*x, power/2);
        } else {
            return x * power_recursion1(x*x, (power-1)/2);
        }
    }
}

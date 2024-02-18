package Array_ADTs;

import java.util.Scanner;

public class OperationsArray {

    private static int[] print(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] +" ");
        }
        System.out.println();
        return arr;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
//        int[] array = {1,2,3,4,5,6,7,8};

        int[] arr = new int[10];
        System.out.println("Enter The Elements Of The Array : ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        System.out.println();
//        print(array);
//        int row = 5;
//        int ar[] = new int[row];
//        for (int x : ar) {
//            System.out.print(x + " ");
//        }
//        System.out.println("Length Of The Array Is : " + ar.length);


        // Get Function //

//        System.out.println(GET(array, 3));

        // Set Function //

        print(arr);
        System.out.println("At A Particular Index : " + GET(arr, 5));
//        SET(arr, 0, 100);
//        print(arr);
        System.out.println("The Sum : " + SUM(arr));
        System.out.println("The Max Value : " + max(arr));
        System.out.println("The Average Of The Array Is : " + average(arr, arr.length-1));


    }

    // GET Function /

    private static int GET(int[] arr, int idx) {
        if (idx >= 0 && idx < arr.length) {
            return arr[idx];
        }
        return -1;
    }

    private static void SET(int[] arr, int idx, int set) {
        if (idx >= 0 && idx < arr.length) {
            arr[idx] = set;
        }
    }

    // SUM //
    private static int SUM(int[] arr) {
        int total = 0;

        for (int i = 0; i < arr.length; i++) {
            total += arr[i];
        }
        return total;
    }

    // Recursive Sum //
//    private static int sum(int[] arr, int n) {
//        if (n < 0) {
//            return 0;
//        } else {
//
//            return sum(arr, n-1) + arr[n];
//        }
//    }

    // Average Function //

    private static float average(int[] arr, int n) {
        int total = 0;
        for (int i = 0; i < arr.length; i++) {
            total += arr[i];
        }
        return (float) total / arr.length;
    }

    // Max Value //
    static int max(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
}

package Array_ADTs;

import java.util.Scanner;

public class LinearSearch {

    static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] +" ");
        }
    }

    private static int lSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (target == arr[i]) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int size, key;
//        Scanner scn = new Scanner(System.in);
//        System.out.println("Enter The Size Of The Array : ");
//        size = scn.nextInt();
//        int[] arr = new int[size];
//        System.out.println("Enter The Elements Of The Array : ");
//        for (int i = 0; i < arr.length; i++) {
//            arr[i] = scn.nextInt();
//        }
//
//        System.out.println("The Array Before Implement The Searching : ");
//        printArray(arr);
//
//        System.out.println();
//        System.out.println("Enter The Target Element : ");
//        key = scn.nextInt();

//        int ans = improve_lSearch(arr, key);
//        if (ans == -1) {
//            System.out.println("The Target Element Doesn't Exist In The Array : ");
//        } else {
//            System.out.println("The Target Element Found At Index : " + ans);
//        }

        // Display The Array After Finding The Element //
        int[] array = {1,2,3,4,5};
        System.out.println(improve_lSearch(array, 4));  // function calling
        printArray(array);
    }

    // Implement Method Of The Linear Search //

    static void swap(int x, int y) {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
    private static int improve_lSearch(int[] array, int target) {

        int store;
        for (int i = 0; i < array.length; i++) {
            if (target == array[i]) {
                swap(target, array[0]);
                return i;
            }
        }
        return -1;
    }
}

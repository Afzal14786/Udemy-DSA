package Array_ADTs.Examples;

import java.util.ArrayList;

public class Shorting {
    public static void main(String[] args) {
        int[] arr = new int[10];

        arr[0] = -9;
        arr[1] = 2;
        arr[2] = -3;
        arr[3] = 5;
        arr[4] = 6;
        arr[5] = -8;
        arr[6] = 8;
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] +" ");
        }
        System.out.println();

//        System.out.println(isSorted(arr));

        reArange(arr);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] +" ");
        }
        System.out.println();

    }

//    static void insert(int[] arr, int value) {
//        int lastIdx = arr.length-1;
////        if (arr.length == arr.)
//
//        while (lastIdx >= 0 && arr[lastIdx] > value) {
//            arr[lastIdx+1] = arr[lastIdx];
//            lastIdx--;
//        }
//        arr[lastIdx+1] = value;
//        lastIdx++;
//    }

    static boolean isSorted(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }

    static void reArange(int[] array) {
        int i = 0, j = array.length-1;

        while (i < j) {

            while (array[i] < 0) {
                i++;
            }
            while (array[j] >= 0) {
                j--;
            }

            if (i < j) {
                // swap //
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
            }
        }
    }

}

package Array_ADTs.Examples;

import java.util.Arrays;

public class MeargeSortedArray {

    static void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {

        int[] a = {1,3,5,7,9};
        int[] b = {2,4,6,8,10};

//        System.out.println(Arrays.toString(Mearge(a,b)));
        int[] merge = Mearge(a, b);
        printArr(merge);

    }

    static int[] Mearge(int[] arr1, int[] arr2) {
        int[] arr3 = new int[15];
        int M = arr1.length, N = arr2.length;
        int i = 0, j = 0, k = 0;
        while (i < M && j < N) {

            // comparision
            if (arr1[i] < arr2[j]) {
                arr3[k++] = arr1[i++];
            } else {
                arr3[k++] = arr2[j++];
            }
        }

        for (; i < M; i++) {
            arr3[k] = arr1[i];
        }

        for (; j < N; j++) {
            arr3[k] = arr2[j];
        }
        return arr3;
    }

}

package Array_ADTs.MenuProgram;

import java.util.Arrays;
import java.util.Scanner;
/*
            Write A Program Which Perform All The Things Like
            1. Insertion In Last
            2. Insertion at particular index;
            3. Append an element And Insert in The Last (Both Are Same)
            4. Delete An Element
            5. Binary Search ( Using Recursion also)
            6. Linear Search
            7. IsSorted
            8. Reverse
            9. Arrange All The -ve Values On The Left Side Of The Array
            10. Merge Two Array
            11. Union Of An Array
            12. Intersection In A Sorted Array
            13. Difference In A Sorted Array
*/


class Array {

    private int length, size;
    private int[] array;
    public Array() {
        size = 10;
        length = 0;
        array = new int[size];
    }

    public Array(int size) {
        this.size = size;
        length = 0;
        array = new int[size];
    }



    // add and append both are same
        int[] add(int value) {
        int len = array.length;
        int[] newAr = new int[len+1];
        int i;
        for (i = 0; i < len; i++) {
            newAr[i] = array[i];
        }
        newAr[i] = value;
        len++;
        return newAr;
    }


    // insert at a particular index //
    int[] insert(int idx, int value) {

//        int len = array.length+1;
//        int[] newArray = new int[len];
//
//        for (int i = 0; i < len; i++) {
//            if (i < idx) {
//                newArray[i] = array[i];
//            } else if (i == idx) {
//                newArray[idx] = value;
//            } else {
//                newArray[i] = array[i-1];
//            }
//        }
//        return newArray;

        // approach 2 //

        int length = array.length-1;
        if (idx >= 0 && idx <= length) {
            for (int i = length; i > idx; i--) {
                array[i] = array[i-1];
            }
            array[idx] = value;
            length++;

        } else {
            System.out.println("Please Provide A Valid Index : ");
        }

        return array;
    }

     int delete(int idx) {
        int size = array.length;

        int deletedElem = 0;

        if (idx >= 0 && idx <= size) {
            deletedElem = array[idx];
            for (int i = idx; i < array.length-1; i++) {
                array[i] = array[i+1];
            }
            size--;
            return deletedElem;
        }
        return 0;
    }

    // set value //
    void setValue(int idx, int value) {
        if (idx >= 0 && idx <= array.length) {
            array[idx] = value;
        }
    }


    // get value
    int GET(int[] arr, int idx) {
        if (idx >= 0 && idx < array.length) {
            return array[idx];
        }
        return -1;
    }

    // Bineary Search Using Recursion And Without Recursion //
    int binearSearch(int target) {

        int start = 0, end = array.length-1;

        while (start <= end) {
            int mid = start + (end - start)/2;
            if (array[mid] == target) {
                return mid;
            } else if (array[mid] > target) {
                end = mid -1;
            } else {
                start = mid + 1;
            }

        }

        return 0;
    }

    int Rbinarysearch(int[] array, int start, int end, int target) {

        end = array.length-1;

        while (start <= end) {
            int mid = start + (end - start)/2;

            if (array[mid] == target) {
                return mid;
            } else if (array[mid] > target) {
                return Rbinarysearch(array, start, mid-1, target);
            } else {
                return Rbinarysearch(array, mid + 1, end, target);
            }
        }
        return 0;
    }

    // Linear Search //

    int linearSearch(int target) {

        for (int i = 0; i < array.length-1; i++) {
            if (array[i] == target) {
                return i;
            }
        }
        return 0;
    }

    // seap two elem //
    static void swap(int x, int y) {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }

    int improve_lSearch(int target) {

        for (int i = 0; i < array.length; i++) {
            if (target == array[i]) {
                swap(target, array[0]);
                return i;
            }
        }
        return 0;
    }


    // max //
    int max() {
        int max = array[0];

        for (int i = 1; i < array.length-1; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }

    int min() {
        int min = array[0];

        for (int i = 0; i < array.length; i++) {
            if (array[i] < min) {
                min = array[i];
            }
        }
        return min;
    }

    // sum //
    int sum() {
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        return sum;
    }

    float average() {
        int sum = 0;

        for (int i = 0; i < array.length-1; i++) {
            sum += array[i];
        }
        float avg = (float) sum/ array.length;
        return avg;
    }

    boolean isSorted() {

        for (int i = 0; i < array.length-1; i++) {
            if (array[i] < array[i+1]) {
                return false;
            }
        }
        return true;
    }


    // Rearranege All the negative number one side of the array //
    void reArange() {
        int i = 0, j = array.length-1;

        while (i < j) {

            while (array[i] < 0) {
                i++;
            }
            while (array[j] >= 0) {
                j--;
            }

            if (i < j) {
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
            }
        }
    }

    // Reverse The Array //
    // way 1//

    int[] reverseArray() {
        int[] newArray = new int[array.length+1];

        for (int i = array.length-1, j = 0; i >= 0; i--, j++) {
            newArray[j] = array[i];
        }

        for (int i = 0; i < newArray.length-1; i++) {
            array[i] = newArray[i];
        }

        return array;
    }

    int[] reverseArray2() {
        for (int i = 0, j = array.length-1; i < j; i++, j--) {
            array[i] = array[i] ^ array[j];
            array[j] = array[i] ^ array[j];
            array[i] = array[i] ^ array[j];
        }

        return array;
    }

    // Merge two sorted array //

    int[] merge(int[] array2) {
        int i = 0, j = 0, k = 0;
        int m = array.length;
        int n = array2.length;
        int[] merge = new int[length + array2.length];

        while (i < m && j < n) {
            if (array[i] < array2[j]) {
                merge[k++] = array[i++];
            } else {
                merge[k++] = array2[j++];
            }
        }

        for (; i < m; i++) {
            merge[k] = array[i];
        }

        for (; j < n; j++) {
            merge[k] = array2[j];
        }

        return merge;
    }


    // Set Operations In Sorted Array //

    /*
        .. Intersection
        .. Difference
        .. Union
     */

    int[] union(int[] array2) {

        int[] result = new int[length + array2.length];

        int i = 0, j = 0, k = 0;
        int M = array.length;
        int N = array2.length;

        while (i < M && i < N) {

            if (array[i] == array2[j]) {
                result[k] = array[i++];
                j++;
            } else if (array[i] < array2[j]) {
                result[k++] = array[i++];
            } else  {
                result[k++] = array2[k++];
            }
        }

        for (; i < M; i++) {
            result[k] = array[i];
        }

        for (; j < N; j++) {
            result[k] = array2[j];
        }

        return result;
    }


    // Intersection //

    int[] Intersection(int[] arr1) {
        int M = array.length, N = arr1.length;
        int size = M + N;
        int[] result = new int[length + arr1.length];

        int i = 0, j = 0, k = 0;

        while (i < M && j < N) {

            if (array[i] == arr1[j]) {
                result[k++] = array[i++];
                j++;
            } else if (array[i] < array[j]) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }

    // Difference // Take All the Uniqe Elements of two sorted array //

    int[] difference(int[] arr1) {
        int M = array.length, N = array.length;
        int size = M + N;
        int i = 0, j = 0, k = 0;

        int[] diffRes = new int[size];

        while (i < M && j < N) {

            if (array[i] < arr1[j]) {
                diffRes[k++] = array[i++];
            } else if (array[i] == arr1[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        for (; i < M; i++) {
            diffRes[k] = array[i];
        }

        return array;
    }

    void Display() {
        for (int i = 0; i < size; i++) {
            System.out.print(array[i] +" ");
        }
        System.out.println();
    }
}



public class DriveMenuProgram {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter The Size Of The Array : ");
        int size = scn.nextInt();
        Array ar = new Array(size);


        boolean flag = false;

        while (!flag) {
            System.out.println("1. Insert Element .");
            System.out.println("2. Delete An Element .");
            System.out.println("3. Linear Search .");
            System.out.println("4. Sum Of All Elements Inside The Array .");
            System.out.println("5. Average Of The Array .");
            System.out.println("6. Maximum Inside The Array .");
            System.out.println("7. Minimum Inside The Array .");
            System.out.println("8. Exit");

            System.out.println("------------------------------------------------------------");

            System.out.print("Enter Your Choise : ");
            int choise = scn.nextInt();
            System.out.println("------------------------------------------------------------");

            switch (choise) {
                case 1 :
                    System.out.println("Enter The Index And The Value : ");
                    int idx = scn.nextInt();
                    int value = scn.nextInt();
                    ar.insert(idx, value);
                    ar.Display();
                    break;

                case 2 :
                    System.out.println("Enter The Index Value Which You Want To Delete .");
                    int delIdx = scn.nextInt();
                    int del = ar.delete(delIdx);
                    if (del < 0) {
                        System.out.println("The Element Is Not Deleted");
                    } else {
                        System.out.println("The Element Is Successfully Deleted .");
                    }
                    ar.Display();
                    break;

                case 3 :
                    System.out.println("Enter The Target Element ");
                    int target = scn.nextInt();
                    int res = ar.linearSearch(target);
                    if (res < 0) {
                        System.out.println("The Target Element Not Found Inside the array ");
                    } else {
                        System.out.println("The Target Element Found At Index : " + res);
                    }
                    ar.Display();
                    break;

                case 4 :
                    int sum = ar.sum();
                    System.out.println("sum Of The Array Elements Is : " + sum);
                    break;

                case 5 :
                    float avg = ar.average();
                    System.out.println("The Average Of The Array Is : " + avg);
                    break;

                case 6 :
                    int max = ar.max();
                    System.out.println("The Maximum Element Inside The Array is : " + max);
                    ar.Display();
                    break;

                case 7 :
                    int min = ar.min();
                    System.out.println("The Minimum Element Inside The Array Is : " + min);
                    ar.Display();
                    break;

                default :
                    flag = true;
                    break;
            }
        }


    }
}
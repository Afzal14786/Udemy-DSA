package Array_ADTs.Examples;

public class ReverseArray {
    public static void main(String[] args) {
        // Reverse An Array In 2 Ways //

        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        int[] arr2 = new int[arr.length];

        System.out.println("Before Reversing The Array : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] +" ");
        }
        System.out.println();

        // way 1
//        reverseArr(arr);

        // Way 2 //
        reverseArrayWay2(arr);
        System.out.println("After Reversing The Array : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }



    }

    // Way 1 To Reverse An Array //
    private static int[] reverseArr(int[] arr) {
        int[] arr2 = new int[arr.length];
        for (int i = arr.length-1, j = 0; i >= 0; i--, j++) {
            arr2[j] = arr[i];
        }

        for (int i = 0; i < arr2.length; i++) {
            arr[i] = arr2[i];
        }
        return arr;
    }

    // The Way 2 For Reverse An Array ://
    private static int[] reverseArrayWay2(int[] arr) {
        for (int i = 0, j = arr.length-1; i < j; i++, j--) {

            // Swap The Elements Using XOR (^)//
            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
        }
        return arr;
    }

}

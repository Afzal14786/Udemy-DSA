package Array_ADTs.SetOperations;

public class Intersection {

    /*
            Intersection

            -> Return ALl The Duplicates Elements In The Resulted Array .
     */

    public static void main(String[] args) {
        int[] arr1 = {1,3,5,7,9};
        int[] arr2 = {3,5,6,7,8,9};

        int[] ans =  intersection(arr1, arr2);
        for (int i = 0; i < ans.length-1; i++) {
            System.out.print(ans[i] +" ");
        }
    }

    static int[] intersection(int[] arr1, int[] arr2) {
        int m = arr1.length, n = arr2.length;
        int[] resultArray = new int[20];
        int i = 0, j =0, k = 0;

        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr2[j] < arr1[i]) {
                j++;
            } else {
                resultArray[k++] = arr1[i];
                j++;
            }
        }

        return resultArray;
    }



}
